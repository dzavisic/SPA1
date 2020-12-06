#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int suma(vector<int> vec){
    int broj=0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]<0){
            broj++;
        }
    }
    int temp=INT_MIN;
    if(broj==vec.size()){
        for(int i=0; i<vec.size(); i++){
            if(vec[i]>temp){
                temp= vec[i];
            }
        }
        return temp;
    }
    int maks=0;
    int tempMaks=0;
    for(int j=0;j<vec.size(); j++){
        if(vec[j]>=0){
            maks=maks+vec[j];
        }
        else{
            if(maks>0){
                if(maks+vec[j]<=maks/2){
                    if(maks>tempMaks){
                        tempMaks=maks;
                    }
                    if(vec[j+1]<=vec[j]){
                        maks=0;
                    }
                    else if(maks+vec[j]<maks/2){
                        maks=0;
                    }
                    else{
                        maks=maks+vec[j];
                    }
                }
                else{
                    maks=maks+vec[j];
                }
            }
            else{
                maks=0;
            }
        }
    }
    if(maks>tempMaks){
        tempMaks=maks;
    }
    return tempMaks;
}

int main()
{
    int n;
    cin >> n;
    int m;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin >> m;
        vec.push_back(m);
    }
    cout << suma(vec) <<endl;
    return 0;
}
