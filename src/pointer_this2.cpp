#include <iostream>

using namespace std;

class Test1
{
private:
  int x;
public:
  Test1(int x = 0) { this->x = x; }
  // void change(Test *t) { this = t; } // This is invalid.
  void change(Test1 *t) { this->x = t->x; }
  void print() { cout << "x = " << x << endl; }
};

class Test2
{
private:
  int x;
  int y;
public:
  Test2(int x = 0, int y = 0) { this->x = x; this->y = y; }
  static void fun1() { cout << "Inside fun1()\n"; }
  // static void fun2() { cout << "Inside fun2()"; this->fun1(); }  - not valid as this cannot be use in fun2
  static void fun2() { cout << "Inside fun2()\n"; fun1(); }
};

class Test3
{
private:
  int x;
  int y;
public:
  Test3 (int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test3 setX(int a) { x = a; return *this; }
  Test3 setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};

class Test4
{
private:
  int x;
  int y;
public:
  Test4(int x = 0, int y = 0) { this->x = x; this->y = y; }
  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy()  { delete this; }
  void print() { cout << "x = " << this->x << " y = " << this->y << endl; }
};

int main()
{
  Test1 obj(5);
  Test1 *ptr = new Test1 (10);
  obj.change(ptr);
  obj.print();

  Test2 obj2;
  obj2.fun2();

  Test3 obj3;
  obj3.setX(10).setY(20);
  obj3.print();

  cout << "Obj4 ..." << endl;

  Test4 obj4;
  obj4.destroy();
  obj4.print();

  return 0;
}