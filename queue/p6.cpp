#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string firstNonRepeating(string &s) {
    int n = s.length();
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        count[ch]++;
        q.push(ch);

        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            ans.push_back('#');
        } else {
            ans.push_back(q.front());
        }
    }
    return ans;
}

int main() {
    string s;

    cout << "String daalo: ";
    cin >> s;

    string res = firstNonRepeating(s);

    cout << "Result: " << res << endl;

    return 0;
}