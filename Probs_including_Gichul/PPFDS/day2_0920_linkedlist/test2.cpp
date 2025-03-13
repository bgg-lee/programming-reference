#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
int main(){
    string s = "ABCD";
    cout << s << endl;
    reverse(s.begin(),s.end());
    cout << s << endl;

    vector<int> vec = {1,2,3,4,5,-1,100};

    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
    sort(vec.begin(),vec.end());
    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
    sort(vec.rbegin(),vec.rend());
    for(int i : vec){
        cout << i << " ";
    }
}