#include<iostream>
using namespace std;


int dishes(int rank[], int n, int dish, int m, int dishCount, int time, int chef, int multiplier){
    if(time + multiplier * chef > m){
        return dishCount;
    }

    return dishes(rank, n, dish, m, dishCount + 1, time + multiplier * chef, chef, multiplier + 1);
}

int totalDishes(int rank[], int n, int dish, int m, int dishCount, int time, int i, int totalDish){
    if(i==n){
        return totalDish;
    }
    int chef = rank[i];

    totalDish += dishes(rank, n, dish, m, dishCount, time, chef, 1);

    return totalDishes(rank, n, dish, m, 0, 0, i + 1, totalDish);
}

bool isPossible(int rank[], int n, int dish, int m){

    int totalDish = totalDishes(rank, n, dish, m, 0, 0, 0,0);

    if(totalDish >= dish){
        return true;
        
    }
    return false;
}

int minTime(int rank[], int n, int dish, int s, int e, int ans){
    int m = s + (e - s) / 2;

    if(s>e){
        return ans;
    }

    if(isPossible(rank, n, dish, m)){
        return minTime(rank, n, dish, s, m - 1, m);
    }
    else{
        return minTime(rank, n, dish, m + 1, e, ans);
    }
}

int main(){
    int rank[] = {1, 2, 3, 4};
    int n = 4;
    int dish = 11;
    int s = 0;
    int e = rank[n - 1] * (dish * (dish + 1) / 2);

    cout << minTime(rank, n, dish, s, e, -1) << endl;
    return 0;
}