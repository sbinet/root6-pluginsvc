#include "pluginsvc/DeclareFactoryEntries.h"
#include "pluginsvc/Class1.h"
#include "pluginsvc/Class2.h"

DECLARE_ALGORITHM_FACTORY(Class1)
DECLARE_ALGORITHM_FACTORY(Class2)

DECLARE_ALGORITHM_FACTORY_WITH_ID(Class1, "1")
DECLARE_ALGORITHM_FACTORY_WITH_ID(Class2, "2")

DECLARE_FACTORY_ENTRIES(MyComp) {
    DECLARE_ALGORITHM(Class1)
    DECLARE_ALGORITHM(Class2)
}
