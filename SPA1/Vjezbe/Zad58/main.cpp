#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    queue<int> q;
    stack<int> s;
    priority_queue<int> p;
    vector<bool> k;
    vector<bool> vecq;
    vector<bool> vecs;
    vector<bool> vecp;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a;
        if(a==1){
            cin >> b;
            q.push(b);
            s.push(b);
            p.push(b);
            vec.push_back(b);
        }
        else if(a==2){
            cin>> b;
            bool t=false;
            for(auto a:vec){
                if(a==b){
                    t=true;
                }
            }
            if(t==true){
                if(q.front()==b){
                    vecq.push_back(true);
                    k.push_back(true);
                    q.pop();
                }
                else{
                    vecq.push_back(false);
                    k.push_back(false);
                }
                if(s.top()==b){
                    vecs.push_back(true);
                    k.push_back(true);
                    s.pop();
                }
                else{
                    vecs.push_back(false);
                    k.push_back(false);
                }
                if(p.top()==b){
                    vecp.push_back(true);
                    k.push_back(true);
                    p.pop();
                }else
                {
                    vecp.push_back(false);
                    k.push_back(false);
                }
                int brojac=0;
                for(int i=k.size()-1; i<k.size()-4; i--){
                    if(k[i]==false){
                        brojac++;
                    }
                }
                if(brojac==3){
                    cout << "neodlucno" << endl;
                    return 0;
                }
            }
            else{
                cout << "nemoguce" << endl;
                return 0;
            }
        }
    }
    int brojacq=0;
    int brojacs=0;
    int brojacp=0;
    for(auto a:vecq){
        if(a==true){
            brojacq++;
        }
        if(brojacq==vecq.size()){
            cout << "red" << endl;
            return 0;
        }
    }
    for(auto a:vecs){
        if(a==true){
            brojacs++;
        }
        if(brojacs==vecs.size()){
            cout << "stog" << endl;
            return 0;
        }
    }
    for(auto a:vecp){
        if(a==true){
            brojacp++;
        }
        if(brojacp==vecp.size()){
            cout << "prioritetni red" << endl;
            return 0;
        }
    }
    cout << "q: " << brojacq << ", s: " << brojacs << ", p: " << brojacp << endl;
    if(brojacq>brojacs && brojacq>brojacp){
        cout << "red" << endl;
        return 0;
    }
    else if(brojacs>brojacq && brojacp<brojacs){
        cout << "stog" << endl;
        return 0;
    }
    else if(brojacp>brojacs && brojacp>brojacq){
        cout << "prioritetni red" << endl;
        return 0;
    }
    if(brojacq==brojacs || brojacq==brojacp || brojacs==brojacp){
        cout << "neodluceno" << endl;
        return 0;
    }
    return 0;
}
