#include <iostream>
#include <string>
using namespace std;

bool check(char ch){
    if(('a' <= ch && 'z' >= ch) || ('A' <= ch && 'Z' >= ch) || ('0' <= ch && '9' >= ch)){
        return true;
    }
    else
        return false;
}

char toLower(char ch){
    if('A' <= ch && 'Z' >= ch){
        return ch - 'A' + 'a';
    }
    else
        return ch;
}

bool advPalindrome(string str){
    string temp = "";
    
    for(int i = 0; i < str.length(); i++){
        if(check(str[i])){
            temp.push_back(toLower(str[i]));
        }
    }
    int s = 0, e = temp.length() - 1;
    while(s <= e){
        if(temp[s++] != temp[e--]){
            cout << "Not a palindrome" << endl;
            return false;
        }
    }
    cout << "Palindrome" << endl;
    return true;
}

int main(){
    string str;
    cout << "enter " << endl;
    getline(cin, str);
    advPalindrome(str);
    return 0;
}