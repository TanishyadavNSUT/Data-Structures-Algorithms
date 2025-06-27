#include<iostream>
#include<vector>
using namespace std;

void rotatearray(vector<int> &nums, int k){ //&nums means vector passed by reference or address. any changes made will reflect in original vector.

    int n = nums.size();
    vector<int> temp(n);

    for (int i = 0; i < n;i++){
        temp[(i + k) % n] = nums[i];
    }
    for (int i = 0; i < n;i++){
        nums[i] = temp[i];
    }
}

void printarray(vector<int> v){
    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    rotatearray(a,1);
    printarray(a);
}
