#include <iostream>
#include <vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < cost.size(); i++) {
        balance += gas[i] - cost[i];

        if (balance < 0) {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0) return start;
    else return -1;
}

int main() {
    int n;

    cout << "No. of Stations: ";
    cin >> n;

    vector<int> gas(n), cost(n);

    cout << "Gas: ";
    for (int i = 0; i < n; i++) cin >> gas[i];

    cout << "Cost: ";
    for (int i = 0; i < n; i++) cin >> cost[i];

    int res = startStation(gas, cost);

    cout << "Starting station: " << res << endl;

    return 0;
}