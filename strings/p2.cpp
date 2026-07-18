#include <iostream>
using namespace std;

int length(char var[]){
    int count = 0;
    for (int i = 0; var[i] != '\0'; i++){
        count++;
    }
    return count;
}

void revString(char str[]){
    int s = 0;
    int e = length(str)-1;

    while(s<=e){
        swap(str[s++], str[e--]);
    }
    cout << str;
}

int main(){
    char str[20];
    cout << "enter your string" << endl;
    cin >> str;
    revString(str);
}