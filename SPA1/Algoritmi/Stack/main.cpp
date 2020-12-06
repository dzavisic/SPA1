#include <iostream>
using namespace std;

class Stack {
protected:
    int top;
    unsigned int size;
    int *container;
public:
    Stack() = delete;
    Stack(unsigned int _size) {
        top = 0;
        size = _size;
        container = new int[size];
    }
    Stack(const Stack &v) {
        top = v.top;
        size = v.size;
        container = new int[size];
        for(int i=0; i<top; i++)
            container[i] = v.container[i];
    }
    ~Stack() {delete [] container;}

    bool empty() const {return top == -1;}
    bool full() const {return top == size;}

    void push(int e) {
        if(!full()){
            container[top] = e;
            top++;
        }
    }

    int pop() {
        if(!empty()){
            top--;
            return container[top+1];
        }
    }

    void print() const {
        for(int i=0; i<top; i++)
            cout << container[i] << " ";
    }
};

int main() {

    Stack v(5);
    for(int i=0; i<5; i++)
        v.push(i);
    v.print();
    cout << endl;
    v.pop();
    v.print();

    return 0;
}