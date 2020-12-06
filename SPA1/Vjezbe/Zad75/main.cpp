#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int m; cin >> m;

    int buket[n];
    for(int i=0; i<n; i++)
        cin >> buket[i];
    sort(buket, buket+n);

    int buket2[n];
    for(int i=1; i<=n; i++)
        buket2[i]=buket[n-i];

    int j = 1;
    int suma = 0;
    for(int i=1;i<=n;i++){
        suma = suma+(buket2[i]*j);
        cout << "cijena: " << buket2[i] <<"    j: " <<j << endl;
        if(i%m==0){
            j++;
        }
    }
    cout << suma << endl;
}
