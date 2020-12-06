#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int a = 0;
static int b = 1;

bool myFunction (pair<int, int> i, pair<int, int> j){
    return i.second > j.second;
}

int main() {

    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    vector<pair<int, int>> v;
    vector<float> ratio;
    for(int i=0; i<weights.size(); i++) {
        ratio.push_back(float(values[i] / weights[i]));
        v.push_back(make_pair(weights[i], ratio[i]));
    }
    sort(v.begin(), v.end(), myFunction);
    for(auto a : v)
        cout << "(" << a.first << ", " << a.second << ")" << "\t";

    return 0;
}