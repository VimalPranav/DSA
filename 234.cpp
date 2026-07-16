#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    bool isLeaf;
    vector<int> key;
    vector<Node*> child;

    Node(bool x){
        isLeaf = x;
        keys.clear();
        child.clear();
    }
};

class BT234{
private:
    static const int MAX_KEYS = 3;
    static const int MIN_KEYS = 1;
public:
    Node* insert(Node* root, int val){
        if(root == nullptr){
            Node* new_node = new Node(true);
            new_node->key.push_back(val);
        }
        if(root->key.size()==MAX_KEYS){
            Node* new_root = new Node(false);
            new_root = 
        }
    }
};

int main(){
    BT234 t;
    Node* root = nullptr;

    root = t.insert(10);
    root = t.insert(20);
    root = t.insert(5);
    root = t.insert(6);
    root = t.insert(12);
    root = t.insert(30);
    root = t.insert(7);
    root = t.insert(17);
    return 0;
}