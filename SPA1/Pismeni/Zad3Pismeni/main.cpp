#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int k;
    vector<int> arr;
    cin >> n; cin >> k;
    for(int i=0; i<n; i++){
        int unos;
        cin>> unos;
        arr.push_back(unos);
    }
    int cijena=0;
    sort(arr.begin(), arr.end(), greater<int>());
    int arr2[n];
    for(int i=0; i<arr.size(); i++){
        arr2[i]=arr[i];
    }
    int priv=0;
    int ind=0;
    int t=1;
    while(n>0){
        if(priv<k){
            cijena=cijena+arr[ind];
            n--;
            ind++;
            priv++;
        }
        else{
            priv=0;
            t++;
            for(int i=0; i<arr.size(); i++){
                arr[i]=arr2[i];
            }
            for(int i=0; i<arr.size(); i++){
                arr[i]=arr[i]*t;
            }
        }

    }
    cout << cijena << endl;
    return 0;
}
