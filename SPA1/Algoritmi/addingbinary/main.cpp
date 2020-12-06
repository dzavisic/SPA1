#include <iostream>
#include <list>
using namespace std;

int main() {

    int n;
    cout << "Unesite broj bitova za vasa dva broja: ";
    cin >> n;
    cout << "Unesite prvi n-bit binarni broj: " << endl;


    int numberA, numberB;
    list<int> A,B,C;
    cin >> numberA;

    while(numberA>0){
        A.push_front(numberA%10);
        numberA = numberA/10;
    }

    cout << "Unesite drugi n-bit binarni broj: " << endl;
    cin >> numberB;

    while(numberB>0){
        B.push_front(numberB%10);
        numberB = numberB/10;
    }

    int carry = 0;
    while(!A.empty()){
        int a = A.back();
        int b = B.back();
        A.pop_back();
        B.pop_back();
        if(a + b + carry == 0){
            C.push_front(0);
        } else if (a + b + carry == 1) {
            C.push_front(1);
        } else if (a + b + carry == 2) {
            carry = 1;
            C.push_front(0);
        } else if (a + b + carry == 3) {
            carry = 1;
            C.push_front(1);
        }
    }

    if(carry == 1)
        C.push_front(1);

    for(auto c : C)
        cout << c << " ";



    return 0;
}