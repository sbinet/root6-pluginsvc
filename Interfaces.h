#ifndef _INTERFACES_H_
#define _INTERFACES_H_

class MyInterface {
public:
   MyInterface() {}
   virtual ~MyInterface() {}

   virtual void theMethod() const = 0;
};

class ISvcLocator {
 public:
  ISvcLocator() {}
  virtual ~ISvcLocator() {}
};

#endif
