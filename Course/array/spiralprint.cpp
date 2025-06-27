#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> &v,int row, int col){
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> spiralprint(vector<vector<int>> &matrix){
   
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while(count < total){

        for (int index = startingCol; index <= endingCol && count < total;index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        for (int index = startingRow; index <= endingRow && count < total;index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        for (int index = endingCol; index >= startingCol && count < total;index--){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        for (int index = endingRow; index >= startingRow && count < total;index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main(){
    vector<vector<int>> a(3,vector<int> (4));
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            cin >> a[i][j];
        }
    }
    print(a, 3, 4);
    vector<int> spiralorder = spiralprint(a);
    for (int i = 0; i < spiralorder.size();i++){
        cout << spiralorder[i] << " ";
    }
    return 0;
}