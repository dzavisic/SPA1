#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeList{
    vector<int> _N;
    int _size;

    BinaryTreeList(): _N{}, _size(0) {}
    BinaryTreeList(vector<int> &V): _N{V}, _size(V.size()) {}

    int parent(int i) const {return (i-1)/2;}
    int left(int i) const {return 2*i+1;}
    int right(int i) const {return 2*i+2;}
    int element(int i) {if(i < _size && i >= 0) return _N[i];}
    int root() {if(_size > 0) return _N[0];}
    int size() {return _size;}

    bool setLeft(int n, int e){
        if(left(n) >= size()) {
            return false;
        } else {
            _N[left(n)] = e;
            return true;
        }
    }

    bool setRight(int n, int e){
        if(right(n) >= size()){
            return false;
        } else {
            _N[right(n)] = e;
            return true;
        }
    }

    bool setParent(int n, int e){
        if(n >= size()){
            return false;
        } else {
            _N[parent(n)] = e;
            return true;
        }
    }

    bool empty() const {return _size == 0;}
    bool isLeaf(int n) const {return left(n)>=_size;}
    void postorderPrint(int i) const {
        if(i >= _size)
            return;

        postorderPrint(left(i));
        postorderPrint(right(i));
        cout << _N[i] << " ";
    }
    void swapNodes(int i, int j) {swap(_N[i], _N[j]);}
    void setSize(int newsize) {_size = newsize;}
    int operator[](int i) {return _N[i];}
};

struct MinPriorityQueue {
    BinaryTreeList T;
    MinPriorityQueue(): T{} {}
    MinPriorityQueue(const MinPriorityQueue &L): T(L.T) {}

    void downHeap(int i) {
        int l{T.left(i)};
        int r{T.right(i)};
        int smallest{};

        if(l<T.size() && T[i]>T[l]) smallest = l;
        else smallest = i;
        if(r<T.size() && T[r]<T[smallest]) smallest = r;

        if(i!=smallest){
            T.swapNodes(i, smallest);
            downHeap(smallest);
        }
    }

    void upHeap(int i){
        while(i>=0 && T[T.parent(i)] > T[i]) {
            T.swapNodes(i, T.parent(i));
            i = T.parent(i);
        }
    }

    void buildMinHeap(const vector<int> &L) {
        T._N = L;
        T.setSize(L.size());
        for(int i{T.size()/2-1}; i>=0; i--)
            downHeap(i);
    }

    int minimum() {return T._N.front();}
    int extractMin() {
        int value{minimum()};
        T._N[0] = T[T.size()-1];
        T.setSize(T.size()-1);
        T._N.pop_back();
        downHeap(0);
        return value;
    }



};

ostream& operator<<(ostream& os, const MinPriorityQueue &L){
    MinPriorityQueue L1{L};
    while(!L1.T.empty())
        os << L1.extractMin() << " ";
    return os;
}


int main() {

    vector<int> a={9, 8, 7, 6, 5, 4, 3, 2, 1};
    BinaryTreeList T(a);
    T.postorderPrint(0);
    cout << endl;
    MinPriorityQueue L;
    L.buildMinHeap(a);
    cout << L;


    return 0;
}