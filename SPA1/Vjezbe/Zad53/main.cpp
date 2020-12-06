#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string removeMinus(string str)
{
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    if(str.size()==7){
        str.resize(8);
        str[7]=str[6];
        str[6]=str[5];
        str[5]=str[4];
        str[4]=str[3];
        str[3]='-';
    }
    //cout << str.size() << endl;
    return str;
}

int main()
{
    int n; cin >> n;
    vector<string> vec1;
    bool prov;
    for(int i=0; i<n; i++){
        string unos;
        cin >> unos;
        for(int j=0; j<unos.size(); j++){
                if(unos[j]=='A' || unos[j]=='B' || unos[j]=='C'){
                    unos[j]='2';
                }
                if(unos[j]=='D' || unos[j]=='E' || unos[j]=='F'){
                    unos[j]='3';
                }
                if(unos[j]=='G' || unos[j]=='H' || unos[j]=='I'){
                    unos[j]='4';
                }
                if(unos[j]=='J' || unos[j]=='K' || unos[j]=='L'){
                    unos[j]='5';
                }
                if(unos[j]=='M' || unos[j]=='N' || unos[j]=='O'){
                    unos[j]='6';
                }
                if(unos[j]=='P' || unos[j]=='R' || unos[j]=='S'){
                    unos[j]='7';
                }
                if(unos[j]=='T' || unos[j]=='U' || unos[j]=='V'){
                    unos[j]='8';
                }
                if(unos[j]=='W' || unos[j]=='X' || unos[j]=='Y'){
                    unos[j]='9';
                }
                else{
                    unos[j]=unos[j];
                }
            }
        //cout << unos.size() << endl;
        if(unos.size()>8){
            vec1.push_back(removeMinus(unos));
        }else{
        if(unos.size()==7){
            unos.resize(8);
            unos[7]=unos[6];
            unos[6]=unos[5];
            unos[5]=unos[4];
            unos[4]=unos[3];
            unos[3]='-';
        }
        vec1.push_back(unos);
        }
    }
    sort(vec1.begin(), vec1.end());
    vector<pair<string,int>> vec2;
    int brojac=0;
    bool t=true;
    for(int i=0; i<vec1.size(); i++){
        string priv=vec1[i];
        for(int j=0; j<vec1.size(); j++){
            if(priv==vec1[j]){
                brojac++;
            }
        }
        if(brojac>1){
            for(auto a:vec2){
                if(a.first==priv){
                    t=false;
                }
            }
            if(t==true) {
                vec2.push_back(make_pair(priv, brojac));
            }
        }
        t=true;
        brojac=0;
    }
    for(int i=0; i<vec2.size();i++){
        for(int j=i+1; j<vec2.size();j++){
            if(vec2[i].first==vec2[j].first){
                vec2.erase(vec2.begin()+j);
            }
        }
    }
    for(int i=0; i<vec2.size(); i++){
        cout << vec2[i].first << " " << vec2[i].second << endl;
    }
    return 0;
}
