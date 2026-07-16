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

Node* level2BT(vector<int> &arr){
    if(arr.empty()){
        return NULL;
    }
    Node* root = nullptr;
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* node = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            node->left = new Node(arr[i]);
            q.push(node->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            node->right = new Node(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
    
}

void preorder(Node* root, vector<int> &arr){
    
    if(root == nullptr){
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

void inorder(Node* root, vector<int> &arr){
    
    if(root == nullptr){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
void postorder(Node* root, vector<int> &arr){
    
    if(root == nullptr){
        return;
    }
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}
vector<vector<int>> levelorder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    if(root == NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            Node* xyz = q.front();
            q.pop();
            if(xyz->left!=NULL){q.push(xyz->left);}
            if(xyz->right!=NULL){q.push(xyz->right);}
            level.push_back(xyz->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr = {4, 3, 2, -1, 8, 7, -1};
    Node* root = level2BT(arr);

    vector<int> arr;   
    vector<int> arr2; 
    vector<int> arr3;

    preorder(root, arr);
    inorder(root, arr2);
    postorder(root, arr3);
    vector<vector<int>> arr4 = levelorder(root);

    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    for(int i : arr2) {
        cout << i << " ";
    }
    cout << endl;
    for(int i : arr3) {
        cout << i << " ";
    }
    cout << endl;
    for(const vector<int>& i : arr4) {
        cout<<"[";
        for (int num : i) {
            cout << num << " ";
        }
        cout<<"]";
    }
    cout << endl;

    return 0;
}   