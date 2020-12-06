#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> kombinacije (const vector<vector<int>>& A){
    vector<vector<int>> novi = {{}};
    for(const auto& u : A){
        vector<vector<int>> r;
        for(const auto& x : novi){
            for(const auto y : u){
                r.push_back(x);
                r.back().push_back(y);
            }
        }
        novi = move(r);
    }
    return novi;
}
int main()
{
    int n; //broj elem u polju A
    cin >> n;
    vector<vector<int>> A;
    vector<int> B;
    int br;
    for(int i=0; i<n; i++){
        cin >> br;
        for(int x=0; x<br; x++){
            B.push_back(x+1);
        }
        A.push_back(B);
        B.clear();
    }
    vector<int> suma;
    int priv=0;
    for(auto a : kombinacije(A)){
        for(int i=1; i<int(a.size()); i++){
            priv = priv + abs(a[i]-a[i-1]);
        }
        suma.push_back(priv);
        priv=0;
    }
    int maks=INT_MIN;
    for(auto b:suma){
        if(b > maks){
            maks = b;
        }
    }
    cout << maks << endl;
    return 0;
}
