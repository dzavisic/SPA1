#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MemoizedCutRodAux(vector<int>, int, int[]);

int MemoizedCutRod(vector<int> v, int n){
    int r[n];
    for(int i=0; i<n; i++)
        r[i] = INT_MIN;
    return MemoizedCutRodAux(v, n, r);
}

int MemoizedCutRodAux(vector<int> v, int n, int r[]){
    int q;
    if(r[n-1] >= 0)
        return r[n-1];
    if(n==0){
        q = 0;
    } else {
        q = INT_MIN;
        for(int i=0; i<n; i++)
            q = max(q, v[i] + MemoizedCutRodAux(v, n-i-1, r));
    }
    r[n-1] = q;
    return q;
}


int main() {

    vector<int> v = {2,7,8,9,10,17,17,20,24,30};
    int n=4;
    int vrati = MemoizedCutRod(v, n);
    cout << "Najbolja cijena: " << vrati << endl;

    return 0;
}