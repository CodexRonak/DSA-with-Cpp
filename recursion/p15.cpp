#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int trees[], int n, int logs, int m, int logSum, int i){
    if(logSum >= logs){
        return true;
    }
    if(i == n){
        return false;
    }

    if(trees[i] > m){
        logSum += trees[i] - m;
        return isPossible(trees, n, logs, m, logSum, i + 1);
    }
    
    return isPossible(trees, n, logs, m, logSum, i + 1);
}

int maxHeight(int trees[], int n, int logs, int s, int e, int ans){
    int m = s + (e - s) / 2;

    if(s>e){
        return ans;
    }

    if(isPossible(trees, n, logs, m, 0, 0)){
        return maxHeight(trees, n, logs, m + 1, e, m);
    }
    else{
        return maxHeight(trees, n, logs, s, m - 1, ans);
    }
}

int main(){
    int n = 4;
    int logs = 7;
    int trees[] = {20, 15, 10, 17};
    sort(trees, trees + n);

    int s = 0;
    int e = trees[n - 1];

    cout << maxHeight(trees, n, logs, s, e, -1);
    return 0;
}