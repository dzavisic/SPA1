#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
    Node(int n): value(n), next(nullptr), prev(nullptr) {}
    Node(const Node &v) {
        Node *n = new Node(v.value);
        next = v.next;
        prev = v.prev;
    }
    ~Node() {}
};

class CDLL {
protected:
    Node *head;
    Node *tail;
public:
    CDLL(): head(nullptr), tail(nullptr) {}
    CDLL(const CDLL &v) {

    }
    ~CDLL() {}

    bool empty() const {return head == nullptr;}

    void prepend(int e) {
        Node *n = new Node(e);
        if(empty()){
            head = n;
            tail = n;
            n->next = n;
            n->prev = head;
        } else {
            tail->next = n;
            head->prev = n;
            n->next = head;
            n->prev = tail;
            head = n;
        }
    }

    void append(int e) {
        Node *n = new Node(e);
        if(empty()){
            head = n;
            tail = n;
            n->next = n;
            n->prev = head;
        } else {
            tail->next = n;
            n->next = head;
            head->prev = n;
            n->prev = tail;
            tail = n;
        }
    }

    double removeFromHead() {
        if(!empty()){
            Node* brisi = head;
            double vrati = head->value;
            if(head->next == head){
                delete brisi;
                return vrati;
            } else {
                head = head->next;
                tail->next = head;
                head->prev = tail;
                delete brisi;
                return vrati;
            }
        }
    }

    double removeFromTail() {
        if(!empty()){
            Node* brisi = tail;
            double vrati = tail->value;
            if(tail->next == tail){
                delete brisi;
                return vrati;
            } else {
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
                delete brisi;
                return vrati;
            }
        }
    }

    void print() const {
        Node *it = head;
        while(it!=tail) {
            cout << it->value << " ";
            it = it->next;
        }
        cout << it->value << endl;
    }

};

int main() {

    CDLL l;
    for(int i=1; i<6; i++)
        l.append(i);
    l.print();

    return 0;
}