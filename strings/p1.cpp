#include <iostream>
using namespace std;

int length(char var[]){
    int count = 0;
    for (int i = 0; var[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(){
    char name[20];
    cout << "Enter " << endl;
    cin >> name;
    
    cout<<"the length is "<<length(name);
    return 0;
}