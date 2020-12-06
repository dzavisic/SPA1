#include <iostream>
using namespace std;

int main() {

    int A[10] = {50, 44, 34, 23, 3, 466, 42, 21, 45, 99};

    for(int i=0; i<size(A); i++){
        for(int j=size(A)-1; j>=i+1; j--){
            if(A[j]<A[j-1]){
                swap(A[j], A[j-1]);
            }
        }
    }

    for(auto a : A)
        cout << a << " ";

    return 0;
}