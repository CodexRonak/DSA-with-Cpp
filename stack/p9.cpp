#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
  if(str.length() % 2 == 1){
    return -1;
  }

  stack<char> s;
  for(int i = 0; i < str.length(); i++){
    char ch = str[i];
    if(ch == '{'){
      s.push(ch);
    }
    else{  // ch == '}'
      if(!s.empty() && s.top() == '{'){
        s.pop();
      }
      else{
        s.push(ch);
      }
    }
  }

  int a = 0;  // '}' count
  int b = 0;  // '{' count

  while(!s.empty()){
    if(s.top() == '}'){
      a++;
    }
    else{
      b++;
    }
    s.pop();
  }

  return (a + 1) / 2 + (b + 1) / 2;
}

int main(){
  cout << findMinimumCost("{{{{") << endl;    // 2
  cout << findMinimumCost("}{") << endl;      // 2
  cout << findMinimumCost("{{}}") << endl;    // 0
  cout << findMinimumCost("}}}{{{") << endl;  // 4
  return 0;
}