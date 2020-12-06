#include <iostream>
using namespace std;

class Queue {
protected:
    unsigned int size, head, tail;
    int *container;
public:
    Queue() = delete;
    Queue(unsigned int _size){
        size = _size;
        head = 0;
        tail = 0;
        container = new int[size+1];
    }
    Queue(const Queue &v) {
        size = v.size;
        head = v.head;
        tail = v.tail;
        container = new int[size];
        for(int i=0; i!=tail; i=(i+1)%(size+1))
            container[i] = v.container[i];
    }
    ~Queue() {delete container;}

    bool empty() const {return head == tail;}
    bool full() const {return (tail+1)%(size+1) == head;}

    void enqueue(int e) {
        if(!full()){
            container[tail] = e;
            tail = (tail+1)%(size+1);
        }
    }

    int dequeue(int e) {
        if(!empty()){
            auto vrati = container[head];
            head = (head+1)%(size+1);
            return vrati;
        }
    }

    void print() const {
        for(int i=head; i!=tail; i++)
            cout << container[i] << " ";
        cout << endl;
    }
};

int main() {

    Queue q(5);
    for(int i=0; i<5; i++)
        q.enqueue(i);
    q.print();
    Queue d(q);
    d.print();

    return 0;
}