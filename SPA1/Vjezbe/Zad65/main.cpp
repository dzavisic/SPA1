#include <iostream>
#include <vector>
using namespace std;

vector<int> podniz(vector<int> vec){
    vector<int> vec2;
    int maks=0;
    int priv=0;
    for(int i=0; i<vec.size(); i++){
        if(i==vec.size()-1){
            if(vec[i]>vec[i-1]){
                vec2.push_back(vec[i]);
                priv++;
                if(maks<priv){
                    maks=priv;
                    return vec2;
                }
            }
        }
        else{
            if(vec[i]<vec[i+1]){
                vec2.push_back(vec[i]);
                priv++;
                if(priv>maks){
                    maks=priv;
                }
            }
            else{
                vec2.push_back(vec[i]);
                priv++;
                if(maks<priv){
                    maks=priv;
                }
                vec2.clear();
                priv=0;
            }
        }
    }
    for(int i=0; i<vec.size(); i++){
        if(vec[i]<vec[i+1]){
            vec2.push_back(vec[i]);
            priv++;
            if(priv>maks){
                maks=priv;
            }
        }
        else{
            vec2.push_back(vec[i]);
            priv++;
            if(maks==priv){
                return vec2;
            }
            if(maks<priv){
                maks=priv;
            }
            vec2.clear();
            priv=0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int br;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin >> br;
        vec.push_back(br);
    }
    for(auto a: podniz(vec)){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
