#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int dva; cin >> dva;
    int slatkisi[n];
    int secer[n];

    for(int i=0;i<n;i++)
        cin >> slatkisi[i];

    sort(slatkisi,slatkisi+n);

    for(int i=0;i<n;i++)
        secer[i]=0;

    for(int i=0; i<n; i++){
        int m=1;
        int d=1;
        for (int j=i;j>=0;j--){
            secer[i]+=slatkisi[j]*m;
            d++;
            if((d>2)&& d%2==1){
                m++;
            }
        }
    }

    for(int i=0; i<n; i++)
        cout << secer[i] << " ";
}
