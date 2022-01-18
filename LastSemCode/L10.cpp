#include<iostream> 
#include<cstdlib>  // needed for the exit function
#include<string>
using namespace std;


// Declaring a Rectangle class

class Rectangle {
      // we have two sets of methods, private and public
      // private methods can only be accessed inside the class
      private:
         double length;  //these are two (private) class members and can only be accessed by 
         double width;   // the functions in the class definition and not in the main function directly
    
      public: 
         // all methods are declared inside the class but defined outside the class and linked via scope resolution operator ::
         // public methods can be accessed outside the class, such as in main() function

         // the next item is called a constructor! a constructor is a member function whichi is automaticall called any time a class object is created.
         // think of a constructor as an initilization procedure.
         // they are used to perform member variable initializations and other setup operations
         // when not explicitly defined, compiler will will create a most basic, default constructor and apply it
         // we will use it to initilize rectangle objects at declaration

         Rectangle(double, double);  // Declaring the constuctor

         // The main idea behind the const functions is not to allow these functions to modify the object on which they are called. 
         // This is recommended practice to ensure that accidental changes to objects are prevented from the start.
         // Recall also that const is followed by an initialization (const variable = some_value). Here the constructor serves this purpose, and 
         // const classs method declaration is only possible if the constructor is used (see  below).
         // unlike with variables, for functions const is placed at the end of the declaration.
         double getLength() const; // const indicates to complier that the function getLength() will not change the data stored in object it handles/calls
         double getWidth() const; 
         double getArea() const;
         double getPerimeter() const;
         bool isSquare() const;

}; //class definitions end with ; 

// here we make use of the constructor
Rectangle::Rectangle(double l, double w) {
         length = l;
         width = w;
}

// we use the "scope resolution operator :: " to write class methods and link them to their corresponding class

double Rectangle::getLength() const {
       // retrieves and returns the value of the length member
       return length;
}

double Rectangle::getWidth() const {
       // retrieves and returns the value of the width member
       return width;
}

double Rectangle::getArea() const {
       return length*width;
}

double Rectangle::getPerimeter() const {
       return 2*length+2*width;
}

bool Rectangle::isSquare() const{
     if (length == width)
        return true;
     else
        return false; 
}

int main(){
    //Note, we do not need to set values via  R.setLength(l) or R.setWidth(w); we do not need to declare l, and w, either

    Rectangle R(10, 25); // R is an instance of the class
    cout << "Rectangle Properties" << endl;
    cout << "Length: " << R.getLength() << endl;
    cout << "Width: " << R.getWidth() << endl;
    cout << "Area: " << R.getArea() << endl;
    cout << "Perimeter: " << R.getPerimeter() << endl;
    cout << "Is it a Square?: " << R.isSquare() << endl;
    return 0;
}