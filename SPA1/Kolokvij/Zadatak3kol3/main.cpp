#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T>
class Stack
{
public:

    void push(T d){
        A.push(d);
        if(temp < d){
            temp = d;
            lista.push_back(temp);
        }
        else{
            lista.push_back(temp);
        }
    }
    T pop(){
        while(!A.empty()){
            B.push(A.front());
            A.pop();
        }
        B.pop();
        while(!B.empty()){
            A.push(B.front());
            B.pop();
        }
        lista.pop_back();
    }
    T findMax(){
        cout << lista[lista.size()-1] << endl;
    }

    private:
    queue<T> A, B;
    T temp=0;
    vector<T> lista;
};


int main()
{

    Stack<int> S;

    // Broj operacija u nizu
    int n;
    cin >> n;
    while(n)
    {
        char x;
        cin >> x;
        if (x == 'i')
        {
            int y;
            cin >> y;
            S.push(y);
        }
        else if (x == 'd') S.pop();
        else if (x=='f') S.findMax();
        else cout << "Not recognized\n";
        n--;
    }
    return 0;
}
