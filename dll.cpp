#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node* arr2list(vector<int> &arr){
    if (arr.empty()){
        return NULL;
    }
    
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

Node* push_front(Node* head,int data){
    Node* new_node = new Node(data);
    head->prev = new_node;
    new_node->next = head;
    return new_node;
}

Node* push_back(Node* head,int data){
    Node* new_node = new Node(data);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}

Node* insert(Node* head,int data,int k){
    Node* new_node = new Node(data);
    if(k==1){
        head = push_front(head,data);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt == k-1){
            Node* new_node = new Node(data);
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* reverse(Node* head){
    Node* temp = head;
    while(temp){
        Node* reverse = temp->next;
        temp->next = temp->prev;
        temp->prev = reverse;
        if(temp->prev==NULL){
            head = temp;
        }
        temp = temp->prev;
    }
    return head;
}

void print_ll(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
    

int main(){
    vector<int> arr = {2,4,6,7};
    Node* head = arr2list(arr);
    cout<<head->next->data<<endl;
    cout<<head->next->prev->data<<endl;
    print_ll(head);
    cout<<endl;
    
    head = push_front(head,3);
    print_ll(head);
    cout<<endl;
    
    head = push_back(head,11);
    print_ll(head);
    cout<<endl;
    
    head = insert(head,13,1);
    print_ll(head);
    cout<<endl;

    head = reverse(head);
    print_ll(head);
    cout<<endl;

    return 0;
}