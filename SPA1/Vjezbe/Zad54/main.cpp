#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* a, Node* b): data(d), left(a), right(b){}
};

class Tree{
public:
    Tree(){}
    Node* root{};
    void insert(int k){
        if(root==nullptr){
            Node* n=new Node(k, nullptr, nullptr);
            root=n;
        }
        else{
            Node* iter=root;
            Node* temp;
            while(iter!=nullptr){
                if(k>iter->data){
                    temp=iter;
                    iter=iter->right;
                }
                else{
                    temp=iter;
                    iter=iter->left;
                }
            }
            if(k>temp->data){
                Node* n=new Node(k, nullptr, nullptr);
                temp->right=n;
            }else{
                Node* n=new Node(k, nullptr, nullptr);
                temp->left=n;
            }
        }
    }
    void inorder(Node* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main()
{
    Tree T;
    T.insert(8);
    T.insert(4);
    T.insert(6);
    T.insert(7);
    T.insert(2);
    T.insert(10);
    T.inorder(T.root);
    return 0;
}
