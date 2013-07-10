#include "Riostream.h"
#include "TH1F.h"

#include "PluginFactory.h"
#include "Interfaces.h"

class Class1: public MyInterface {
public:
  Class1(const std::string &name, ISvcLocator *svc): m_name(name), m_svc(svc) {}
   virtual ~Class1() {}

   virtual void theMethod() const {
      std::cout << "I'm Class1 instance called " << m_name << std::endl;
   }

private:
   std::string m_name;
  ISvcLocator *m_svc;
};

class Class2: public MyInterface {
public:
  Class2(const std::string &name, ISvcLocator *svc): m_name(name), m_svc(svc) {}

  virtual ~Class2() {}

  virtual void theMethod() const {
    std::cout << "I'm Class2 instance called " << m_name << std::endl;
  }

private:
  std::string m_name;
  ISvcLocator *m_svc;
};

_PLUGINSVC_FACTORY2(Class1, MyInterface*, std::string, ISvcLocator*);
_PLUGINSVC_FACTORY2(Class2, MyInterface*, std::string, ISvcLocator*);

_PLUGINSVC_FACTORY_WITH_ID2(Class1, 1, MyInterface*, std::string, ISvcLocator*);
_PLUGINSVC_FACTORY_WITH_ID2(Class2, 2, MyInterface*, std::string, ISvcLocator*);

//_PLUGINSVC_FACTORY5(TH1F, TH1*, const char*, const char*, Int_t, Double_t, Double_t);

