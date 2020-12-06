#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
    Node(int e, Node *N): prev(nullptr), next(N), value(e) {}
    Node(const Node &v) {
        Node *n = new Node(v.value, nullptr);
        prev = v.prev;
        next = v.next;
    }
    //~Node() {}
    void swap(Node &v) {
        int temp = this->value;
        this->value = v.value;
        v.value = temp;

    }
};

class DLL {
protected:
    Node *head;
public:
    DLL(): head(nullptr) {}
    DLL(const DLL *v) {

    }
    ~DLL() {
        Node *it = head;
        Node *brisi;
        while(it!= nullptr){
            brisi = it;
            it = it->next;
            delete brisi;
        }
    }

    bool empty() const {return head == nullptr;}

    void push_front(int e) {
        if(empty()) {
            Node *n = new Node(e, head);
            head = n;
        } else {
            Node *n = new Node(e, head);
            head->prev = n;
            head = n;
        }
    }

    bool erease(int e) {
        Node *it = head;
        Node *brisi;
        if(head->value == e){
            brisi = head;
            head = head ->next;
            delete brisi;
            return true;
        }
        while(it!= nullptr){
            if(it->next->value == e){
                brisi = it->next;
                it->next->next->prev = it;
                it->next = it->next->next;
                return true;
            }
            it = it->next;
        }
    }

    void print() const {
        Node *it = head;
        while(it!= nullptr){
            cout << it->value << ", next: " << it->next << ", prev: " << it->prev << " ";

            it = it->next;
        }
        cout << endl;
    }
};


int main() {

    DLL l;
    for(int i=1; i<6; i++)
        l.push_front(i);
    l.erease(3);
    l.print();



    return 0;
}