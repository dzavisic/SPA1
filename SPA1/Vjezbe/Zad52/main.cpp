#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int b, e;
    cin >> b; cin >> e;
    vector<char> vec;
    /*
    for(int i=0; i<b; i++){
        if(i%2!=0 || i==0){
            vec.push_back('B');
        }
        else{
            if(e>0){
                vec.push_back('E');
                e--;
            }
            else{
                vec.push_back('B');
            }
        }*/

    for(int i=0; i<b/2; i++){
        vec.push_back('B');
        vec.push_back('B');
        if(e>0){
            vec.push_back('E');
            e--;
        }
    }
    if(b%2!=0){
        vec.push_back('B');
    }
    while(e!=0){
        vec.push_back('E');
        e--;
    }
    for(auto a: vec){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
