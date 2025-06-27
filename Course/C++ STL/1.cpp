/*STL refers to standard template library of c++. it allow access to vast 
library for generic functions which makes code easier, like sort, max, min functions*/

#include<bits/stdc++.h>   //will include most libraries
using namespace std;

void explainvector(){

    vector<int> v;   //vector is a dynamic array, can increase it's size when required
    v.push_back(1);
    v.emplace_back(2);  //similar function to push back

    vector<int> v1(5, 20);  //creates a vector of size 5 with all values 20
    cout << v1[0];
    
    // *(it) this will return value placed at address it.

    vector<int>::iterator it = v.begin();  //v.begin() gives value of address of start of v
    vector<int>::iterator it = v.end();   //end will point to address next to address of last element
    cout << v.back();  //gives last element of vector

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){ //to print the vector
        cout << *(it);
    }

    for (auto it = v.begin(); it != v.end();it++){ //auto will automatically assign value it according to it's data type 
        cout << *(it);
    }

    v.erase(v.begin()); //deletes element at begin
    v.erase(v.begin(), v.begin() + 2); //deletes elements from starting to ending index [start,end)

    vector<int> v(2, 100); //{100,100}
    v.insert(v.begin(), 300);  //{300,100,100}
    v.insert(v.begin()+1, 2, 10); //{300,10,10,100,100}

    cout << v.size();  //give size of vector

    v.pop_back();  //deletes last element of vector

    v.clear(); //clear the vector to an empty vector

    v.empty(); //return bool value if vector is empty or not

    v1.swap(v2); //swaps vector v1 to v2
}

void explainlist(){

    list<int> ls; //allows cheaper insertion at front using direct function, in respect with vector

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.empalce_front(4);
}

void explainDeque(){  //double ended queue

    deque<int> dq;
    dq.push_back(2);
    dq.emplace_back(3);
    dq.push_front(4);
    dq.emplace_front(6);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
}

void explainStack(){

    stack<int> st;
    st.push(1);
    st.emplace(2);

    cout << st.top(); //prints top element

    st.pop();
    st.size();
    st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue(){

    queue<int> q;
    q.push(1);
    q.emplace(2);
    q.pop();

    q.back() += 5;
    q.front();
}

void explainPriority_queue(){ //largest element has highest priority

    priority_queue<int> pq;
    pq.push(1);
    pq.emplace(10);
    pq.top();
    pq.pop();

    priority_queue<int, vector<int>, greater<int>> pq; //priority queue with smallest element having largest priority
}

void explainSet(){ //stores unique items in sorted order

    set<int> st;
    st.insert(1);
    st.emplace(2);

    auto it = st.find(2); //returns address of 2
    auto it = st.find(6); //since 6 is not present in the set. it will return address off end 

    st.erase(5);
    st.erase(it1, it2); //erases [it1,it2)

    int cnt = st.count(1); //since set only has unique elements. count will be 1 if element is present otherwise 0
}

void explainMultiset(){ //set having ordered duplicate values

    multiset<int> st;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.erase(1);  //all ones will be deleted
    ms.erase(ms.find(1)); //only single 1 will be deleted since address of only one 1 is passed 
}

void explainUset(){ //set having only unique unordered values

    unordered_set<int> us;
}

void explainMap(){ //key value pairs. keys are unique and sorted while values can repeat. each key is mapped to some value
    map<int, int> mpp;
    mpp[1] = 2;
    mpp.emplace({3, 1});

    for(auto it:mpp){
        cout << it.first << " " << it.second << endl;
    }
    cout << mpp[1]; //return value with key 1

    auto it = mpp.find(2); //address of 2
}

//multimap , map can have multiple keys 
//Unordered map, unique unsorted keys

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first>p2.first) return true;
    return false;
}

void explainExtra(){

    sort(v.begin(), v.end());
    sort(a + 2, a + 4);  //sorts  only elements of specified indexes
    sort(a, a + 2, greater<int>); //sorts in descending order

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}}; // we want to sort it according to our own way 

    //let's define a comparator for this
    //sort according to second element , if second elements are same then sort according to first element in descending order

    sort(a, a + n, comp);
}