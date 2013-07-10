#ifndef GAUDIKERNEL_DECLAREFACTORYENTRIES_H
#define GAUDIKERNEL_DECLAREFACTORYENTRIES_H 1

#include "pluginsvc/Interfaces.h"
#include "pluginsvc/PluginFactory.h"

#define DECLARE_FACTORY_ENTRIES(x)              \
  void x##_load();                              \
                                                \
  extern "C" void x##_loadRef() {               \
    x##_load();                                 \
  }                                             \
                                                \
  void x##_load()


#define DECLARE_ALGORITHM_FACTORY(x)          _PLUGINSVC_FACTORY2(x, MyInterface*, std::string, ISvcLocator*)
#define DECLARE_NAMED_ALGORITHM_FACTORY(x,n)  _PLUGINSVC_FACTORY_WITH_ID2(x, 1, MyInterface*, std::string, ISvcLocator*)

#define DECLARE_ALGORITHM(x)  /*dummy*/


#endif
