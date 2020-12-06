#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec;

priority_queue<int> fkja(priority_queue <int> g){
    int b = g.size();
    for(int i=0; i<5; i++){
        if(!g.empty()){
            vec.push_back(g.top());
            g.pop();
        }
    }
    return g;
}

int main()
{

    priority_queue <int> pq;
    for(int i=0; i<4; i++){
        int unos;
        cin >> unos;
        pq.push(unos);
    }
    pq=fkja(pq);

    for(int i=0; i<7; i++){
        int unos;
        cin >> unos;
        pq.push(unos);
    }
    pq=fkja(pq);

    for(int i=0; i<2; i++){
        int unos;
        cin >> unos;
        pq.push(unos);
    }
    pq=fkja(pq);
    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
