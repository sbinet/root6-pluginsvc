#ifndef PLUGINSVC_CLASS2_H
#define PLUGINSVC_CLASS2_H 1

#include <string>
#include "pluginsvc/Interfaces.h"

class Class2: public MyInterface {
public:
  Class2(const std::string &name, ISvcLocator *svc);
  virtual ~Class2();

  virtual void theMethod() const;

private:
  std::string m_name;
  ISvcLocator *m_svc;
};

#endif
