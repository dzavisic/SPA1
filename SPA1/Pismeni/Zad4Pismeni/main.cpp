#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<vector<int>> mat;
    vector<int> priv;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int unos; cin>> unos;
            priv.push_back(unos);
        }
        mat.push_back(priv);
        priv.clear();
    }
    int duljina=0;
    for(int i=0; i<n; i++){
        if(i==0){
            if(abs(mat[0][0]-mat[0][1])=1){
                duljina = duljina+1;
            }
            else if(mat[i][i]-mat[i+1][i]=1 || mat[i+1][i]-mat[i][i]=1){
                duljina=duljina+1;
            }
        }
    }
    cout << duljina << endl;
    return 0;
}
