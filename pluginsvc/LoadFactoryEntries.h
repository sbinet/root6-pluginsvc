#ifndef GAUDIKERNEL_LOADFACTORYENTRIES_H
#define GAUDIKERNEL_LOADFACTORYENTRIES_H 1

#define GAUDI_EXPORT __attribute__((visibility("default")))

#define LOAD_FACTORY_ENTRIES(x)                             \
  extern "C" GAUDI_EXPORT void* x##_getFactoryEntries() {   \
    return 0;                                               \
  }

#endif
