#include <iostream>
#include <vector>
using namespace std;

pair<int*, int*> ExtendedBottomUpCutRod(vector<int> v, int n){
    int q;
    int *r = new int[n+1];
    int *s = new int[n+1];
    r[0] = 0;
    for(int j=1; j<=n; j++){
        q = INT_MIN;
        for(int i=0; i<j; i++){
            if(q<v[i] + r[j-i-1]){
                q = v[i] + r[j-i-1];
                s[j] = i+1;
            }
            r[j] = q;
        }
    }
    return make_pair(r, s);
}

int main() {

    vector<int> v={2,7,8,9,10,17,17,20,24,30};
    int n = 8;
    pair<int*, int*> p = ExtendedBottomUpCutRod(v, n);
    for(int i=1; i<n+1; i++)
        cout << i << "\t";
    cout << endl;

    for(int i=1; i<n+1; i++){
        cout << p.first[i] << "\t";
    }
    cout << endl;
    for(int i=1; i<n+1; i++){
        cout << p.second[i] << "\t";
    }

    return 0;
}