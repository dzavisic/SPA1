#include <iostream>
#include <vector>
using namespace std;

pair<int**, int**> LcsLength(vector<string> X, vector<string> Y){
    int m = X.size();
    int n = Y.size();
    int** b = new int*[m];
    for(int i=0; i<m; i++)
        b[i] = new int[n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            b[i][j] = 0;
    }
    int** c = new int*[m];
    for(int i=0; i<m; i++)
        c[i] = new int[n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            c[i][j] = 0;
    }
    for(int i=1; i<m; i++)
        c[i][0] = 0;
    for(int j=0; j<n; j++)
        c[0][j] = 0;
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(X[i] == Y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            } else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 2;
            }
        }
    }
    return make_pair(b, c);
}

void PrintLcs(int** b, vector<string> X, int i, int j){
    if(i==0 or j==0) {
        return;
    }
    if(b[i][j]==0){
        PrintLcs(b,X,i-1,j-1);
        cout << X[i] << "\t";
    } else if(b[i][j] == 1) {
        PrintLcs(b, X, i - 1, j);
    }
    else{
        PrintLcs(b,X,i,j-1);
    }

}

void PrintLcs1(vector<string> Y, int** b, int** c, int i, int j){
    int k=c[i][j]-1;
    string l[c[i][j]];
    while(c[i][j] != 0){
        if(b[i][j] == 0){
            l[k] = Y[j];
            i = i-1;
            j = j-1;
            k--;
        } else if(b[i][j] == 1)
            i-=1;
        else
            j-=1;
    }
    for(auto a : l)
        cout << a << "\t";
}

int main() {

    vector<string> X = {"","Z","N","C","B","D","A","B"};
    vector<string> Y = {"","B","D","C","A","K","A","B"};

    pair<int**, int**> p = LcsLength(X, Y);

    for(int i=0; i<X.size(); i++){
        for(int j=0; j<Y.size(); j++)
            cout << p.second[i][j] << "\t";
        cout << endl;
    }

    cout << "------------------------------------------\n";

    for(int i=0; i<X.size(); i++){
        for(int j=0; j<Y.size(); j++)
            cout << p.first[i][j] << "\t";
        cout << endl;
    }

    cout << "------------------------------------------\n";

    //PrintLcs(p.first, X, X.size()-1, Y.size()-1);
    PrintLcs1(Y, p.first, p.second, Y.size()-1, Y.size()-1);

    return 0;
}