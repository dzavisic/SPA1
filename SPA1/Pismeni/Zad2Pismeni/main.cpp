#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;
    stack<int> st;
    stack<int> pr;


    for(int i=0; i<n; i++){
        int unos; cin >> unos;
        st.push(unos);
    }
    stack<int> orig;

    for(int i=0; i<n; i++){
        int k=i+1;
        while(k>0){
            orig.push(st.top());
            st.pop();
            k--;
        }
        int fst = orig.top();
        bool t=false;
        while(!st.empty() && t!=true){
            if(st.top()>=fst){
                orig.push(st.top());
                st.pop();
                t=false;
            }
            else{
                pr.push(st.top());
                t=true;
            }
        }
        if(st.size()<=0){
            pr.push(-1);
        }
        while(!st.empty()){
            orig.push(st.top());
            st.pop();
        }
        while(!orig.empty()){
            st.push(orig.top());
            orig.pop();
        }

    }
    while(!pr.empty()){
        cout << pr.top() << " ";
        pr.pop();
    }
    cout << endl;
    return 0;
}
