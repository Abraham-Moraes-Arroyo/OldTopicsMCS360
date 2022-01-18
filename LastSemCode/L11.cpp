#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Rectangle {
    
      private:
         double length;  
         double width;
         string s1 = "private variable element";
         // A friend function of a class has the right to access all private and protected members of the class, however, it is defined outside of the scope of that class.
         // Even though the friend functions are declared in the class definition, friends functions are not member functions.
         friend double getLongerSide(Rectangle); // it accepts single variable of type Rectangle as its argument; its always declared here, in private section
         friend double* getCenter(Rectangle); // returns an array of two doubles 

      public: 
         Rectangle(double, double);  // Declaring the constuctor
         double getLength();
         double getWidth(); 
         double getArea();
         string getPrivateElement();
         string s2 = "public variable element";

         
}; 

// here we make use of the constructor
Rectangle::Rectangle(double l, double w) {
         length = l;
         width = w;
}

// we use the "scope resolution operator :: " to write class methods and link them to their corresponding class
double Rectangle::getLength(){
       return length;
}

double Rectangle::getWidth(){
       return width;
}

double Rectangle::getArea(){
       return length*width;
}

string Rectangle::getPrivateElement(){
       return s1;
}

double getLongerSide(Rectangle R){  // note how we do not use "scope resolution operator Rectangle::
       double a = R.length;   // we use the dot operator for friend functions; we do not need getLength();
       double b = R.width;    // we use the dot operator for friend functions; we do not need getWidth();
       if (a > b)
          return a;
       else
          return b;       
}

double  *getCenter(Rectangle R){  // note how we do not use "scope resolution operator Rectangle:: because it is a friend function
       // this function prints to screen the coordinates of the rectangle center 
       static double A[2] = {R.length/2, R.width/2}; // we use the dot operator for friend functions; we do not need getLength();
       return A;
}

int main(){
    Rectangle R1(4, 6); // R1 is an instance of the class
    // R1 instance is a locally declared instance. R1 will delte itself when it exits the scope; no need to use or to declare a destructor

    cout << R1.getPrivateElement()<< endl;         //this is how you access private elements of a class, via a special function
    cout << "Length: " << R1.getLength() << endl;  //same here 
    cout << "Width: " << R1.getWidth() << endl;    //same here
    cout << R1.s2 << endl;                     //public elements of a class are accessed via the dot operator
    cout << "Area: " << R1.getArea() << endl;  // this is a class function, not a private member
    cout << "Longer side: " << getLongerSide(R1) << endl;  //
    double *V = getCenter(R1); // here we work with an array but in C++ working with vectors is better (vectors are covered a bit later)
    cout << "Center location: " << "(" << V[0] << "," << V[1] << ")" << endl;
    // executing delete R1 will not work; it s not necessary to delete local instances
    //----------end of part 1----------------------------
    Rectangle *R2 = new Rectangle(8, 9); // R2 is a dynamically allocated Rectangle, i.e. as when instances are allocated at runtime
    cout << "Area: " << R2->getArea() << endl;
    delete R2; // not to have amemory leak, delete instances that are dynamically allocated
    cout << "Area: " << R2->getArea() << endl; // shows 0 pointer, since the instance has been deleted;
    //----------end of part 2----------------------------
    return 0;
}