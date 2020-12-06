#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool palindrom(stack <char> S1, stack <char> S2){
    stack<char> s1=S1;
    stack<char> s2=S2;
    int brojac=0;
    while(!s1.empty() && !s2.empty()){
        if(s1.top()==s2.top()){
            brojac++;
            s1.pop();
            s2.pop();
        }
        else{
            return false;
        }
    }
    if(brojac==S1.size() && brojac==S2.size()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string Str;
    cin >> Str;
    stack <char> s1;
    stack <char> s2;
    if(Str.length()%2==0){
        for(int i=0; i<Str.length()/2; i++){
            s1.push(Str[i]);
        }
        for(int i=Str.length()-1;i>(int(Str.length())/2)-1;i--){
            s2.push(Str[i]);
        }
    }

    else{
        for(int i=0; i<Str.length()/2; i++){
            s1.push(Str[i]);
        }
        for(int i=Str.length()-1; i>int(Str.length())/2; i--){
            s2.push(Str[i]);
        }
    }
    if(palindrom(s1,s2)==true){
        cout << "DA" << endl;
    }
    else{
        cout << "NE" << endl;
    }
    return 0;
}
