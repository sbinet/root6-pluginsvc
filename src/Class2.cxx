#include <iostream>
#include "pluginsvc/Class2.h"

Class2::Class2(const std::string& name, ISvcLocator* svc) :
  m_name(name),
  m_svc(svc)
{}

Class2::~Class2()
{}

void
Class2::theMethod() const
{
  std::cout << "I'm Class2 instance called " << m_name << std::endl;
}
