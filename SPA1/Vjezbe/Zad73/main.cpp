#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    vector<char> vec;
    vector<char> vec2;
    while(b!=0){
        if(a>=b){
            vec.push_back('a');
            vec.push_back('b');
            a--; b--;
        }
        else if(a<b && a>0){
            while(a!=0){
                vec.push_back('a');
                vec.push_back('b');
                a--; b--;
            }
        }
        else{
            vec2.push_back('b');
            for(auto a:vec){
                vec2.push_back(a);
            }
            vec.clear();
            for(auto a:vec2){
                vec.push_back(a);
            }
            break;
        }
    }
    if(a>0 && c>0){
        while(c!=0){
            vec.push_back('a');
            vec.push_back('b');
            c--;
        }
        vec.push_back('a');
    }
    if(a==0 || b==0){
        while(c!=0){
            vec.push_back('a');
            vec.push_back('b');
            c--;
        }
    }
    int brojac=0;
    for(auto a : vec){
        cout << a << " ";
        brojac++;
    }
    cout << endl;
    cout << "Duljina: " << brojac << endl;
    return 0;
}
