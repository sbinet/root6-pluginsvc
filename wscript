# -*- python -*-
# automatically generated wscript

import waflib.Logs as msg

PACKAGE = {
    'name': 'pluginsvc',
    'author': ["Sebastien Binet"], 
}

def pkg_deps(ctx):
    ctx.use_pkg('pkg-settings')
    return

def configure(ctx):
    msg.debug('[configure] package name: '+PACKAGE['name'])
    ctx.load('find_posixlibs')
    ctx.find_posixlibs()
    return

def build(ctx):
    ctx.build_linklib(
        name = "pluginsvc",
        source = "src/PluginService.cpp",
        includes = ["pluginsvc"],
        defines= ["NDEBUG=1"],
        export_includes = ["pluginsvc"],
        )

    ctx.build_app(
        name = "gaudi-listcomps",
        source = "src/listcomponents.cpp",
        defines= ["NDEBUG=1"],
        use    = ["pluginsvc", "dl"],
        )
    
    ctx.build_linklib(
        name = "MyCompLib",
        source = "src/Class1.cxx src/Class2.cxx",
        use = ["pluginsvc",],
        )

    ctx.build_linklib(
        features = "gen_complist",
        name = "MyComp",
        source = "src/components/*.cxx",
        use = ["pluginsvc", "MyCompLib"],
        )

    ctx.env['GENCOMPLIST'] = 'gaudi-listcomps.exe'

    ctx.build_app(
        name = "test-loading",
        source = "src/test-loading.cpp",
        use = ["pluginsvc"],
        )
    return


### ---------------------------------------------------------------------------
import waflib.Task
from waflib.TaskGen import feature, before_method, after_method, extension, after


@extension('.so')
@feature('gen_complist')
@after('symlink_tsk')
def schedule_gen_complist(self, node=None):
    lnk_task = getattr(self, 'link_task', None)
    if not lnk_task:
        return
    for n in lnk_task.outputs:
        gen_complist_hook(self, n)
    pass

@after('symlink_tsk')
def gen_complist_hook(self, node):
    "Bind the .so file extension to the creation of a gen_complist task"
    dso = node.name
    bld_node = node.get_bld().parent
    dso_ext = self.bld.dso_ext()
    out_node = bld_node.make_node(dso.replace(dso_ext,".components"))
    tsk = self.create_task('gen_complist', node, out_node)
    self.source += tsk.outputs
    #merge_dsomap_hook(self, out_node).set_run_after(tsk)
    self.bld.install_files(
        '${INSTALL_AREA}/lib',
        out_node,
        postpone=False,
        )
    
class gen_complist(waflib.Task.Task):
    vars = ['GENCOMPLIST', 'DEFINES', 'CPPFLAGS', 'INCLUDES']
    color= 'BLUE'
    run_str = '${GENCOMPLIST} ${SRC[0].name}'
    ext_in  = ['.so', '.dylib', '.dll', '.bin']
    ext_out = ['.components']
    shell = False
    reentrant = True
    after = ['cxxshlib', 'cxxprogram', 'symlink_tsk']

    def exec_command(self, cmd, **kw):
        cwd_node = self.outputs[0].parent
        #out = self.outputs[0].change_ext('.gencomplist.log')
        out = self.outputs[0]
        fout_node = cwd_node.find_or_declare(out.name)
        fout = open(fout_node.abspath(), 'w')
        kw['stdout'] = fout
        kw['stderr'] = fout
        kw['env'] = self.generator.bld._get_env_for_subproc()
        kw['cwd'] = self.inputs[0].get_bld().parent.abspath()
        rc = waflib.Task.Task.exec_command(self, cmd, **kw)
        if rc != 0:
            msg.error("** error running [%s]" % ' '.join(cmd))
            msg.error(fout_node.read())
        return rc

    def runnable_status(self):
        status = waflib.Task.Task.runnable_status(self)
        if status == waflib.Task.ASK_LATER:
            return status
        
        for out_node in self.outputs:
            try:
                os.stat(out_node.abspath())
            except:
                return waflib.Task.RUN_ME
        return status
    pass
