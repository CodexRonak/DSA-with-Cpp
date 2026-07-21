// 567. Permutation in String
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkStrPermutation(string s1, string s2){
    // for storing str data
    vector<int> s1Count(26, 0);
    vector<int> s2Count(26, 0);

    int n1 = s1.length();
    int n2 = s2.length();

    // creating a window using s2
    for (int i = 0; i < n2; i++){
        s1Count[s1[i] - 'a']++;
        s2Count[s2[i] - 'a']++;
    }

    if(s1Count==s2Count) return true;

    // sliding the window
    for (int i = n2; i < n1; i++){
        s1Count[s1[i] - 'a']++;
        s1Count[s1[i - 1] - 'a']--;
        if(s1Count==s2Count) return true;
    }
    return false;
}


int main(){
    string s1 = "eidboaooo", s2 = "ab";
    if(checkStrPermutation(s1, s2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}