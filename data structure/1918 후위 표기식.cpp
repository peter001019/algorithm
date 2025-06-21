#include <bits/stdc++.h>
using namespace std;

string expr;
string postfix;

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

void to_postfix(){
    stack<char> st;

    for(char c: expr){
        if(isalpha(c)) postfix += c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop(); // '(' 제거
        }
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> expr;

    to_postfix();

    cout << postfix << '\n';

    return 0;
}