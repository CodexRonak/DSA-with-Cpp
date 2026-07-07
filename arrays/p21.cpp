#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int trees[], int log, int n, int m){

    long long int logSum = 0;
    for (int i = 0; i < n; i++){
        if (trees[i] > m){
            logSum += trees[i] - m;
        }
    }
    return logSum>=log;
}

int maxHeight(int trees[], int log, int n){
    int s = 0;
    int e = trees[n-1];
    int ans = -1;

    sort(trees, trees + n);

    while(s <= e){
        int m = s + (e - s) / 2;

        if(isPossible(trees, log, n, m)){
            ans = m;
            s = m + 1;
        }
        else{
            e = m - 1;
        }
    }

    return ans;
}

int main (){
    // int trees[] = {4, 42, 40, 26, 46};
    int trees[] = {4, 26, 40, 42, 46};
    int log = 20;
    int n = 5;

    cout << "max height: " << maxHeight(trees, log, n) << endl;

    return 0;
}