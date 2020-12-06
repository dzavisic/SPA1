#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> ActivitySel(vector<int> s, vector<int> f, int k, int n){
    k = k-1;
    vector<pair<int, int>> v;
    v.push_back(make_pair(s[0], f[0]));
    for(int i=1; i<n; i++){
        if(f[k]<=s[i]){
            v.push_back(make_pair(s[i],f[i]));
            k=i;
        }
    }
    return v;
}

int main() {

    vector<int> s = {1,3,0,5,3,5,6,8,8,2,12};
    vector<int> f = {4,5,6,7,9,9,10,11,12,14,16};

    vector<pair<int, int>> v = ActivitySel(s, f, 1, f.size());
    for(auto a : v)
        cout << "(" << a.first << ", " << a.second << ")" << "\t";

    return 0;
}