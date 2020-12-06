#include <iostream>
using namespace std;

int main() {

    int A[] = {5, 2, 4, 6, 1, 3};

    cout << "unsorted list: ";
    for(auto a : A)
        cout << a << " ";

    for(int j = 1; j<size(A); j++){
        int key = A[j];
        int i = j-1;
        while(i>=0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }

    cout << "\nsorted list: ";
    for(auto a : A)
        cout << a << " ";

    return 0;
}