#include <iostream>
using namespace std;

bool isPalindrome(string str, int s, int e){
    if(s>e){
        return true;
    }
    if(str[s] == str[e]){
        return isPalindrome(str, s + 1, e - 1);
    }else{
        return false;
    }
}

int main(){
    string str = "radar";
    int s = 0;
    int e = str.length() - 1;

    cout << isPalindrome(str, s, e) << endl;
    return 0;
}