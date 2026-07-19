// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".
// Example 2:

// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".
 

// Constraints:

// 1 <= s.length <= 1000
// 1 <= part.length <= 1000
// s​​​​​​ and part consists of lowercase English letters.



#include <iostream>
#include <string>
using namespace std;

string removeStr(string str, string part){
    string ans = "";
    int n = str.length();
    int m = part.length();

    for (int i = 0; i < n; i++){
        ans.push_back(str[i]);

        if(ans.length()>=part.length() && ans.compare(ans.length() - m, m, part) == 0){
            int times = m;
            while(times--){
                ans.pop_back();
            }
        }
    }
    return ans;
}


int main(){
    string str, part;
    cout << "enter your string" << endl;
    cin >> str;
    cout << "enter your part" << endl;
    cin >> part;
    string output = removeStr(str, part);
    cout << output ;
    return 0;
}