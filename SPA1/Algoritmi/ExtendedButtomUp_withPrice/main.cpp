#include <iostream>
#include <vector>
using namespace std;

pair<int*, int*> ExtendedButtomUpWithPrice(vector<int> v, int n){
    int q;
    int *r = new int[n+1];
    int *s = new int[n+1];
    int *k = new int[n+1];
    r[0] = 0;
    for(int j=1; j<=n; j++){
        q = INT_MIN;
        for(int i=0; i<j; i++){
            if(q < v[i] + r[j-i-1]){ //(v[i]/(i+1)) value slucaj
                q = v[i] + r[j-i-1]; //(v[i] - p[i]) cost slucaj
                s[j] = i+1;
            }
        }
        r[j] = q;
    }
    int x = n;
    int l = 1;
    while(x>0){
        k[l] = s[x];
        x = x - s[x];
        l += 1;
    }
    k[0] = l-1;
    return make_pair(r, k);
}

int main() {

    vector<int> v={2,5,8,9,10,17,17,20,24,30};
    int n = 9;
    pair<int*, int*> p = ExtendedButtomUpWithPrice(v, n);
    for(int i=1; i<n+1; i++)
        cout << i << "\t";
    cout << endl;

    for(int i=1; i<n+1; i++){
        cout << p.first[i] << "\t";
    }
    cout << endl;
    cout << p.second[0] << " puta presjecen na duljinama: ";
    for(int i=1; i<=p.second[0]; i++){
        cout << p.second[i] << "\t";
    }

    return 0;
}