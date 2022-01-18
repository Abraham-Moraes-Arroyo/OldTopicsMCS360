#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Cylinder {
    
      private:
         double radius;   
         double height;            
         friend string show(Cylinder);         // displays the cylinder properties     
         friend double getBaseArea(Cylinder);  // takes Cylinder object on input
         friend double getSideArea(Cylinder*); // takes Cylinder pointer object on input  

      public:

         Cylinder(double r = 0, double h = 0);  // Declaring the constuctor; values must be initialized for operator overloading to work!
         
         double pi = 3.14;          // public class variable
         double getRadius();
         double getHeight(); 
         double getVolume();
         Cylinder compareVolumes(Cylinder, Cylinder);

         //overloading the + operator for Cylinder variable B
         Cylinder operator + (Cylinder B) {
            Cylinder C;
            C.radius = radius+B.radius;
            C.height = height+B.height;
            return C;
         }
         //overloading the - operator for, given an address of the Cylinder variable B
         Cylinder operator - (Cylinder &B) {
            Cylinder C;
            C.radius = this->radius-B.radius;
            C.height = this->height-B.height;
            return C;
         }
         
}; 

// here we make use of the constructor
Cylinder::Cylinder(double r, double h) {
         radius = r;
         height = h;
}

// we use the "scope resolution operator :: " to write class methods and link them to their corresponding class
double Cylinder::getRadius(){
       return radius;
}

double Cylinder::getHeight(){
       return height;
}

string show(Cylinder C){
       return "Cylinder("+to_string(C.radius)+", "+to_string(C.height)+")";
} 

double getBaseArea(Cylinder C){
       return C.pi * pow(C.radius, 2);
}

// this function takes a pointer variable on input
double getSideArea(Cylinder *C){
       return 2*(C->pi)*(C->radius)*(C->height); // because of the pointer, we use -> operator
} 

//this is a an ordinary class function which computes the volume of the cylinder
double Cylinder::getVolume(){
       return pi*pow(radius, 2)*height; 
}

//this class function compares the volume of two instance and returns the instance with the larger volume
Cylinder compareVolumes(Cylinder A, Cylinder B){
         double v1 = A.getVolume();
         double v2 = B.getVolume();
         if (v1 > v2)
             return A;
         else
             return B;
}


int main(){
    Cylinder C1(10, 20); // C1 is an instance of the class
    Cylinder C2(5, 5); // C2 is the second instance of the class
    cout << show(C1) << endl;
    cout << show(C2) << endl;
    //illustrating the two friend functions
    cout << getBaseArea(C1) << endl;  // takes an instance as its argument
    cout << getSideArea(&C2) << endl; // here we pass the address to the function, since it takes a pointer as its argument
    cout << C1.getVolume() << endl;   //class function, takes no input; works in any instance
    cout << show(compareVolumes(C1, C2)) << endl;
    cout << show(C1+C2) << endl;
    cout << show(C1-C2) << endl;
    return 0;
}