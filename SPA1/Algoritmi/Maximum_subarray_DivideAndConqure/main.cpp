#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

tuple<int, int, int> FindMaxCrossingSubarray(vector<int> A, int low, int mid, int high){
    int leftSum = INT_MIN;
    int maxLeft;
    int sum = 0;
    for(int i=mid; i>low; i--){
        sum = sum + A[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum = INT_MIN;
    int maxRight;
    sum = 0;
    for(int j=mid+1; j<high; j++){
        sum = sum + A[j];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }
    return make_tuple(maxLeft, maxRight, leftSum+rightSum);
}

tuple<int, int, int> FindMaximumSubarray(vector<int> A, int low, int high){
    int mid;
    int leftLow, leftHigh, leftSum, rightLow, rightHigh, rightSum, crossLow, crossHigh, crossSum;
    if(high==low)
        return make_tuple(low, high, A[low]);
    else {
        mid = floor((low+high)/2);
        tuple<int, int, int> l = FindMaximumSubarray(A, low, mid);
        tuple<int, int, int> r = FindMaximumSubarray(A, mid+1, high);
        tuple<int, int, int> c = FindMaxCrossingSubarray(A, low, mid, high);

        tie(leftLow, leftHigh, leftSum) = l;
        tie(rightLow, rightHigh, rightSum) = r;
        tie(crossLow, crossHigh, crossSum) = c;
        cout << leftSum << "----" << rightSum << "----" << crossSum << endl;
        if(leftSum>=rightSum && leftSum>=crossSum)
            return make_tuple(leftLow, leftHigh, leftSum);
        else if(rightSum>=leftSum && rightSum>=crossSum)
            return make_tuple(rightLow, rightHigh, rightSum);
        else return make_tuple(crossLow, crossHigh, crossSum);
    }
}

int main() {

    vector<int> v = {-13,-3,-25,-20,-3,-16,-23,-18,-20,-7,-12,-5,-22,-15,-4,-7};
    int low, high, sum;
    tie(low, high, sum) = FindMaximumSubarray(v, 0, v.size()-1);

    cout << "Low: " << low << "\nHigh: " << high << "\nSum: " << sum << endl;


    return 0;
}