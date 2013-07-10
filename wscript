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
    ctx.load('find_root')
    return

def build(ctx):
    ctx.build_linklib(
        name = "pluginsvc",
        source = "src/PluginSvc.cxx",
        )

    ctx.build_linklib(
        name = "MyCompLib",
        source = "src/Class1.cxx src/Class2.cxx",
        use = ["pluginsvc",],
        )

    ctx.build_linklib(
        name = "MyComp",
        source = "src/components/*.cxx",
        use = ["pluginsvc", "MyCompLib", "ROOT"],
        )
    return
