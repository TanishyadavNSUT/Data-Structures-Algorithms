#include<iostream>
#include<vector>
using namespace std;

void waveprint(vector<vector<int>> &v, int row, int col){
    for (int j = 0; j < col;j++){
        if(j%2==0){
            for (int i = 0; i < row;i++){
                cout << v[i][j]<<" ";
            }
        }
        else{
            for (int i = row-1; i >=0;i--){
                cout << v[i][j]<<" ";
            }
        }
    }
}

void print(vector<vector<int>> &v, int row,int col){
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

    int main()
{
    vector<vector<int>> a(3, vector<int>(4));
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            cin >> a[i][j];
        }
    }
    print(a, 3, 4);
    waveprint(a, 3, 4);
    return 0;
}