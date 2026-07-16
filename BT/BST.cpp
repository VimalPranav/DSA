#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = 0; }
};

Node* BST(Node* root,int t){
    while(root != NULL && root->data != t){
            if(t<root->data)
                root = root->left;
            else
                root = root->right;
        }
        return root;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);
    
    int target = 6;
    Node* result = BST(root, target);

    if (result != nullptr) {
        cout << "Value " << target << " found in the BST!" <<endl;
    } else {
        cout << "Value " << target << " not found in the BST." <<endl;
    }
    
    return 0;
}