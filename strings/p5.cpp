// optimised soln 

#include <iostream>
#include <string>
using namespace std;

void revWord(string &str, int s, int e){
    string temp = "";
    while(s <= e){
        swap(str[s++], str[e--]);
    }
}

void revWordsInSentenece(string &str){
    int s = 0, n= str.length();

    for (int i = 0; i < n; i++){
        if(i == n - 1){
            revWord(str, s, i);
            s = i + 1;
        }else if(str[i] == ' '){
            revWord(str, s, i - 1);
            s = i + 1;
            }
        }
}


int main(){
    string str;
    cout << "enter your line" << endl;
    getline(cin, str);
    revWordsInSentenece(str);
    cout << str ;
    return 0;
}



// string revWord(string str){
//     int s = 0, e = str.length() - 1;
//     while(s <= e){
//         swap(str[s++], str[e--]);
//     }
//     return str;
// }

// string revWordSentence(string str){
//     string sen = "";
//     string word = "";
//     str = str + " ";
//     for (int i = 0; i < str.length(); i++){
//         if (str[i] != ' ' && str[i] != '\0'){
//             word.push_back(str[i]);
//         }
//         else{
//             string newWord = revWord(word);
//             word = "";
//             if(sen == ""){
//                 sen = newWord;
//             }
//             else{
//                 sen = sen + " " + newWord;
//             }
//         }
//     }
//     return sen;
// }

// int main(){
//     string str;
//     cout << "enter your line" << endl;
//     getline(cin, str);
//     string sen = revWordSentence(str);
//     cout << sen ;
//     return 0;
// }