#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int cows, int n, int m){

    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; i++){
        if(stalls[i] - lastPos >= m){
            cowCount++;
            if(cowCount==cows){
                return true;
            }
            lastPos = stalls[i];
        }
    }

    return false;
}

int maxDistance(int stalls[], int cows, int n){
    int s = 0;
    int maxi = -1;
    int ans = -1;
    sort(stalls, stalls + n);
    

    for (int i = 0; i < n; i++){
        maxi = max(maxi, stalls[i]);
    }

    int e = maxi;
    
    while(s<=e){
        int m = s + (e - s) / 2;
        if(isPossible(stalls, cows, n, m)){
            s = m + 1;
            ans = m;
        }
        else{
            e = m - 1;
        }
    }
    return ans;
}

int main(){

    int stalls[] = {1, 2, 3, 4, 6};
    int cows = 2;
    int n = 5;

    cout <<"the maximum closest distance: "<< maxDistance(stalls, cows, n) << endl;
    return 0;
}