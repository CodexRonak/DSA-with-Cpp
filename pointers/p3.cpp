#include<iostream>
using namespace std;

void inc(int *num){
    *num += 1;
}

void update(int *num){
    num += 1;
    cout << "inside update " << num << endl;
    }
int main(){
    int a = 5;
    int *p = &a;
    cout << *p << endl;
    cout << p << endl;
    inc(p);
    cout << "inc " << *p << endl;
    cout << "inc " << p << endl;
    update(p);
    cout << "update " << *p << endl;
    cout << "update " << p << endl;
    return 0;
}