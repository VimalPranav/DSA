#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue {
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }
    
  Queue(int maxSize) {
    ( * this).maxSize = maxSize;
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }
  
  bool isEmpty(){
    return currSize == 0;
  }
  bool isFull(){
    return currSize == maxSize;
  }
  void enqueue(int data){
    if(isFull()){cout<<"queue is full"<<endl; exit(1);}
    if(start == -1){
        start = 0;
        end = 0;
    } else{
        end = (end + 1) % maxSize;}
    arr[end] = data;
    currSize++;
  }
  void dequeue(){
    if(isEmpty()){cout<<"queue is empty"<<endl; exit(1);}
    if(currSize == 1){
        start = -1;
        end = -1;
    }else{
        start = (start + 1) % maxSize;
    }
    currSize--;
  }
  int peek(){
    if(isEmpty()){cout<<"queue is Empty"<< endl; exit(1);}
    return arr[start];
    }
  int size(){
    return currSize;
  }  
  void display(){
    while(!isEmpty()){
        cout<<peek()<<" ";
        dequeue();
    }
    cout<<endl;
  }
}; 

class Queue_ll{
    Node* start;
    Node* end;
    int size;
    public:
        Queue_ll(){
            start = nullptr;
            end = nullptr;
            size = 0;
        }
    
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int val){
        Node* new_node = new Node(val);
        if(isEmpty()){
            start = new_node;
        }else{
            end->next = new_node;
        }
        end = new_node;
        size++;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
    }
    int peek(){
        return start->data;
    }
    void display(){
        Node* temp = start;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

class Stack_by_Queue{
    Queue q;
public:
    Stack_by_Queue() : q(100) {}

    bool isEmpty() {
        return q.isEmpty(); 
    }

    void push(int x) {
        int s = q.size(); 
        q.enqueue(x); 
        for (int i = 0; i < s; i++) {
            q.enqueue(q.peek()); 
            q.dequeue(); 
        }
    }

    int pop() {
        if(isEmpty()){
            cout << "stack empty\n";
            exit(1);
        }
        int n = q.peek(); 
        q.dequeue(); 
        return n; 
    }

    int peek() {
        if(q.isEmpty()){ 
            cout<<"queue is empty"<<endl; 
            exit(1); 
        }
        return q.peek(); 
    }
};

class Queue_by_Stack {
  public:
    stack<int> input, output;

    StackQueue() {}

    void enqueue(int x) {
        input.push(x);
    }

    void dequeue() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return;
        }

        output.pop();
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};



int main() {
    // queue using array
    Queue q(6);
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.enqueue(34);  
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.display();
    cout<<endl;

    // queue using linked list
    Queue_ll q2;
    q2.enqueue(4);
    q2.enqueue(14);
    q2.enqueue(24);
    q2.enqueue(34);  
    cout<<q2.peek()<<endl;
    q2.dequeue();
    cout<<q2.peek()<<endl;
    q2.display();
    cout<<endl;

    // stack using queue
    Stack_by_Queue s;
    s.push(3);
    s.push(8);
    s.push(5);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<endl;

    // queue using stack
    Queue_by_Stack q3;
    q3.enqueue(4);
    q3.enqueue(14);
    q3.enqueue(24);
    q3.enqueue(34);  
    cout<<q3.peek()<<endl;
    q3.dequeue();
    cout<<q3.peek()<<endl;
    cout<<endl;

    return 0;
}
