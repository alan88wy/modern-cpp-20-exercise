#include <iostream>
using namespace std;

// Class that uses this pointer
class A {
    public:
      int a;
      A(int a) {
  
          // Assigning a of this object to
          // function argument a
          this->a = a;
      }
      void display() {
  
          // Accessing a of this object
          cout << "Value: " << this->a  << endl;
      }
  };

/* local variable is same as a member's name */
class B
{
private:
   int x;
public:
   void setX (int xi)
   {
       // The 'this' pointer is used to retrieve the object's x
       // hidden by the local variable 'x'
       this->x = xi;
   }
   void print() { cout << "x = " << x << endl; }
};

/*
    To return reference to the calling object

    // Reference to the calling object can be returned
    Test& Test::func () {
        // Some processing
        return *this;
    } 
*/
class C
{
private:
  int x;
  int y;
public:
  C (int x = 0, int y = 0) { this->x = x; this->y = y; }
  C &setX(int a) { x = a; return *this; }
  C &setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main() {
  
    // Checking if this works for the object
    A o(10);
    o.display();

    /* local variable is same as a member's name */
    B obj;
    int x = 20;
    obj.setX(x);
    obj.print();

    // To return reference to the calling object
    C obj1(5, 5);

    // Chained function calls.  All calls modify the same object
    // as the same object is returned by reference
    obj1.setX(10).setY(20);

    obj1.print();


    
    return 0;
  }