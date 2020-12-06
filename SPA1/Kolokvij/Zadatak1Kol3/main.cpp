#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Magicni(string rijec){
    int velicina = rijec.length();
    if(rijec[0]!='1'){
        return false;
    }
    int counter = 0;
    for(int i=1; i < velicina; i++){
        if(rijec[i]!='1' && rijec[i]!='4'){
            return false;
        }
        if(rijec[i]=='1'){
            counter=0;
        }
        if(rijec[i]=='4'){
            counter++;
        }
        if(counter >= 3){
            return false;
        }
    }
    return true;
}


int main()
{
    int n; //broj testnih slucajeva
    cin >> n;
    string unos;
    vector<string> vec;
    for(int i = 0; i < n; i++){
        cin >> unos;
        vec.push_back(unos);
    }
    for(int i = 0; i<n; i++){
        string rijec;
        rijec = vec[i];
        if(Magicni(rijec)==true){
            cout << "DA" << endl;
        }
        else{
            cout << "NE" << endl;
        }
    }
    return 0;
}
