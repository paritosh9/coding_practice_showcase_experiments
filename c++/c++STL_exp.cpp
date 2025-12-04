#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string>

using namespace std;

int main() {
    // Write C++ code here
    // stl set , map etc
    
    vector<int> vec = {2,5,6,7,-2,16};
    vec.push_back(44);
    
    for(auto i : vec){
        cout << i << " ";
    }
    
    
    set<int> s = {};
    s.insert(2);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(14);
    s.insert(8);
    
    cout << endl;
    for(auto i : s){
        cout << i << " ";
    }
    
    map<int, string> maps;
    maps.insert({1,"one"});
    maps.insert({5,"five"});
    maps.insert({3,"three"});
    cout << endl;
    for(auto [i,j] : maps){
        cout << i << " : " << j << endl;
    }
    
    cout << "3 at " << maps.at(3) << endl;
    
    map<string, int> maps2;
    maps2.insert({"one",1});
    maps2.insert({"five",5});
    maps2.insert({"three",3});
    cout << "three at " << maps2.at("three");
    cout << endl;
    
    
}
