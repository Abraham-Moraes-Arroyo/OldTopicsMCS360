/* The string Class */

/* The string class is an abstract data type. That is, it is not a built-in data type, like char or int for example. It is an added-on component of the C++ language. In order to work with the string data type, we must first include the string header file. 

The string data type is accompanied by a set of member functions, that is, a set of function that operate on this data type. We are going to cover a subset of these member functions due to the time constraints. */

/* 1. Basics */
/*
#include<iostream>
#include<string>   // first include the string header file to work with strings

using namespace std;

int main() {
    string s1; // declaring a string varibale 
    string s2 = "hello world!"; // declaring a string varibale and setting it equal to a specific string
    cout << s2 << endl;

    // second part of the main function
    string day;
    string sentence;

    cout << "What day is it today? ";
    cin >> day;  // this reads in a single word; space character is seen as end of string when the string is read-in with cin
    cout << "Great, I am glad it is " << day << "." << endl;

    cout << "Describe why you like " << day << " in one sentence: ";
    cin.ignore(); // When getline is used after cin, the getline() sees a newline character as leading empty space, so it never reads-in the imput
    getline(cin, sentence); // reading in an entire sentence, instead of just a word
    cout << "You said: " << sentence << endl;

    return 0;        
}
*/

/* 2. String Class Member Functions (some common ones) */
/*
#include<iostream>
#include<string>   // first include the string header file to work with strings

using namespace std;

int main() {
    string s = "MCS 360 at UIC"; // our string variable
    
    // execute these commands as blocks; keep the rest commented out.

    //s.append(" hello");  // appending a string to another string; can be used to initiate an empty string to a specific string
    //cout << s << endl;

    //s += " hello";  // alternatively
    //cout << s << endl;

    //s.begin(); // returns an iterator, pointing to the begin of the string
    //s.end();   // returns an iterator, pointing to the end of the string
    //cout << *s.begin() << endl; // points to M, here we can see it

    //cout << s.at(8) << endl; // returns the character at position 8
    
    //cout<< s.find("at") << endl; // finds the index location of the substring at
    
    //cout << s.size() << endl;   // functions size and length perform the same operation, telling us how many characters are there in the string.
    //cout << s.length() << endl; //

    //s.insert(7, "(Fall 2020)"); // inserting substring (Fall 2020) into the string s, starting at index 7.
    //cout << s << endl;

    //cout << s.substr(8, 2) << endl; // returns a copy of the substring, which starts at index 8 and is 2 characters long 

    //s.erase(); // remove all characters from the string; the variable is s is still valid; same with s.clear()
    //s.erase(8, 2); // ereases 2 characters, starting at index 8 from the string s
    //cout << s << endl;

    //s.replace(8, 2, "*AT*"); // replaces 2 characters, starting at index 8 in the string s with the string "*AT*"
    //cout << s << endl;

    //cout << s.compare("MCS") << endl; // same as strcmp in C; here it returns 11, a positive number, since s is larger;
    //cout << s.compare("MCS 360 at UIC in the Fall") << endl; // -12, since s is smaller
    //cout << s.compare("MCS 360 at UIC") << endl; // 0, since they are the same

    //cout << to_string(1234)+"hello"  << endl;  // converting numerical values to string, we can add to it another string "hello"

    // converting strings to numerical types
    string s1 = "100";
    string s2 = "3.14";
    cout << stoi(s1)+5 << endl;  // to integer
    cout << stof(s2)+1.0 << endl; //to float
    cout << stod(s2)+2.0 << endl; //to double
    return 0;        
}
*/


/* Readin Passing strings to a function */

#include <iostream>
#include <fstream> // library to for file processing
#include <string>
using namespace std;

int main () {
    string line;
    string text;
    ifstream my_file;  // input file strem 
    my_file.open("chicago-wiki.txt"); // ifstream my_file("chicago-wiki.txt"); is another way to open a file 
    if (my_file.is_open()){
       while(getline(my_file, line)){
          cout << line << endl;
          text += line;
       }
       my_file.close();
    } 
    else{ 
      cout << "File cannot be opened!";
    }
    cout << "--------------" << endl;
    cout << "The whole text as a single string" << endl;
    cout << "--------------" << endl;
    cout << text << endl;
    return 0;
}
