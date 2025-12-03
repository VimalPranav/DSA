#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(ll i = 0; i < n; i++)

// node class
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// linked list class
class Linked_list{
    Node* head;
    public:
        Linked_list(){
            head = nullptr;
        }

    void push_front(int data){
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void push_back(int data){
        Node* new_node = new Node(data);
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insert(int data,int k){
        Node* new_node = new Node(data);
        if(k==1){
            push_front(data);
        }
        int cnt = 0;
        Node* temp = head;
        while(temp->next!=NULL){
            cnt++;
            if(cnt == k-1){
                Node* new_node = new Node(data);
                new_node->next = temp->next;
                temp->next = new_node;
                break;
            }
            temp = temp->next;
        }
        }

    void deleteFromBack(int n){
        Node* front = head;
        Node* back = head;

        for(int i=0;i<n;i++){
            front = front->next;
        }
        if(front == NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        while(front->next!=NULL){
            front = front->next;
            back = back->next;
        }
        Node* temp = back->next;
        back->next = back->next->next;
        delete temp;
    }

    Node* middle_node(){
        Node* temp1 = head;
        Node* temp2 = head;

        while(temp2){
            if(temp2->next==NULL){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }
        return temp1;
    }

    void reverse(){
        Node* temp = head;
        Node* reverse = NULL;

        while(temp){  
            if(temp->next == NULL){
                head = temp;
            }      
            Node* hh = temp->next;
            temp->next = reverse;
            reverse = temp;
            temp = hh;
        }
    }

    void print_ll(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
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
        mover = temp;
    }
    return head;
}


int main(){
    Linked_list ll;
    
    ll.push_front(2);
    ll.push_back(4);
    ll.push_back(6);
    ll.push_back(7);
    ll.print_ll();

    ll.push_front(3);
    ll.print_ll();
    
    ll.push_back(11);
    ll.print_ll();
    
    ll.insert(13,3);
    ll.print_ll();

    ll.reverse();
    ll.print_ll();

    Node* middle = ll.middle_node();
    cout<<middle->data;
    cout<<endl;

    ll.deleteFromBack(3);
    ll.print_ll();
    
    vector<int> arr = {2,4,6,7};

    return 0;
}
