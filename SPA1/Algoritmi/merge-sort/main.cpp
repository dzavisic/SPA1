#include <iostream>
#include <limits>
using namespace std;

void Merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    cout << "n1 : " << n1 << ", n2: " << n2 << endl;
    int* L = new int [n1+1];
    int* R = new int [n2+1];
    for(int i=0; i<n1; i++) {
        L[i] = A[p + i];
        cout << L[i] << " li ";
    }
    for(int j=0; j<n2; j++) {
        R[j] = A[q + j + 1];
        cout << R[j] << " rj ";
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    cout << "p: " << p << ", r: " << r << endl;
    for(int k = p; k<=r; k++){
        cout << "k = " << k << ", p = " << p << ", r = " << r << endl;
        if(L[i] <= R[j]){
            cout << "LI :::: " << L[i] << endl;
            A[k] = L[i];
            cout << A[k] << " ak " << endl;
            i++;
        } else {
            cout << "RJ :::: " << R[j] << endl;
            A[k] = R[j];
            cout << A[k] << " ak " << endl;
            j++;
        }
    }
}

void MergeSort(int A[], int p, int r){
    if(p<r){
        cout << "prvi ---- p =" << p << ", r =" << r << endl;
        int q = floor((p+r)/2);
        cout << "drugi ---- " << "q = " << q << ", r: " << r << endl;
        MergeSort(A, p, q);
        cout << "treci ---- merge sort A,p,q --- p = " << p << ", q = " << q << ", r: " << r << endl;
        MergeSort(A, q+1, r);
        cout << "cetvrti ---- merge sort A,q+1,r --- q+1 = " << q+1 << ", r = " << r << endl;
        Merge(A, p, q, r);
        cout << "zadnji ---- merge A,p,q,r,  p = " << p << ", q = " << q << ", r = " << r << endl;
    }
}

int main() {

    int A[10] = {3, 54, 44, 21, 11, 5, 7, 22, 34, 276};
    MergeSort(A, 0, (size(A))-1);

    for(auto a : A)
        cout << a << " ";


    cout << endl;

    return 0;
}