/* 5. Call by Value vs. Call by Constant Reference */

/*
When working with functions in programming languages, the functions can be invoked in two ways
1) by value (call by value) 
2) by reference (call by constant reference)

The "call by value" means that the argument's value - that is, a copy of the object named by the
argument - is passed to the function, so that even if the function modifies the parameter value, 
the modification will not remain after the return from the function.
*/

/*
#include<iostream> 

using namespace std;

void swap(int x, int y){
    int z;
    z = x;
    x = y;
    y = z;
    cout << "x = " << x << endl; 
    cout << "y = " << y << endl; 
}

int main(){
    int a = 5;
    int b = 10;

    // The call by value example
    swap(a, b);  // exchanges the two values with each other
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // note how, despite the change, a and b remain unchanged
    // because a copy of a and b had been created and then they were swapped 
    return 0;
}
*/

/*
With the "call by constant reference", a reference to the argument object is passed to the function. If the function modifies the parameter value, this modification is made to the original object named by the argument.\\
*/

/*
#include<iostream> 

using namespace std;

void swap(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
    cout << "x = " << *x << endl; 
    cout << "y = " << *y << endl; 
}

int main(){
    int a = 5;
    int b = 10;

    // The call by constant reference
    swap(&a, &b);  // exchanges the two values at their address with each other
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // because the values at addresses have been changed, a and b have been permanently altered
    // ie. no copies were created/changed with but values directly stored at those addresses
    // consequently, the values were permanently swapped.
   return 0;
}
*/

/*Topic: File Input and Output in C++*/

/*File stream data types:

  - ofstream is the output file stream. use this to create files and write data to them.
    in this type data can be only copied from variables to the file but not vice versa.

  - ifstream is input file stream. use this to open existing files and write data to them.
    in this type data can be copied from file into variables, but not vice versa.

  - fstream is used for both. that is, data can be copied from variables into a file and from file into variables.
*/


/*
//Writing data to a file example:

#include<iostream>
#include<fstream> // library needed to work with files; fstream = file stream; think of files as streams of data;

using namespace std;

int main()
{
  ofstream my_output_file; //declaring a type and file variable  
  my_output_file.open("output1.txt");

  unsigned seed = time(0); // unsigned for positive or zero integer
  srand(seed);             // initialize random number generator

  int x, y, z;

  x = 1 + rand() % 1000; //limiting the range of the random number between 1 and 1000
  y = 1 + rand() % 1000; //limiting the range of the random number between 1 and 1000
  z = 1 + rand() % 1000; //limiting the range of the random number between 1 and 1000
  
  my_output_file << "This file contains 3 randomly generated integers between 1 and 1000 " << endl;
  my_output_file << x << endl; // here we write the integer value
  my_output_file << y << endl;
  my_output_file << z << endl;
  my_output_file << "end of the file." << endl; // adding some text to 
  my_output_file.close(); // when done working with a file, close it.   
  return 0;
}
*/

/*
//Reading data from a file example:

#include<iostream>
#include<fstream> // library needed to work with files; fstream = file stream; think of files as streams of data;

using namespace std;

int main()
{
  ifstream my_input_file;
  const int SIZE = 81; // max number of characters in file per line. each line usually contains 80+1 ('\n') characters
                     // const tells the compiler to fix the SIZE to 81 and never to modify it.
  char line[SIZE];   // each line is an array of 81 characters at the most.
  
  my_input_file.open("inputfile1.txt");

  cout << "Fetching lines from file" << endl; // prints a message to screen;

  my_input_file >> line; // read the first line from file
  cout << line << endl;  // print the first line to screen
  
  my_input_file >> line; // read the second line from file
  cout << line << endl;  // print the second line to screen

  my_input_file >> line; // read the third line from file
  cout << line << endl;  // print the third line to screen

  my_input_file.close(); // when done working with a file, close it.

  cout << "Finished fetching lines from file" << endl; // prints another message to screen;
  return 0;
}
*/