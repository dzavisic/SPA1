#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n, k;
    cin >> n; //broj stabljika
    cin >> k; //broj ubiranja
    int lista[n];
    for(int i=0; i<n; i++){
        int raj;
        cin >> raj;
        lista[i] = raj;
    }
    int maks=0;
    int ubrano=0;
    for(int i=0; i<k; i++){
        maks = 0;
        for(int j=0; j<n; j++){
            if(lista[j]>maks)
                maks=lista[j];
        }
        for(int j=0; j<n; j++){
            if(lista[j]==maks){
                ubrano = ubrano + lista[j];
                lista[j] = floor(lista[j] / 2);
                break;
            }
        }
    }
    cout << ubrano << endl;
    return 0;
}
