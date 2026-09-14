#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<int>> &matrix, int n, vector<vector<int>> visited, int newx, int newy){
    if((newx >=0 && newx < n) && (newy >=0 && newy < n) && visited[newx][newy] == 0 && matrix[newx][newy] == 1){
        return true;
    }
    return false;
}

void ratInaMatrix(vector<vector<int>> &matrix, int n, vector<vector<int>> &visited, vector<string> &ans, string path, int x, int y){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    int newx = x + 1;
    int newy = y;

    if(check (matrix,n, visited, newx, newy)){
        path.append("D");
        ratInaMatrix(matrix, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    newx = x;
    newy = y - 1;

    if(check (matrix, n, visited, newx, newy)){
        path.append("L");
        ratInaMatrix(matrix, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    newx = x;
    newy = y + 1;

    if(check (matrix, n, visited, newx, newy)){
        path.append("R");
        ratInaMatrix(matrix, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    newx = x - 1;
    newy = y;

    if(check (matrix, n, visited, newx, newy)){
        path.append("U");
        ratInaMatrix(matrix, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main(){
    vector<vector<int>> matrix = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans;
    string path = "";
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (matrix[0][0] == 0 || matrix[n - 1][n - 1] == 0) {
        return 0;
    }

    ratInaMatrix(matrix, n, visited, ans, path, 0, 0);

    for (const string& p : ans) {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}