// Class Inheritance with C++

#include<iostream>
#include<string>
#include<vector>

using namespace std;


//Rectangle will be our base class
class Rectangle {
    
      private:
         double length;  
         double width;
         friend string show(Rectangle); // displays the rectangle properties     
         friend vector<double> getCenter(Rectangle);

      public: 
         Rectangle(double length = 0.0, double width = 0.0);  // Declaring the constuctor, with initialization
         string dynamicShow(); // this is an ordinary class member function
         double getArea(); 
}; 

// here we make use of the constructor
Rectangle::Rectangle(double l, double w) {
         length = l;
         width = w;
}

string show(Rectangle R){
       return "<"+to_string(R.length)+", "+to_string(R.width)+">";
}

string Rectangle:: dynamicShow(){
       return "<"+to_string(length)+", "+to_string(width)+">";
}  

double Rectangle::getArea(){
       return length*width;
}


vector<double> getCenter(Rectangle R){  // note how we do not use "scope resolution operator Rectangle::
       // this function prints to screen the coordinates of the rectangle center 
       vector<double> v;
       v = {R.length/2, R.width/2}; // we use the dot operator for friend functions; we do not need getLength();
       return v;
}

//Square will be our derived case. 
class Square: public Rectangle{
      public:
      //overloading "default" constructor; data members are initialized in base class Rectangle, hence the empty {} 
      Square(double side): Rectangle(side, side) {};
};  

int main(){
    Rectangle R1(4, 6); // R1 is an instance of the class
    // R1 instance is a locally declared instance. R1 will delte itself when it exits the scope; no need to use or to declare a destructor
    cout << show(R1) << endl;
    cout << "Area: " << R1.getArea() << endl;  // this is a class function, not a private member
    vector<double> v = getCenter(R1);
    cout << "Center location: " << "(" << v[0] << "," << v[1] << ")" << endl;
    // executing delete R1 will not work; it s not necessary to delete local instances
    //----------end of part 1----------------------------

    Rectangle *R2 = new Rectangle(8, 9); // R2 is a dynamically allocated Rectangle, i.e. as when instances are allocated at runtime
    cout << R2->dynamicShow()<< endl;
    cout << "Area: " << R2->getArea() << endl;
    delete R2; // not to have amemory leak, delete instances that are dynamically allocated
    cout << "Area: " << R2->getArea() << endl; // shows 0, since the instance has been deleted;
    //----------end of part 2----------------------------
    Square S1(10);
    cout << show(S1) << endl;
    cout << "Area of the Square: "<< S1.getArea() << endl;
    //----------end of part 2----------------------------
    Square *S2 = new Square(20);
    cout << S2->dynamicShow() << endl;
    cout << "Area of the Square: "<< S2->getArea() << endl;
    return 0;
}