#include<bits/stdc++.h>
using namespace std;

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

void infix2postfix(string s){
    stack <char> stk;
    string r;
    
    for(int i = 0;i<s.length();i++){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            r += c;}
        else if(c=='('){
            stk.push('(');}
        else if(c == ')'){
            while(stk.top()!='('){
                r += stk.top();
                stk.pop();
            }
            stk.pop();}
        else {
          while (!stk.empty() && prec(s[i]) <= prec(stk.top())) {
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
    
    cout << "Postdix expression: " << r << endl;
}

int main(){
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infix2postfix(exp);
    return 0;
}