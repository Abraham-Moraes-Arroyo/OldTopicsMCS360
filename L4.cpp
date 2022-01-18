// PART 1

/* We demonstrate how to allocate arrays in C++. */

/*
#include <iostream>

using namespace std;

int main()
{
   int n;

   cout << "Enter the array dimension : ";
   cin >> n;

   cout << "allocating an array of length " << n << endl;
                 
   double a[n];
   for(int i=0; i<n; i++) 
      a[i] = double(i); //because the array holds doubles, we convert the integer variable i to a double

   for(int i=0; i<n; i++)
      cout << "  a[" << i << "] = " << a[i] << endl;
  
   cout << "---------------" << endl;

   //arrays can also be allocated dynamically
   int *b;  // this notation is called pointer notation; in C++ arrays and pointers are the same
   b = new int[n]; // dynamic allocation of an integer array
   for(int i=0; i<n; i++) 
      b[i] = i;

   for(int i=0; i<n; i++)
      cout << "  b[" << i << "] = " << b[i] << endl;

   delete[] b; // deallocation (memory release): dynamically allocated objects should always be deleted at the end 

   return 0;
}

*}

// PART 2

/*This code pairs the month with its number of days, using a 2D array. 
  We have already encoutered the type string but we can also think of 
  a string as an array of characters.
*/

/*
#include<iostream>

using namespace std;


int main()
{ 
  const int MONTH_NUMBERS = 12;  // cost tells the compiler that this variable cannot be altered beyond this point by the program
  const int STRING_SIZE = 15; // maximum size of each month name/string

  char months[MONTH_NUMBERS][STRING_SIZE] = {"January","February","March","April","May","June","July","August","September","October", "November","December"}; //month names
 
  int days[MONTH_NUMBERS] = {31,28,31,30,31,30,31,31,30,31,30,31}; // number of days

  // display months and their number of days
  for (int i = 0; i < MONTH_NUMBERS; i++)
  {
    cout << months[i] << " has " << days[i] << " days." << endl;
  }
 
  return 0;
}
 */

//Part 3

/*Topic Functions in C++*/

/*C++ programmers can use functions to define a group of statements that perform a
particular operation. The statements beginning with keyword return cause an exit
from the function; the expression following return is the function result.

In order for the compiler to compile a function call, it must first see a declaration of
that function. The declaration of a function specifies the name, return type, and
parameter types of a function.
*/

/*
  In this program we create an on-going menu, which keeps offeringg the user the
  choice of selecting a specific computation,
  1. Circle Area Computation
  2. Rectangle Area Computation
  3. Quit Program   
*/


#include<iostream>
#include<iomanip>

using namespace std;

// Declaring function prototypes - i.e. functions involved in this program, other than main()
// double area_of_circle(double); //input argument is radius of type double
// double area_of_rectangle(double, double); //input arguments are sides of the rectangle of type doubles
// bool is_square(double, double); // function returns boolean type true/false

double area_of_circle(double r)
{
  const double PI = 3.1415; //local function constant and variable
  double area;
  area = PI*r*r; //area is double as is the function type!
  return area;
}

double area_of_rectangle(double l, double w)
{
  double area;
  area = l*w; //area is double as is the function type!
  return area;
}

bool is_square(double l, double w)
{
  bool state;
  if (l == w)
     state = true;
  else
     state = false;
  return state;
}

int main()
{ 
  double radius;
  double length, width;
  int choice;
  
  cout << fixed << showpoint << setprecision(2); //setting the output format

  do {
     cout << "***** Menu *****" << endl;
     cout << "1. Circle Area Computation" << endl;
     cout << "2. Rectangle Area Computation" << endl;
     cout << "3. Quit Program " << endl;

     cout << "Enter your choice: ";
     cin >> choice;
  
     switch(choice)
     {
       case 1:
          cout << "Enter the radius: ";
          cin >> radius;
          cout << "Circle area is: " << area_of_circle(radius) << endl;
          cout << endl;
          break;
       case 2:
          cout << "Enter the length: ";
          cin >> length;
          cout << "Enter the width: ";
          cin >> width;
          cout << "Rectangle area is: " << area_of_rectangle(length, width) << endl;
          if ( is_square(length, width) )  // if is_square() returns true, then print; otherwise do nothing. 
             cout << "It is a square!" << endl;
          cout << endl;
          break;
       default:
          cout << "You have quit the program! " << endl;
     }
     } while (choice != 3);//  end of do statement  

  return 0;
}

