#include <iostream>
using namespace std;

int len(char var[]){
    int count = 0;
    for (int i = 0; var[i] != '\0'; i++){
        count++;
    }
    return count;
}

char lowercase(char ch){
    if('a' <= ch && 'z' >= ch){
        return ch;
    }
    else{
        return ch = ch - 'A' + 'a';
    }
}


bool palidrome(char str[], int n){
    int s = 0, e = n - 1;
    while(s<=e){
        if(lowercase(str[s++]) != lowercase(str[e--])){
            cout << "Not a palindrome" << endl;
            return false;
        }
    }
    cout << "Palindrome" << endl;
    return true;
}

int main(){
    char str[20];
    cout << "enter " << endl;
    cin >> str;
    int n = len(str);
    palidrome(str, n);
    return 0;
}