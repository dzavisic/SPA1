#include <iostream>
using namespace std;

long long int q = 0;
long long int r[1000];


long long int Fibonacci(int n){
    if(r[n] >= 0)
        return r[n];
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else{
        q = Fibonacci(n-1) + Fibonacci(n-2);
    }
    r[n] = q;
    return r[n];
}

int main() {

    for(int i=0; i<1000; i++){
        r[i] = -1;
    }
    cout << Fibonacci(240) << endl;

    return 0;
}