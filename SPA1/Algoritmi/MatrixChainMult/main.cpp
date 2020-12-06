#include <iostream>
#include <vector>
using namespace std;

pair<int**, int**> MatrixChainMult(vector<int> v){
    int n=v.size();
    int **m = new int*[n];
    for(int i=0; i<=n; i++)
        m[i] = new int[n];
    int **s = new int*[n];
    for(int i=0; i<n; i++)
        s[i] = new int[n];
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++)
            m[i][j] = 0;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++)
            s[i][j] = 0;
    }
    int j,q;
    for(int i=1; i<n; i++){
        m[i][i] = 0;
    }
    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + v[i-1]*v[k]*v[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return make_pair(m, s);
}

void PrintOptimalParens(int** s, int i, int j){
    if(i==j)
        cout << "A" << i;
    else {
        cout << "(";
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {

    vector<int> v = {30,35,15,5,10,20,25};
    pair<int**, int**> p = MatrixChainMult(v);

    int n = v.size();
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++)
            cout << p.first[i][j] << "\t";
        cout << endl;
    }

    cout << "\n----------------------------------\n" << endl;

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++)
            cout << p.second[i][j] << "\t";
        cout << endl;
    }

    cout << "\n-----------------------------------\n" << endl;

    PrintOptimalParens(p.second, 1, 6);

    return 0;
}