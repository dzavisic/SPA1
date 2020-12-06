#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int a = 0;
static int b = 1;

bool myFunction (pair<double, double> i, pair<double, double> j){
    return i.second > j.second;
}

vector<pair<double, double>> KnapsackFra(vector<double> weights, vector<double> values, float knapsack){
    vector<pair<double, double>> v;
    vector<pair<double, double>> vrati;
    for(int i=0; i<weights.size(); i++) {
        v.push_back(make_pair(weights[i], ((double)(values[i] / weights[i]))));
    }
    sort(v.begin(), v.end(), myFunction);
    int i=0;
    while(knapsack > 0){
        if(knapsack-v[i].first>=0){
            vrati.push_back(make_pair(v[i].first, ((double)(v[i].first*v[i].second))));
            knapsack = knapsack-v[i].first;
            i++;
        } else {
            vrati.push_back(make_pair(knapsack, ((double)(knapsack*v[i].second))));
            knapsack = -1;
        }
    }
    return vrati;
}

int main() {

    int knapsack = 50;
    vector<double> weights = {31, 31, 2};
    vector<double> values = {60, 100, 121};
    vector<pair<double, double>> v = KnapsackFra(weights, values, knapsack);
    double sum = 0;
    for(auto a : v){
        sum = sum + a.second;
        cout << "(" << a.first << ", " << a.second << ")" << "\t";
    }
    cout << "\nNajveca vrijednost: " << sum << endl;

    return 0;
}