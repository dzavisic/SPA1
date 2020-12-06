#include <iostream>
#include <vector>
using namespace std;

int MaxSubarraySum(vector<int> v, int size){
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    int start, end, c = 0;
    for(int i=0; i<size; i++){
        maxEndingHere = maxEndingHere + v[i];
        if(maxEndingHere > maxSoFar){
            maxSoFar = maxEndingHere;
            start = c;
            end = i;
        }
        if(maxEndingHere < 0){
            maxEndingHere = 0;
            c = i + 1;
        }
    }
    cout << start << " ---- " << end << endl;
    return maxSoFar;
}

int main() {

    vector<int> v = {-2,-3,4,-1,-2,1,5,-3};
    int maxSum = MaxSubarraySum(v, v.size()-1);
    cout << "Max Sum: " << maxSum << endl;

    return 0;
}