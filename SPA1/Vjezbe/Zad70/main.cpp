#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minkal(vector<int> vec,int n){
    int suma=0;
    for(int i=0; i<n; i++){
        suma = suma + (pow(2,i))*(vec[i]);
    }
    return suma;
}

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    int unos;
    for(int i=0; i<n; i++){
        cin >> unos;
        vec.push_back(unos);
    }
    sort(vec.begin(), vec.end(), greater<int> ());
    cout << minkal(vec,n) << endl;
    return 0;
}
