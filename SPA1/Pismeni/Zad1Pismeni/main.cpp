#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node(float a, float b, float c, float d, float e) :
        a(a), b(b), c(c), d(d), e(e) { }
    float a, b, c, d, e;
};

void sort(vector<Node>& V)
{
    int suma=0;
    vector<pair<int, int>> vec;
    for(int i=0; i<int(V.size()); i++){
        suma=V[i].a+V[i].b+V[i].c+V[i].d+V[i].e;
        vec.emplace_back(make_pair(suma, i));
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<int(V.size()); i++){
        cout << V[vec[i].second].a << " " << V[vec[i].second].b << " " << V[vec[i].second].c << " " << V[vec[i].second].d << " " << V[vec[i].second].e << endl;
    }
}

int main()
{
    int unos;
    int arr[5];
    vector<Node> vec;
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            cin>>unos;
            arr[j]=unos;
        }
        Node N(arr[0],arr[1],arr[2],arr[3],arr[4]);
        vec.emplace_back(N);
    }
    sort(vec);
    return 0;
}
