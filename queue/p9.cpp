#include <iostream>
#include <queue>
using namespace std;


int SumOfMinMax(int *arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    for (int i = 0; i < k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < n; i++){
        
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}


int main(){
    int n = 5;
    int arr[n] = {1, 3, -2, 0, 5};
    int k = 3;

    cout << SumOfMinMax(arr, n, k) << endl;

    return 0;
}