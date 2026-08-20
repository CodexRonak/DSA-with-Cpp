#include<iostream>
using namespace std;

int main(){

    int i = 2;
    int *p1 = &i;
    int **p2 = &p1;

    // value of i
    cout << i << endl;
    cout << *p1 << endl;
    cout << **p2 << endl;
    cout << endl;
    
    // address of i
    cout << &i << endl;
    cout << p1 << endl;
    cout << *p2 << endl;
    cout << endl;
    
    // address of p1
    cout << p2 << endl;
    cout << &p1 << endl;
    cout << endl;
    
    // address of p2
    cout << &p2<< endl;


    return 0;
}
