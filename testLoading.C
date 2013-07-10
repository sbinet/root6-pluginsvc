#include "TROOT.h"
#include "Riostream.h"
#include "TH1.h"
#include <memory>

#include "PluginFactory.h"
#include "Interfaces.h"

void call(MyInterface *p) {
   std::cout << std::showbase << std::hex << std::nouppercase << (unsigned long)p << std::endl;
   if (p) p->theMethod();
}

void testLoading()
{
   std::auto_ptr<MyInterface> c1a( CALL1(MyInterface*, Class1, std::string("c1a")) );
   std::auto_ptr<MyInterface> c2a( CALL1(MyInterface*, Class2, std::string("c2a")) );
   call(c1a.get());
   call(c2a.get());

   std::auto_ptr<MyInterface> c1b( CALL1(MyInterface*, 1, std::string("c1b")) );
   std::auto_ptr<MyInterface> c2b( CALL1(MyInterface*, 2, std::string("c2b")) );
   call(c1b.get());
   call(c2b.get());

   // example with the TH1F class
   //std::auto_ptr<TH1> h1( CALL5(TH1*, TH1F, (const char*)"h1", (const char*)"example title", 100, 0.0, 0.0) );
   //h1.get()->Print();
}
