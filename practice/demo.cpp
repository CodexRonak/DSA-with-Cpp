#include <iostream>
using namespace std;
int main(){
    int st = 0;
    int end = 6;
    for (st; st < end; st++){
        cout << "start1: " << st << endl;
        cout << "end1: " << end << endl;
        st--;
        end--;
        cout << "start2: " << st << endl;
        cout << "end2: " << end << endl;
    }
    return 0;
}