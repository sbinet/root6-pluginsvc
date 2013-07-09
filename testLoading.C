#include "TROOT.h"
#include "TClass.h"
#include "TString.h"
#include "Riostream.h"
#include "TH1.h"
#include <memory>

#include "Interfaces.h"

#define CALL1(A, ArgType1, ArgVal1) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s))",#A, #ArgType1, #ArgVal1))

#define CALL2(A, ArgType1, ArgVal1, ArgType2, ArgVal2) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2))
   
#define CALL3(A, ArgType1, ArgVal1, ArgType2, ArgVal2, ArgType3, ArgVal3) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2, #ArgType3, #ArgVal3))

#define CALL4(A, ArgType1, ArgVal1, ArgType2, ArgVal2, ArgType3, ArgVal3, ArgType4, ArgVal4) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s), %s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2, #ArgType3, #ArgVal3, #ArgType4, #ArgVal4))

#define CALL5(A, ArgType1, ArgVal1, ArgType2, ArgVal2, ArgType3, ArgVal3, ArgType4, ArgVal4, ArgType5, ArgVal5) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s), %s(%s), %s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2, #ArgType3, #ArgVal3, #ArgType4, #ArgVal4, #ArgType5, #ArgVal5))

#define CALL6(A, ArgType1, ArgVal1, ArgType2, ArgVal2, ArgType3, ArgVal3, ArgType4, ArgVal4, ArgType5, ArgVal5, ArgType6, ArgVal6) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s), %s(%s), %s(%s), %s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2, #ArgType3, #ArgVal3, #ArgType4, #ArgVal4, #ArgType5, #ArgVal5, #ArgType6, #ArgVal6))

#define CALL7(A, ArgType1, ArgVal1, ArgType2, ArgVal2, ArgType3, ArgVal3, ArgType4, ArgVal4, ArgType5, ArgVal5, ArgType6, ArgVal6, ArgType7, ArgVal7) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s), %s(%s), %s(%s), %s(%s), %s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2, #ArgType3, #ArgVal3, #ArgType4, #ArgVal4, #ArgType5, #ArgVal5, #ArgType6, #ArgVal6, #ArgType7, #ArgVal7))

#define CALL8(A, ArgType1, ArgVal1, ArgType2, ArgVal2, ArgType3, ArgVal3, ArgType4, ArgVal4, ArgType5, ArgVal5, ArgType6, ArgVal6, ArgType7, ArgVal7, ArgType8, ArgVal8) \
   gROOT->ProcessLine(TString::Format("new %s(%s(%s), %s(%s), %s(%s), %s(%s), %s(%s), %s(%s), %s(%s), %s(%s))",#A, #ArgType1, #ArgVal1, #ArgType2, #ArgVal2, #ArgType3, #ArgVal3, #ArgType4, #ArgVal4, #ArgType5, #ArgVal5, #ArgType6, #ArgVal6, #ArgType7, #ArgVal7, #ArgType8, #ArgVal8))


void call(MyInterface *p) {
   std::cout << std::showbase << std::hex << std::nouppercase << (unsigned long)p << std::endl;
   if (p) p->theMethod();
}

void testLoading()
{
   std::auto_ptr<MyInterface> c1a( (MyInterface*)CALL1(Class1, std::string, "c1a") );
   std::auto_ptr<MyInterface> c2a( (MyInterface*)CALL1(Class2, std::string, "c2a") );
   call(c1a.get());
   call(c2a.get());

   // example with the TH1F class
   //std::auto_ptr<TH1> h1( (TH1*)CALL5(TH1F, (const char*), "h1", (const char*), "example title", Int_t, 100, Double_t, 0.0, Double_t, 0.0) );
   //h1.get()->Print();
}
