/*
Sequential Containers: Vector data type from Standard Template Library (STL)
  - vector data type defines a sequential container
  - resembles an array but it is more powerfull, 
    flexible and easier to work with than arrays
  - vector is not a built-in type so the library
    STL library containing it must be included prior to use
*/


/* 1. Introduction */
/*
#include<iostream>
#include<vector>     // needed so we can define vectors
#include<string>
#include<algorithm>  // needed for the sort function

using namespace std;

int main(){
  vector<int> v1;    // defines an empty vector; size does not need to be declared.
  vector<int> v2(5); // defines an empty vector for 5 integers, but we can add more; its not bounded by the size
  vector<int> v3(5, 10); // this is how we define a vector for 5 integers, all initialized to value 10; 
  vector<int> v4{7,3,8,6,0,4,5,2}; // vector containing values 7,3,8,6,0,4,5,2
  vector<string> v5{"mcs","360","at","UIC"}; // vector of strings

  // looping through vector and printing its values to screen
  // vector is an index data type, much like an array
  // here we use the function size() to find the length of a vector
  for(int i = 0; i < v4.size(); i++){
     cout<< v4[i] << endl; 
  }

  // alternatively, we can loop through a vector using a "for" loop over a range.
  // keyword "auto" is convenient as it deduces the type of a declared 
  // variable from its initialization expression;
  // elements can appear on one line, if we use " " before endl
  for (auto x : v4) cout << x << " "; cout << endl;

  // vector can be sorted with the sort function
  sort(v4.begin(), v4.end());
  for (auto x : v4) cout << x << " ";
  cout << endl;

  // in case of strings the sort order is: first numbers, 
  // then upper case letters, then lower case letters; this is due to ASCII;
  sort(v5.begin(), v5.end()); // sorting
  for (string s : v5) cout << s << " "; cout << endl;

  return 0;
}
*/



/* 2. Vector Member Functions; Common functions operating on vector data type 
   - of special importance are functions begin()/end(), which return an iterator 
     pointing to the first element in the sequence. 
*/

/*
#include<iostream>
#include<vector> 
#include<algorithm> // for the reverse function

using namespace std;

int main(){
  vector<int> v{7,3,8,6,0,4,5,2,7};

  cout << v.size() << endl;     // size() shows current number of elements
  cout << v.capacity() << endl; // capacity() shows how many elements can be stored in vector 
  cout << v.at(3) << endl;      // at() function returns the value at index location 3.
  v.pop_back();   // pop_back() removes the last element in the vector!
  v.push_back(2); // push_back() appends 2 to then end of the vector; 
  // when inserting at location other than front/back, use iterators
  v.insert(v.begin() + 4, 9); // inserts integer 9 at index location 4, using an iterator with v.begin(). 
  for (auto x : v) cout << x << " "; cout << endl;

  v.erase(v.begin() + 4); // erases value at index location 4, using an iterator with v.begin(). 
  for (auto x : v) cout << x << " "; cout << endl;

  // removing all elements of specific value, here integer 7, can be achieved with
  v.erase(remove(v.begin(), v.end(), 7), v.end()); 
  for (auto x : v) cout << x << " "; cout << endl;

  // all elements can be reversed with
  reverse(begin(v), end(v));  
  for (int x : v) cout << x << " "; cout<<endl;

  v.clear(); // clear() clears the vector of all its elements! does not return anything, so we do not print
  cout << v.empty() << endl; // empty() function returns true (1) if vector is empty or false (0) if vector is not empty.
     


  return 0;
}
*/


/* 3. 2D Vectors */
/*
#include<iostream>
#include<vector> // needed so we can define vectors


using namespace std;

int main(){
  vector<vector<int>> M{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // notice the nesting of vectors as dimension increases
  for(int i=0; i < M.size(); i++){
     for(int j=0; j < M[i].size(); j++)
        cout<< M[i][j] << " ";
     cout<<endl;
  }                
  return 0;
}
*/

/* 4. Passing Vectors to functions as arguments, which also return vectors*/

/*
#include<iostream>
#include<vector> // needed so we can define vectors
#include<string>

using namespace std;

vector<int> add_5(vector<int> v){
     // inside functions, we need to say how long the vector 
     // we return should be
     vector<int> w(v.size());
     for(int i=0; i < v.size(); i++){
        w[i] = v[i]+5;
     }
     return w;
}

int main(){
  vector<int> v{1,2,3,4,5,6};
  vector<int> z; 
  z = add_5(v);
  for (auto x : z) cout << x << " "; cout << endl; 
  return 0; 
  
}

*/
