#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename K, typename V>
struct BinaryTreeList {
    vector<pair<K, V>> N;
    int size;

    BinaryTreeList(): N{}, size(0) {}
    BinaryTreeList(const vector<pair<K, V>> &V): N{V}, size(V.size()) {}

    int parent(int i) const {return (i-1)/2;}
    int left(int i) const {return 2*i+1;}
    int right(int i) const {return 2*i+2;}
    pair<K, V> element(int i) {if(i<size) return N[i];}

    void setLeft(int i, const pair<K, V> &E){
        if(left(i) < size)
            N[left(i)] = E;
    }

    void setRight(int i, const pair<K, V> &E){
        if(right(i) < size)
            N[right(i)] = E;
    }

    void setParent(int i, const pair<K, V> &E){
        if(i > 0)
            N[parent(i)] = E;
    }

    void setSize(int newSize) {size = newSize;}

    bool isLeaf(int i) const {return left(i)>=size;}

    bool empty() const {return size == 0;}

    void preorderPrint(int i) const {
        if(i>=size)
            return;
        cout << N[i] << " ";
        preorderPrint(left(i));
        preorderPrint(right(i));
    }

    void swapNodes(int i, int j) {swap(N[i], N[j]);}

    pair<K, V>& operator[](int i) {return N[i];}
};

template<typename K, typename V>
struct MinPriorityQueue {
    BinaryTreeList<K, V> T;
    MinPriorityQueue(): T{} {}
    MinPriorityQueue(const MinPriorityQueue &L): T(L.T) {}

    void downHeap(int i) {
        int l{T.left(i)};
        int r{T.right(i)};
        int smallest{};

        if(l<T.size && T[i].first > T[l].first) smallest = l;
        else smallest = i;
        if(r<T.size && T[r].first < T[smallest].first) smallest = r;

        if(i!=smallest){
            T.swapNodes(i, smallest);
            downHeap(smallest);
        }
    }

    void upHeap(int i) {
        while(i>=0 && T[T.parent(i)].first > T[i].first){
            T.swapNodes(i, T.parent(i));
            i = T.parent(i);
        }
    }

    void buildMinHeap(const vector<pair<K, V>> &L){
        T.N = L;
        T.setSize(L.size());
        for(int i{T.size/2-1}; i>=0; i--)
            downHeap(i);
    }

    V minimum() {return T.N.front().second;}

    V extractMin() {
        V value{minimum()};
        T[0] = T[T.size-1];
        T.setSize(T.size-1);
        T.N.pop_back();
        downHeap(0);
        return value;
    }

    void decreaseKey(int i, int key) {
        T[i].first = key;
        upHeap(i);
    }

    void insert(const pair<K, V> &L) {
        T.setSize(T.size+1);
        T.N.push_back(L);
        upHeap(T.size-1);
    }
};

template<typename K, typename V>
ostream& operator<<(ostream& os, const pair<K, V> &T) {
    return os << "K: " << T.first << ", V: " << T.second << " ";
}

template<typename K, typename V>
ostream& operator<<(ostream& os, const MinPriorityQueue<K, V> &L){
    MinPriorityQueue<K, V> L1{L};
    while(!L1.T.empty()){
        os << L1.extractMin() << " ";
    }
    return os;
}


int main() {

    vector<pair<int, string>> a = {{3, "kljuc1"}, {2, "kljuc2"}, {1, "kljuc3"}};
    BinaryTreeList<int, string> T(a);
    T.preorderPrint(0);
    cout << endl << " ---------------- " << endl;
    MinPriorityQueue<int, string> K;
    K.buildMinHeap(a);
    cout << K;

    return 0;
}