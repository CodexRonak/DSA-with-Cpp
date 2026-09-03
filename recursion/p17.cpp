#include <iostream>
#include <algorithm>
using namespace std;

string revStr(string str, int s, int e){
    if(s>=e){
        return str;
    }

    swap(str[s], str[e]);
    return revStr(str, s + 1, e - 1);
}

int main(){
    string str = "ronak";
    int s = 0;
    int e = str.length() - 1;
    cout << revStr(str, s, e);
    return 0;
}