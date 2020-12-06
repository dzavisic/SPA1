#include <bits/stdc++.h>

/*
2 3 -999999
-2 2 -3 4 -5 -999999
1 2 3 -999999
-2 2 -3 4 -5 -999999
-5 -3 4 1 -8 -999999
20 -3 4 1 -8 -999999
*/

using namespace std;

int main()
{
    vector<vector<int>> vec;
    vector<int> temp;
    int k=6;
    while(k>0){
        int unos;
        cin>>unos;
        if(unos==-999999){
            k--;
            vec.emplace_back(temp);
            temp.clear();
        }
        else{
            temp.emplace_back(unos);
        }
    }
    int br=0;
    int prod=1;
    int mini=INT_MAX;
    for(auto a:vec){
        br=0;
        for(auto x:a){
            if(x<0){
                br++;
            }
        }
        if(br%2==0){
            prod=1;
            for(auto x:a){
                prod=prod*x;
            }
            temp.push_back(prod);
            prod=1;
        }
        else{
            prod=1;
            mini=INT_MIN;
            for(auto x:a){
                if(x>mini && x<0){
                    mini=x;
                }
            }
            for(auto x:a){
                if(x!=mini){
                    prod=prod*x;
                }
            }
            temp.push_back(prod);
            prod=1;
            mini=INT_MIN;
        }
    }
    for(auto a:temp){
        cout << a << endl;
    }
    return 0;
}
