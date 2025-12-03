#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Node{
public:
    string data;
    Node* next;

    Node(string val){
        data = val;
        next = NULL;
    }
};

// stack using array
class Stack {
  int capacity, top;
  int * arr;
  public:
    Stack(int cap = 100) {
      top = -1;
      capacity = cap;
      arr = new int[capacity];
    }
  bool isEmpty(){
    return top == -1;
  }
  bool isFull(){
    return top == capacity - 1;
  }
  void push(int x) {
    if(isFull()){
        cout<<"Stack is full";
        return;
    }
    top++;
    arr[top] = x;
  }
  int pop() {
    if(isEmpty()){
        cout<<"Stack is empty";
        return -1;
    }
    int x = arr[top];
    top--;
    return x;
  }
  int peek() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
  void printStack(){
    while(!isEmpty()){
        cout<<peek()<<" ";
        pop();
    }
    cout<<endl;
  }
};

void reverse(int arr[], int n){
    Stack s;
    f(i,n){
        s.push(arr[i]);
    }
    f(i,n){
        arr[i] = s.pop();
    }
}

// stack using linked list
class Stack_ll{
  Node* top;
  int size;
  public:
    Stack_ll(){
      top = nullptr;
      size = 0;
    }

  bool isEmpty(){
    if(top == nullptr){
      return true;
    }
    return false;
  }
  void push(string val){
    Node* new_node = new Node(val);
    new_node->next = top;
    top = new_node; 
    size++; 
  }
  string peek(){
    if(isEmpty()){
      cout<<"stack is empty";
      exit(-1);
    }
    return top->data;
  }
  string pop(){
    if(isEmpty()){
      cout<<"stack is empty";
      exit(-1);
    }
    string x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    size--;
    return x;
  }
  void printStack(){
    Node* temp = top;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};

bool isPallindrome(string s){
    Stack_ll stk;
    int n = s.size();
    f(i,n){
        stk.push(string(1,s[i]));
    }
    f(i,n){
        if(stk.peek()[0] != s[i]){
            return false;
        }
        stk.pop();
    }
    return true;
}

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infix2postfix(string s){
    stack <char> stk;
    string r;
    
    f(i,s.length()){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            r += c;}
        else if(c==' '){
            continue;
        }
        else if(c=='('){
            stk.push('(');}
        else if(c == ')'){
            while(!stk.empty() && stk.top()!='('){
                r += stk.top();
                stk.pop();
            }
            stk.pop();}
        else {
          while (!stk.empty() && (prec(s[i]) <= prec(stk.top())) ) {
            r += stk.top();
            stk.pop();
          }
          stk.push(c);
        }
            
    }
    while(!stk.empty()){
        r += stk.top();
        stk.pop();
    } 
    return r;
}

string prefix2Infix(string prefix) {
    Stack_ll s;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string op1 = s.peek(); s.pop();
            string op2 = s.peek(); s.pop();
            s.push("(" + op1 + c + op2 + ")");
        }
    }
    return s.peek();
}

int main() {
    // array stacks
    Stack s;
    s.push(3);
    s.push(8);
    s.push(5);
    cout<<s.peek()<<endl;
    s.printStack();

    // reversing through stack
    int arr[5] = {1,2,3,4,5};
    reverse(arr, 5);
    f(i,5){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // linked list stack that takes string inputs
    Stack_ll s2;
    s2.push("glj");
    s2.push("f");
    s2.push("k");
    cout<<s2.peek()<<endl;
    s2.printStack();

    // check if pallindrome or not
    if(isPallindrome("olplo")){
        cout<<"yes"<<endl;
    }else{cout<<"no"<<endl;}

    // Infix to Postfix conversion
    string exp1 = "a+b*(c^d-e)^(f+g*h)-i"; 
    cout << "Postdix expression: " << infix2postfix(exp1) << endl;
    string exp2 = "(A + (B * C - D) ^ E) / (F * (G + H))";
    cout << "Postdix expression: " << infix2postfix(exp2) << endl;

    // Prefix to Infix conversion
    string exp3 = "*-A/BC-/AKL";
    cout << "Infix Expression: " << prefix2Infix(exp3) << endl;

    return 0;

}
