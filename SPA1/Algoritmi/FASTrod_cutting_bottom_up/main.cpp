#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BottomUpCutRod(vector<int> v, int n){
    int r[n];
    r[0] = 0;
    int q;
    for(int j=1; j<=n; j++){
        q = INT_MIN;
        for(int i=0; i<j; i++)
            q = max(q, v[i] + r[j-1-i]);
        r[j] = q;
    }
    return r[n];
}

int main() {

    vector<int> v = {2,7,8,9,10,17,17,20,24,30};
    int n = 5;
    int vrati = BottomUpCutRod(v, n);
    cout << "Najbolja cijena: " << vrati << endl;

    return 0;
}