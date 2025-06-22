#include <bits/stdc++.h>
using namespace std;

string str, bomb;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    cin >> bomb;

    stack<char> st;
    string ans = "";
    int bombC = bomb[bomb.size() - 1];

    for(char c: str){
        st.push(c);

        //bomb인지 검사
        if (st.top() == bombC && st.size() >= bomb.size()){
            string tmp = "";

            for(int i = bomb.size() - 1; i > -1; i--){
                if(st.top() != bomb[i]) break;

                tmp += st.top();
                st.pop();
            }

            reverse(tmp.begin(), tmp.end());

            //bomb이 아닌 경우 다시 스택에 push
            if(tmp.compare(bomb) != 0)
                for(char c: tmp)     
                    st.push(c);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << (ans.empty() ? "FRULA" : ans);

    return 0;
}