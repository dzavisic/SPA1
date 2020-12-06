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
    int prod=1;
    int k=1;
    int d=1;
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
    int fold(Node* root){
        if(root!=nullptr){
            fold(root->left);
            if(root->data%2==0){
                prod=prod*root->data;
            }
            fold(root->right);
        }
        return prod;
    }
};

int main()
{
    Tree T;
    T.insert(1);
    T.insert(2);
    T.insert(3);
    T.insert(4);
    T.insert(5);
    T.insert(6);
    T.insert(7);
    T.insert(8);
    cout << T.fold(T.root) << endl;
    T.inorder(T.root);
    return 0;
}
