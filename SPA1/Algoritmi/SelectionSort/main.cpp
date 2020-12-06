#include <iostream>
using namespace std;

int main()
{
    int arr[12] = {15,13,11,14,10,8,9,7,5,3,1,2};
    int temp=INT_MAX;
    int k;
    for(int i=0; i<11;i++){
        for(int j=i; j<12;j++){
            if(arr[j]<temp){
                temp=arr[j];
                k=j;
            }
        }
        arr[k]=arr[i];
        arr[i]=temp;
        temp=INT_MAX;
    }
    for(int i =0; i<12; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
