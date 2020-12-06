#include <bits/stdc++.h>
using namespace std;

int zabavni(priority_queue <int, vector<int>, greater<int>>pq){
    int tp=pq.top();
    pq.pop();
    int suma=tp+pq.top();
    pq.pop();
    vector<int> vec;
    vec.emplace_back(suma);
    while(!pq.empty()){
        suma=suma+pq.top();
        vec.emplace_back(suma);
        pq.pop();
    }
    int k=0;
    for(auto a:vec){
        k=k+a;
    }
    return k;
}

int main()
{
    priority_queue <int, vector<int>, greater<int>>pq;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int unos;
        cin >> unos;
        pq.push(unos);
    }
    cout << zabavni(pq) << endl;
    return 0;
}
