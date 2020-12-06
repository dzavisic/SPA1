#include <iostream>
using namespace std;

int main() {

    int index;

    cout << "Unesite vrijednost: " << endl;
    cin >> index;

    int vrati;
    int A[] = {1, 34, 5, 76, 3, 23, 322, 4, 11};
    for(int i=0; i<size(A); i++){
        if(A[i] == index) {
            vrati = i;
            break;
        }else
            vrati = 0;
    }

    if(vrati == 0)
        cout << "Uneseni broj nije pronaden!" << endl;
    else
        cout << "Uneseni broj nalazi se na poziciji: " << vrati << endl;

    return 0;
}