#include <iostream>
#include <vector>
using namespace std;

int bomboni(vector<pair<int, int>> vec){
    for(int i=0; i<int(vec.size()); i++){
        if(i==0){
            if(vec[i].first<=vec[i+1].first){
                vec[i].second=1;
            }
            else{
                vec[i].second=2;
            }
        }
        else if(i==int(vec.size())-1){
            if(vec[i].first<=vec[i-1].first){
                vec[i].second=1;
            }
            else{
                vec[i].second= vec[i-1].second+1;
            }
        }
        else{
            if(vec[i].first<vec[i+1].first && vec[i].first<vec[i-1].first){
                vec[i].second=1;
            }
            else if(vec[i].first<vec[i+1].first && vec[i].first > vec[i-1].first || vec[i].first==vec[i+1].first && vec[i].first>vec[i-1].first){
                vec[i].second=vec[i-1].second+1;
            }
            else if(vec[i].first>vec[i+1].first && vec[i].first < vec[i-1].first){
                vec[i].second=2;
            }
            else if((vec[i].first==vec[i-1].first && vec[i].first==vec[i+1].first) || (vec[i].first==vec[i-1].first && vec[i].first<vec[i+1].first) || (vec[i].first==vec[i+1].first && vec[i].first<vec[i-1].first)){
                vec[i].second=1;
            }
            else{
                vec[i].second=vec[i-1].second+1;
            }
        }
    }
    int brojac=0;
    for(int i=0;i<int(vec.size());i++){
        brojac=brojac+(vec[i].second);
        cout << "(" << vec[i].first << ", " << vec[i].second << ") ";
    }
    cout << endl;
    return brojac;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    int unos;
    for(int i=0; i<n; i++){
        cin >> unos;
        vec.push_back(make_pair(unos, 0));
    }
    cout << bomboni(vec) << endl;
    return 0;
}
