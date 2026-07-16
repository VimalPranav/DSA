#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = 0;
        height = 1;
     }
};

int height(Node* root){
    if(root == nullptr){return 0;}
    return root->height;
}

Node* left_rotate(Node* root){
    Node* temp1 = root->right;
    Node* temp2 = temp1->left;
    temp1->left = root;
    root->right = temp2;
    root->height = 1 + max(height(root->left), height(root->right));
    temp1->height = 1 + max(height(temp1->left), height(temp1->right));
    return temp1;
}
Node* right_rotate(Node* root){
    Node* temp1 = root->left;
    Node* temp2 = temp1->right;
    temp1->right = root;
    root->left = temp2;
    root->height = 1 + max(height(root->left), height(root->right));
    temp1->height = 1 + max(height(temp1->left), height(temp1->right));
    return temp1;
}

int height_diff(Node* root){
    if(root == nullptr){return 0;}
    return height(root->left) - height(root->right);
}

Node* insert(Node* root, int val){
    if(root == nullptr){return new Node(val);}
    if(val<root->data){
        root->left = insert(root->left, val);
    }
    else if(val>root->data){
        root->right = insert(root->right, val);
    }
    else{
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    if(height_diff(root)>1 && val<root->left->data){return right_rotate(root);}
    if(height_diff(root)<-1 && val>root->right->data){return left_rotate(root);}
    if(height_diff(root)>1 && val>root->left->data){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(height_diff(root)<-1 && val<root->right->data){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}
void preOrder(Node *root) { 
    if (root != nullptr) { 
        cout << root->data << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

Node* Delete(Node* root, int val){
    if(root == nullptr){return root;}
    if(val<root->data){
        root->left = Delete(root->left, val);
    }
    else if(val>root->data){
        root->right = Delete(root->right, val);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
        }
        else if(root->left == nullptr){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else{
            Node* temp = root->right;
            Node* temp2 = root;
            root = root->left;
            root->right = temp;
            delete temp2;
        }
    }
}

int main(){
    Node *root = nullptr; 
    
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    preOrder(root);
    return 0;
}