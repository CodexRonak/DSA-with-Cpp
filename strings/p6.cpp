#include <iostream>
#include <string>
using namespace std;

char getMaxOccurence(string str){
    int temp[26] = {0};
    int n = str.length();

    for (int i = 0; i < n; i++){
        int idx = -1;
        if(str[i] >= 'a' && str[i] <= 'z'){
            idx = str[i] - 'a';
        }
        else{
            idx = str[i] - 'A';
        }
        temp[idx]++;
    }

    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++){
        if(temp[i] > maxi){
            maxi = temp[i];
            ans = i;
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){
    string str;
    cout << "enter your line" << endl;
    getline(cin, str);
    char output = getMaxOccurence(str);
    cout << output ;
    return 0;
}