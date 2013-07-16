#ifndef GAUDIKERNEL_DECLAREFACTORYENTRIES_H
#define GAUDIKERNEL_DECLAREFACTORYENTRIES_H 1

#include "pluginsvc/Interfaces.h"
#include "Gaudi/PluginService.h"

#define DECLARE_FACTORY_ENTRIES(x)              \
  void x##_load();                              \
                                                \
  extern "C" void x##_loadRef() {               \
    x##_load();                                 \
  }                                             \
                                                \
  void x##_load()


typedef Gaudi::PluginService::Factory2<
  MyInterface*, 
  const std::string&, ISvcLocator*
  >
AlgFactory_t;

#define DECLARE_ALGORITHM_FACTORY(x)          \
  DECLARE_FACTORY(x, AlgFactory_t)

#define DECLARE_ALGORITHM_FACTORY_WITH_ID(x, id)   \
  DECLARE_FACTORY_WITH_ID(x, id, AlgFactory_t)

#define DECLARE_NAMED_ALGORITHM_FACTORY(x,n)  \
  DECLARE_FACTORY_WITH_ID(x, n, AlgFactory_t)

#define DECLARE_ALGORITHM(x)  /*dummy*/


#endif
