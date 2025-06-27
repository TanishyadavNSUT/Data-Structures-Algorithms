#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //Unordered_Map is an efficient data structure which allows insertion, deletion and searching operations in O(1) time complexity.
    //Implemented using a hashtable
    //ordered map allows these operations in O(logn) time complexity. Implemented using binary search tree.

    unordered_map<string, int> map1;
    
    //insertion

    //method1
    pair<string, int> p1 = make_pair("tanish", 2);
    map1.insert(p1);

    //method2
    pair<string, int> p2("yadav", 3);
    map1.insert(p2);

    //method3
    map1["babbar"] = 4;

    //searching

    cout << map1["yadav"] << endl;
    cout << map1.at("tanish") << endl;

    //cout << map1.at("ray"); since this is not presnt, it will give error
    //but if this is directly accessed then it would have given 0.
    cout << map1["ray"] << endl;

    cout << map1.size() << endl;

    //count is used to check presence, give true if present otherwise false
    cout << map1.count("tanish") << endl;

    map1.erase("babbar");
    cout << map1.size() << endl;

    /*
    for(auto i: map1){
        cout<<i.first<<" "<<i.second;
    }
    */

    unordered_map<string, int>::iterator it = map1.begin();
    while(it!=map1.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}