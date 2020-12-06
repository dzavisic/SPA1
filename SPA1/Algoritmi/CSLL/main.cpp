#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int e): value(e), next(nullptr) {}
    ~Node() {}
    void print() const {cout << value << endl;}
};

class CSLL {
protected:
    Node *head;
public:
    CSLL(): head(nullptr) {}
    CSLL(const CSLL &v) {

    }
    ~CSLL(){while(!empty()) removeFromHead();}

    int removeFromHead() {
        if(!empty()){
            Node* last = head;
            Node* brisi = head;
            int vrati = head->value;
            if(last->next==head){
                head = nullptr;
                return vrati;
            } else {
                while (true) {
                    if (last->next == head)
                        break;
                    last = last->next;
                }
                head = head->next;
                last->next = head;

                return vrati;
            }
        } else {
            return NULL;
        }
    }

    bool empty() const {return head == nullptr;}

    void prepend(int e) {
        Node *n = new Node(e);
        if(empty()){
            n->next = n;
            head = n->next;
        } else {
            Node *last = head;
            while(true){
                if(last->next == head)
                    break;
                last = last->next;
            }
            n->next = head;
            head = n;
            last->next = head;
        }
    }

    void append(int e) {
        Node *n = new Node(e);
        if(empty()){
            n->next = n;
            head = n;
        } else {
            Node *last = head;
            while(true){
                if(last->next == head)
                    break;
                last = last->next;
            }
            last->next = n;
            n->next = head;
        }
    }

    bool erease(int e) {
        Node *last = head;
        Node *brisi;
        if(head->value == e){
            while(true){
                if(last->next == head)
                    break;
                last = last->next;
            }
            brisi = head;
            head = head->next;
            last->next = head;
            delete brisi;
            return true;
        } else {
            Node* it = head;
            while(it->next!=head){
                if(it->next->value == e){
                    brisi = it->next;
                    it->next = it->next->next;
                    delete brisi;
                    return true;
                }
                it = it->next;
            }
        }
        return false;
    }

    void print() const {
        Node *it = head;
        while(it->next!=head){
            cout << it->value << ", next: " << it->next << ", it: " << it << " ";
            it = it->next;
        }
        cout << it->value << ", next: " << it->next << ", it: " << it << " ";
    }
};

int main() {

    CSLL l;
    for(int i=1; i<6; i++)
        l.append(i);

    l.removeFromHead();
    l.erease(3);

    l.print();

    return 0;
}