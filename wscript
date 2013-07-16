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
        name = "MyComp",
        source = "src/components/*.cxx",
        use = ["pluginsvc", "MyCompLib"],
        )


    ctx(
        rule = "gaudi-listcomps.exe ${SRC[0].name} > ${TGT}",
        source = "libMyComp.so",
        target = "test.components",
        install_path = "${INSTALL_AREA}/lib",
        use = ["MyComp", "gaudi-listcomps"],
        )

    ctx.build_app(
        name = "test-loading",
        source = "src/test-loading.cpp",
        use = ["pluginsvc"],
        )
    return
