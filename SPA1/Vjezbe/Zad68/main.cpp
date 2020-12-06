#include <iostream>
using namespace std;

int count1( int S[], int m, int n )
{
    int i, j, x, y;
    int table[n + 1][m];
    for (i = 0; i < m; i++)
        table[0][i] = 1;

    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

            y = (j >= 1) ? table[i][j - 1] : 0;

            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int unos;
    int arr[m];
    for(int i=0; i<m;i++){
        cin >> unos;
        arr[i]=unos;
    }
    cout << count1(arr, m, n) << endl;
    return 0;
}
