#include "TROOT.h"
#include "TClass.h"
#include "Riostream.h"

#include "Interfaces.h"

#define PLUGINSVC_FACTORY_NS "__pf__"

class Class1: public MyInterface {
public:
  Class1(const std::string &name, ISvcLocator* svc) : 
    m_name(name), 
    m_svc(svc) 
  {}
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
  Class2(const std::string &name, ISvcLocator* svc) : 
    m_name(name), 
    m_svc(svc) 
  {}
   virtual ~Class2() {}

   virtual void theMethod() const {
      std::cout << "I'm Class2 instance called " << m_name << std::endl;
   }

private:
   std::string m_name;
  ISvcLocator *m_svc;
};

class SvcLocator : public ISvcLocator {
public:
  virtual void IsSvcLocator() const {
    return;
  }
};

std::string FactoryName(const std::string& name)
{
   // Create a factory name out of the parameter given.
   static std::string chars(":<> *&, ");
   std::string::size_type pos1 = name.find_first_not_of(' ');
   std::string::size_type pos2 = name.find_last_not_of(' ');
   std::string res = name.substr(pos1 == std::string::npos ? 0 : pos1,
                            pos2 == std::string::npos ? name.length() - 1 : pos2 - pos1 + 1);

   for (std::string::iterator i = res.begin(); i != res.end(); i++) {
      if (chars.find(*i) != std::string::npos) {
         *i = '_';
      }
   }
   return res;
}

#define PLUGINSVC_CNAME(name, serial) name ## _dict ## serial
#define PLUGINSVC_FACTORY(type, signature) _PLUGINSVC_FACTORY(type, signature, __LINE__)

#define _PLUGINSVC_FACTORY(type, signature, serial) \
   namespace { \
   struct PLUGINSVC_CNAME (type, serial) { \
      PLUGINSVC_CNAME(type, serial) () { \
         TClass *cl = TClass::GetClass(typeid( type )); \
         std::string name = cl ? cl->GetName() : #type; \
         std::string sig = std::string(#signature); \
         std::string fname = (std::string(PLUGINSVC_FACTORY_NS "::") + FactoryName(name)); \
         if (gDebug > 0) \
            std::cout << "name: " << name << " sig: " << sig << " fname: " << fname << std::endl; \
      } \
   }; \
   PLUGINSVC_CNAME(type, serial) PLUGINSVC_CNAME(s_ ## type, serial); \
   }

PLUGINSVC_FACTORY(Class1, MyInterface*(std::string, ISvcLocator*));
PLUGINSVC_FACTORY(Class2, MyInterface*(std::string, ISvcLocator*));

