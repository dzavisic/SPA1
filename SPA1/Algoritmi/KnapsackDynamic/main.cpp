#include <iostream>
#include <vector>
using namespace std;

void KnapsackDyn(vector<int> weights, vector<int> values, int knapsack){
    int size = weights.size();
    int** m = new int*[size+1];
    for(int i=0; i<size+1; i++)
        m[i] = new int[knapsack+1];
    for(int i=0; i<4; i++){
        for(int j=0; j<51; j++){
            m[i][j] = 0;
        }
    }

    int i, w;
    for(i=0; i<=size; i++){
        for(w=0; w<=knapsack; w++){
            if(i==0 || w==0) {
                m[i][w] = 0;
            }
            else if(weights[i-1]<=w)
                m[i][w] = max((values[i-1] + m[i-1][w-weights[i-1]]), m[i-1][w]);
            else
                m[i][w] = m[i-1][w];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<51; j++)
            cout << m[i][j] << ",";
        cout << endl;
    }

}

int main() {

    int knapsack = 50;
    vector<int> weights = {5, 20, 30};
    vector<int> values = {60, 100, 120};

    KnapsackDyn(weights, values, knapsack);

    return 0;
}