#include <iostream>
using namespace std;

void sayNum(string arr[], int n){
    if(n == 0)
        return ;

    int digit = n % 10;
    n = n / 10;
    sayNum(arr, n);
    cout << arr[digit] << " ";
}

int main(){
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};
    int n;
    cin >> n;

    sayNum(arr, n);
    return 0;
}