#include <iostream>
using namespace std;

struct Node {
    int e;
    Node *next;
    Node(int n, Node *N): e(n), next(N) {}
};

class List {
protected:
    Node *head;
public:
    List(): head(nullptr) {}
    void push_front(int e) {
        Node *n = new Node(e, head);
        head = n;
    }
    void print() const {
        Node *it = head;
        while(it != nullptr){
            cout << it->e << " ";
            it = it->next;
        }
        cout << endl;
    }
    ~List() {
        Node *it = head;
        Node *brisi;
        while(it != nullptr){
            brisi = it;
            it = it->next;
            delete brisi;
        }
    }
    Node *search(int n) {
        Node *it = head;
        while(it != nullptr){
            if(it->e == n)
                return it;
            it = it->next;
        }
        return nullptr;
    }
    bool erease(int n) {
        Node *it = head;
        Node *brisi;
        if(head->e == n){
            brisi = head;
            head = head -> next;
            delete brisi;
            return true;
        }
        while(it != nullptr){
            if(it->next->e == n){
                brisi = it->next;
                it->next = it->next->next;
                delete brisi;
                return true;
            }
            it = it->next;
        }
        return false;
    }
    int size() {
        Node *it = head;
        int cnt = 0;
        while(it!= nullptr) {
            cnt++;
            it = it->next;
        }
        return cnt;
    }
};

int main() {

    List L;
    for(int i=1; i<6; i++)
       L.push_front(i);

    L.erease(5);
    cout << L.size() << endl;
    cout << L.search(3) << endl;

    L.print();

    return 0;
}