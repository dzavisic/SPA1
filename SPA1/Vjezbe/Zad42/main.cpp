#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int fastPow(int x, int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        return ((fastPow(x,y/2))*(fastPow(x,y/2)));

    }else{
        return (x*(fastPow(x,y-1)));
    }
}


int main()
{
    vector<int> Parovi;
    int a;
    int b;
    for(int i=0; i<1; i++){
        cin >> a;
        cin >> b;
        Parovi.push_back(fastPow(a, b));
    }
    for(auto a : Parovi){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
