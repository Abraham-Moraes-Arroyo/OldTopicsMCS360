#include<iostream>
#include<string>

/* Polymorphisms and Virtual Functions
   - polymorphism occurs when there is a hierarchy of classes and they are related by inheritance with each other.
   - Inheritance can cause conflicts, for example, if we have functions with the same name, defined in both the 
     base class and the derived class. Polymorphism and virtual functions resolve such issues. 
   - Polymorphic behavior of class member functions is only possible when we pass an object to functions by reference.
   - Polymorphic behavior of class member functions is not possible when an object is passed to functions by value.
   - A virtual function is a function, declared in in a base class using the keyword "virtual". 
     It signals to the compiler that we do not want static binding (early binding), set at complie time.
     Instead, keyword virtual signals to the compiler that we want dynamic (late binding) in which the function's
     relation to the object is defined dynamically (later) and this links the function with the object it is meant 
     to work with explicitly. 
*/

/*Virtual functions allow us to create a sequence of base class pointers and calls to class member functions for any of the derived classes. In particular, we do not even need to know with which kind of derived class object we are dealing with. 
This is where the term Polymorphism, ie. "abilityt to take on many shapes", is derived form; 
*/

/*
Recall:
A pointer variable is a variable that holds a memory address, that is, the location of the object in memory. 
A reference has the same memory address as the object it is referencing. 
We dereference pointer variable with * to access the memory location of the object that it points to.
A reference, however, is used directly.
*/

using namespace std;

/*Part 1 - Illustration of the need for Polymorphism and how its necessity arises*/

/*
// base class
class UICMember{
      protected:
        string name;
        int uin;

      public:
      // default constructor
      UICMember(string member_name, int member_id_number){
         name = member_name;
         uin = member_id_number;
      }

      string getRoleDescription(){
         return "Works for UIC";
      }
};

// derived class
class Professor: public UICMember{
      public:
        // declaring derived class constructor with initialization
        Professor(string member_name, int member_id_number) : UICMember(member_name, member_id_number){
        }

        string getRoleDescription(){
          return "Teaches at UIC";
        }
};

// second derived class
class Student: public UICMember {
      public:
        // declaring second derived class constructor with initialization
        Student(string member_name, int member_id_number) : UICMember(member_name, member_id_number){
        }

        string getRoleDescription(){
          return "Takes classes at UIC";
        }  
};

int main(){

    UICMember *M1, *M2;              //declaring pointer variables for the object UICMember
    Professor P("Jane Doe", 29464);  // object of the derivated class Professor
    Student S("John Doe",   55812);  // object of the derivated class Student

    M1 = &P;
    M2 = &S;
    cout << M1->getRoleDescription() << endl;
    cout << M2->getRoleDescription() << endl;
    //This output for above is clearly not accurate. A student does not usually work for the university!
    //What has happended is that the compiler has made a call to the getRoleDescription(), defined in the base class,
    //and not to those defined in the derived classes; We want to fix this! That is, we want to be able to call
    //getRoleDescription() function and it should work for its respective object!
    return 0;
}
*/

/*Part 2 - Illustration of the fix to the problem with virtual functions*/

// base class
class UICMember{
      protected:
        string name;
        int uin;

      public:
      // default constructor
      UICMember(string member_name, int member_id_number){
         name = member_name;
         uin = member_id_number;
      }

         virtual string getRoleDescription(){
         return "Works for UIC";
      }
};

// derived class
class Professor: public UICMember{
      public:
        // declaring derived class constructor with initialization
        Professor(string member_name, int member_id_number) : UICMember(member_name, member_id_number){
        }

          virtual string getRoleDescription(){
          return "Teaches at UIC";
        }
};

// second derived class
class Student: public UICMember {
      public:
        // declaring second derived class constructor with initialization
        Student(string member_name, int member_id_number) : UICMember(member_name, member_id_number){
        }

          virtual string getRoleDescription(){
          return "Takes classes at UIC";
        }  
};

int main(){

    UICMember *M1, *M2;              //declaring pointer variables for the object UICMember
    Professor P("Jane Doe", 29464);  // object of the derivated class Professor
    Student S("John Doe",   55812);  // object of the derivated class Student

    M1 = &P;
    M2 = &S;
    cout << M1->getRoleDescription() << endl;
    cout << M2->getRoleDescription() << endl;
    
    return 0;
}