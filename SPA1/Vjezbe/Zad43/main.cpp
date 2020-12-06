#include <iostream>
using namespace std;

//rekurzivno
int fibonaci(int n){
    if(n<=1){
        return n;
    }
    return fibonaci(n-1)+fibonaci(n-2);
}
//dinamicki
int fibonacci(int n){
    int f[n+2];
    int i;
    f[0]=0;
    f[1]=1;
    for(i = 2; i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    cout << "Rekurzivno: " << fibonaci(n) << endl;
    cout << "Dinamicko: " << fibonacci(n) << endl;
    return 0;
}
