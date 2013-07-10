#ifndef PLUGINSVC_CLASS1_H
#define PLUGINSVC_CLASS1_H 1

#include <string>
#include "pluginsvc/Interfaces.h"

class Class1: public MyInterface {
public:
  Class1(const std::string &name, ISvcLocator *svc);
  virtual ~Class1();

  virtual void theMethod() const;

private:
  std::string m_name;
  ISvcLocator *m_svc;
};

#endif
