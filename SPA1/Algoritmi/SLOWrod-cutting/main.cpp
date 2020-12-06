#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int r[1000];
int s[1000];

int z;
int CutRod(vector<int> v, int n){
    int q;
    if(r[n] >= 0)
        return r[n];
    if(n==0)
        return 0;
    else{
        q = INT_MIN;
        for(int i=0; i<n; i++) {
            z = (v[i]/(i+1))+CutRod(v, n - 1 - i);
            if(q<z){
                q = z;
                s[n] = i+1;
            }
        }
    }
    r[n] = q;
    return r[n];
}

int main() {

    vector<int> v={1,20,33,36};
    int n=4;

    for(int i=0; i<n+1; i++)
        r[i] = INT_MIN;

    int vrati = CutRod(v,n);
    cout << "najbolja cijena: " << vrati << endl;

    for(int i=1; i<n+1; i++)
        cout << s[i] << " ";

    return 0;
}