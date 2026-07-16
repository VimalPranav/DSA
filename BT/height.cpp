#include <iostream>
#include <vector>
#include <queue>
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

int height(Node* root){
    queue<Node*> q;
    q.push(root);
    if(q.front() == NULL){return 0;}
    int k = 0;
    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL){q.push(node->left);}
            if(node->right != NULL){q.push(node->right);}
        }
        k++;        
    }
    return k;
}

int dfs_height(Node* root){
    if(root == nullptr){return 0;}
    int left_height = dfs_height(root->left);
    if(left_height == -1){return -1;}
    int right_height = dfs_height(root->right);
    if(right_height == -1){return -1;}

    if(abs(left_height - right_height) > 1){return -1;}
    return max(left_height, right_height) + 1;
}

bool bal_height(Node* root){
    return dfs_height(root) != -1;
}

int diameter(Node* root, int d){
    if(root == nullptr){return 0;}
    int left_height = diameter(root->left, d);
    int right_height = diameter(root->right, d);
    d = max(left_height+right_height, d);
    return max(left_height, right_height) + 1;
}

bool eq_tree(Node* root1, Node* root2){
    if(root1 == nullptr && root2 == nullptr){return true;}
    if(root1 == nullptr || root2 == nullptr){return false;}
    if(root1->data != root2->data){return false;}
    bool left = eq_tree(root1->left, root2->left);
    if(left == false){return false;}
    bool right = eq_tree(root1->right, root2->right);
    if(right == false){return false;}
    return true;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int h = height(root);
    cout<<"Height: "<<h<<endl;

    // root = NULL;
    bool bal_h = bal_height(root);
    cout<<"Balanced? "<<bal_h<<endl;

    int d = diameter(root,0);
    cout<<d<<endl;
    
    return 0;
}