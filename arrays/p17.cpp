// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1


#include<iostream>
using namespace std;

long long int sqroot(int num){
    int s = 0, e = num;
    long long int ans = 0;
    int m = s + (e - s) / 2;
    if (num == 0 || num == 1) return num;
    while (s <= e){
        long long sq = m * m;
        if (sq == num ){
            ans = m;
            return ans;
        }
        else if (sq > num){
            e = m - 1;
        }
        else if (m * m < num){
            ans = m;
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int num, int precision, int tempsol){
    double ans = tempsol, factor = 1;

    for (int i = 0; i < precision; i++){
            factor = factor / 10;

        for (double j = ans; j * j <= num; j += factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int num = 37;
    int tempsol = sqroot(num);
    cout << morePrecision(num ,3 ,tempsol) << endl;
    return 0;
}