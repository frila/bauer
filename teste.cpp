#include <iostream>
using namespace std;

class C1
{
public:
  C1();
  ~C1();

  template<class T>
  virtual void junda(T a);
};

C1::C1(){}
C1::~C1(){}

void C1::junda(string a)
{
  cout << a << endl;
}


class C2 : C1
{
public:
  C2();
  ~C2();
};

C2::C2(){}
C2::~C2(){}

void C2::junda(int a){
  cout << a << endl;
}

int main(int argc, char const *argv[])
{
  C1 c1;
  C2 c2;
  c1.junda("fausto");
  c2.junda(4);
  return 0;
}
