#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack <pair<int,int>> s;
    stack <pair<int,int>> S;
    int maks=0;
    for(int i=0; i<n; i++){
        int unos; cin>>unos;
        if(unos>maks){
            maks=unos;
        }
        s.push(make_pair(unos,maks));
    }
    int m; cin >> m;
    if(m<n){
        while(m!=0){
            s.pop();
            m--;
        }
        if(s.empty()==false){
            cout << s.top().second << endl;
        }
    }
    else{
        cout << "X" << endl;
    }
    return 0;
}
