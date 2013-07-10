#include <iostream>
#include "pluginsvc/Class1.h"

Class1::Class1(const std::string& name, ISvcLocator* svc) :
  m_name(name),
  m_svc(svc)
{}

Class1::~Class1()
{}

void
Class1::theMethod() const
{
  std::cout << "I'm Class1 instance called " << m_name << std::endl;
}
