#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> funkcija(vector<char> vec){
    vector<char> rev;
    int brojac=0;
    bool k=false;
    for(int i=0; i<int(vec.size()); i++){
        if(i==int(vec.size())-1){
            rev.push_back(vec[i]);
            k=true;
        }
        else{
            for(int j=i+1; j<int(vec.size());j++){
                if(vec[i]==vec[j]){
                    brojac=vec.size()-j;
                    rev.push_back(vec[i]);
                    while(brojac!=0){
                        vec.pop_back();
                        brojac--;
                    }
                    break;
                }
            }
        }
    }
    int siz;
    if(k==true){
        siz=rev.size()-1;
    }else{
        siz=rev.size();
    }
    for(int i = siz-1; i>-1; i--){
        rev.push_back(rev[i]);
    }
    cout << "Size of palindrom: " << rev.size() << endl;
    cout << "Palindrom: ";
    return rev;
}

int main()
{
    string rj;
    vector<char> vec;
    cin >> rj;
    for(int i=0; i<int(rj.length()); i++){
        vec.push_back(rj[i]);
    }
    for(auto a: funkcija(vec)){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
