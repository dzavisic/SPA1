#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> ActivitySel(vector<int> s, vector<int> f, int k, int n){
    int m=k+1;
    vector<pair<int, int>> v;
    while(m<=n and s[m]<f[k]) {
        m=m+1;
    }
    if(m<n) {
        v.push_back(make_pair(s[m], f[m]));
        ActivitySel(s, f, m, n);
    } else return v;
}

int main() {

    vector<int> s = {1,2,0,5,3,5,6,8,8,2,12};
    vector<int> f = {4,5,6,7,9,9,10,11,12,14,16};

    vector<pair<int, int>> v = ActivitySel(s, f, 0, f.size());
    for(auto a : v)
        cout << "(" << a.first << ", " << a.second << ")" << "\t";

    return 0;
}