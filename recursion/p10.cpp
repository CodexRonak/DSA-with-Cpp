#include <iostream>
using namespace std;

double finalDec(int n, double ans, double factor){
    if((ans + factor) * (ans + factor) > n){
        return ans;
    }
    return finalDec(n, ans + factor, factor);
}

double morePrecision(int n, int p, double ans, double f = 1){
    if(p == 0){
        return ans;
    }

    f = f / 10;

    ans = finalDec(n, ans, f);

    return morePrecision(n, p - 1, ans, f);
}

long long int sqrt(int n, int s, int e, long long int ans = 0){
    long long int m = s + (e - s) / 2;
    if (s > e) {
        return ans;
    }
    
    if(m * m == n){
        return m;
    }
    else if( m * m > n){
        return sqrt(n, s, m - 1, ans);
    }
    else{
        return sqrt(n, m + 1, e, m);
    }

    return -1;
}

int main(){

    int n;
    cin >> n;

    int s = 0;
    int e = n;

    int ans = sqrt(n, s, e, 0);
    int p = 2;

    cout << morePrecision(n, p, ans) << endl;
    return 0;
}