#include <iostream>
using namespace std;

// Node of a doubly linked list
class Node {
public:
    int data;
    Node* prev, *next;
    Node(int d,Node* a, Node* b): data(d), next(a), prev(b){}
};

class Lista{
public:
    Node* head=new Node(INT_MIN, nullptr,nullptr);
public:
    Lista(){}
    /*bool sortedInsert(Node* head, int x){
        cout << "uso sam sa "<< x << endl;
        Node* iter=head;
        if(iter->next==nullptr && iter->prev!=nullptr){
            cout << "4: " << endl;
            Node* temp = new Node(x, nullptr, iter->prev);
            iter=head;
            return true;
        }
        else{
            while(iter->next!=nullptr){
                /*if(iter->data >= x){
                    if(iter->data==INT_MIN){
                        cout << "1: " << endl;
                        head->data=x;
                        return true;
                    }
                    else if(iter->data<x && iter->next->data>x){
                        cout << "2: " << endl;
                        Node* temp = new Node(x, iter->next, iter);
                        iter->next=temp;
                        temp->next->prev=temp;
                        return true;
                    }
                    else if(iter->data >= x){
                        cout << "3: " << endl;
                        Node* temp = new Node(x, iter, nullptr);
                        head=temp;
                        iter->prev=temp;
                        return true;
                    }
                }
                if(iter->data==INT_MIN){
                    cout << "1: " << endl;
                    head->data=x;
                    Node* temp=new Node(x, nullptr, nullptr);
                    head=temp;
                    iter=head;
                    return true;
                }
                else if(head->data>=x){
                    cout << "2: " << endl;
                    Node* priv = head;
                    Node* temp = new Node(x, priv, nullptr);

                    priv->prev=temp;
                    head=temp;
                    iter=head;
                    return true;
                }
                else if(x>=iter->data && x<=iter->next->data){
                    cout << "3: " << endl;
                    Node* temp = new Node(x, iter->next,iter);
                    iter->next=temp;
                    temp->next->prev=temp;
                    iter=head;
                    return true;
                }
                else{
                    cout << "iteriram " << endl;
                    iter=iter->next;
                }
            }
        }*/
    void sortedInsert(int x){
        Node* iter = head;
        if(iter->next==nullptr && iter->prev==nullptr && iter->data==INT_MIN){
            cout << "1: " << x << endl;
            Node* n=new Node(x, nullptr, nullptr);
            head=n;
            print();
            //cout << "head novi " << head->data << " " << head->next << " " << head->prev << endl;
            return;
        }
        else{
            int brojac=0;
            while(brojac!=1){
                if(iter->data>x && iter->prev==nullptr){
                    Node* n=new Node(x, iter, nullptr);
                    iter->prev=n;
                    head=n;
                    print();
                    return;
                }
                else if(iter->data<x && iter->next==nullptr){
                    cout << "2: " << x << endl;
                    Node* n=new Node(x, nullptr, iter);
                    iter->next=n;
                    print();
                    return;
                }
                else if(iter->data<x && iter->next->data>x ){
                    cout << "3: " << x << endl;
                    Node* n=new Node(x, iter->next, iter);
                    iter->next->prev=n;
                    iter->next=n;
                    print();
                    return;
                }

                else{
                    cout << "4: " << x << endl;
                    iter=iter->next;
                    brojac=0;
                    print();
                    cout <<"Trenutno: " <<iter->data << " " <<iter->prev << " " << iter->next << endl;
                }
            }
        }
    }
    void print(){
        Node* iter=head;
        while (iter != nullptr) {
            cout << iter->data << " <-> ";
            iter= iter->next;
        }
        cout << endl;
    }

};

// Driver program to test above
int main()
{
    Lista L;
    L.sortedInsert(8);
    L.sortedInsert(5);
    L.sortedInsert(3);
    L.sortedInsert(10);
    L.sortedInsert(12);
    L.sortedInsert(9);

    L.print(); //8,5,3,10,12,9
    return 0;
}
