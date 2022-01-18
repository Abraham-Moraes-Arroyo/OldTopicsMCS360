#include <iostream>
using namespace std;
int main()
{
    cout<<"enter string: ";
    string str;
    cin >> str;
    for(int i = str.length() - 1; i >= 0; i--){
        cout<< str[i];
    }
    return 0;
}