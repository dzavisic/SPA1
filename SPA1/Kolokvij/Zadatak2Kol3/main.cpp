#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int values[n];
    int igraca = n/2;
    int karta;
    for(int i = 0; i<n; i++){
        cin >> karta;
        values[i]=karta;
    }
    int zbroj=0;
    for(int i=0; i<n; i++){
        zbroj = zbroj + values[i];
    }
    int wanted=zbroj/igraca;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(x!=y){
                if(values[x]+values[y]==wanted){
                    cout << x+1 << " " << y+1 << endl;
                    values[x]=0;
                    values[y]=0;
                }
            }
        }
    }
    return 0;
}
