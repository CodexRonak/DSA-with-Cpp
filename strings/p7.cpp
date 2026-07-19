#include <iostream>
#include <string>
using namespace std;


string removeSpaceInPlace(string str) {
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') {
            str.replace(i, 1, "@40"); 
            i += 2;
        }
    }
    return str;
}

int main(){
    string str;
    cout << "enter your line" << endl;
    getline(cin, str);
    string output = removeSpaceInPlace(str);
    cout << output ;
    return 0;
}