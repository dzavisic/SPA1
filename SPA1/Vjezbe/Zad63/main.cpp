#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = n;
    int brojac=0;
    while(k!=0){
        while(k>=50){
            k=k-50;
            brojac++;
        }
        while(k>=20){
            k=k-20;
            brojac++;
        }
        if(k>=10){
            k=k-10;
            brojac++;
        }
        if(k>=5){
            k=k-5;
            brojac++;
        }
        while(k>=2){
            k=k-2;
            brojac++;
        }
        if(k>=1){
            k=k-1;
            brojac++;
        }
    }
    cout << brojac << endl;
    return 0;
}
