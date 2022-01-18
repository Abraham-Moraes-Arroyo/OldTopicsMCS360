/*5. Templates

The idea of a template has been introduced to C++ to allow functions and classes to operate with generic types. This is especially useful when it comes to code recycling, and object oriented programming in general, as it allows for creation of general procedures that work on several data types istead of just one.

Consider the case when we need to sort some data. The data can come in different forms - it can be numeric (such as integers, floats, etc) but it can also be characters.

In such a case we can make use of a template, in which a generic template type parameter T stands for any of the data types we would wish to sort. 

Along the same lines, this idea can be applied to searching as well as to storing of data, for example, in a vector or any other container (stacks, lists, queues, etc). Without templates, we would need to declare a vector for each type. However, with templates, we can create a vector using the generic template type parameter T and use that T to stand for any data type we wish to store.

There are three template types: function, variable, and class templates. 
The generic formats are:
 - template <typename indetifier> "function declaration"; (for functions and variables)
 - template <class indetifier> "class declaration";       (for classes)

The function template is treated and used as an ordinary function, which has the special ability to handle function arguments of many different types. 

The variable template allows us to define constants, for example, which work for the various data types of C++: integers, doubles, floats, etc.

The class templates are generally used for creation of advance structures, for example, container-like objects, and class member functions operating on such objects.

In general, we use 
 - typename indetifier for functions and variables
 - class identifiers when creating class templates
*/


// 1. Function Templates
/*
#include<iostream>

using namespace std;

// my_min function arguments can now be of any type for which the symbol "<" is applicable. For example, x and y can be doubles, floats, etc but also characters.

template <typename T> // using template <class T> is fine as well
T my_min(T x, T y) {
  T min;
  if (x < y)
     min = x;
  else
     min = y;
  return min;
}

int main(){
    cout << my_min(3, 5) << endl;
    cout << my_min(4.56, 4.11) << endl;
    cout << my_min('x', 'c') << endl;
    return 0;
}
*/

// 2. Variable Templates

/*
#include<iostream>

using namespace std;

// by setting up this template, we can use constant e with different types
template<typename T> 
constexpr T e = T(2.71828);


int main(){
    
    cout << e<int> << endl;
    cout << e<double> << endl;
       
    return 0;
}
*/


// 3. Class Templates A
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;


// the following implements a generic vector, capable of holding any data type
template<class T, int n> 
class my_container {
      T c {n}; // using vector, holding n elements
      public:
        my_container(T v){    //constructor
          for (int i = 0; i<n; i++){
              c[i] = v[i];
          }
        }
        
        void show(){
             for (int i = 0; i<n; i++){
                 cout << c[i] << " ";
             }
             cout << endl;
        } 
};

int main(){
    my_container<vector<int>, 3> C1({1,2,3});
    my_container<vector<char>, 3> C2({'x','y','z'});
    C1.show();
    C2.show(); 
    return 0;
}
*/

// 3. Class Templates B

#include<iostream>
#include <algorithm>
#include<string>

using namespace std;


// The following implements a new data type, pretty much what you can do with an ordinary class.
// Here we want to see how to implement class memeber functions, outside the class

template<class T> 
class Tripple {
      private:
        T a, b, c; // three variables of type T

      public:
        Tripple(T x, T y, T z){   //constructor
          a = x;
          b = y;
          c = z;
        }
        string show();
        T get_min();
        int get_sum(); // you can also specify type if you do not want type T
        
};

template <class T>
string Tripple<T>::show(){
     return "<"+to_string(a)+", "+to_string(b)+", "+to_string(c)+">";
}

template <class T>
T Tripple<T>::get_min(){
     return min(min(a,b),c); // min function located in algorithm library works with 2 values
}

template <class T>
int Tripple<T>::get_sum(){
     return a+b+c; // min function located in algorithm library works with 2 values
}

int main(){
    Tripple<int> A(1,2,-3);
    cout << A.show() << endl;
    cout << A.get_min() << endl; 
    cout << A.get_sum() << endl; 
    return 0;
}
