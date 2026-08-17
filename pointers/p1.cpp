#include<iostream>
using namespace std;

// int main(){

//     // int a = 4;
//     // int *ptr = &a;

//     // (*ptr)++;

//     // cout << &a << " " << ptr << endl;
//     // cout << a << " " << *ptr << endl;

//     int a = 10;
//     int *p = &a;
//     int *q = p;

//     (*q)++;

//     cout << &a << " " << p << " " << q << endl;
//     cout << a << " " << *p << " " << *q << endl;

//     return 0;
// }


int main(){

    char s[]= "hello";
    char *p = s;  // it will be &s[0] implicitly
    cout << s[0] << " " << p[0];

}