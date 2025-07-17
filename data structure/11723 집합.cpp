#include <bits/stdc++.h>
using namespace std;

int M;
bool s[21];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> M;

    string op;
    int x;

    for(int i = 0; i < M; i++){
        cin >> op;

        if(op == "add") {
            cin >> x;
            s[x] = true;
        }
        else if(op == "remove") {
            cin >> x;
            s[x] = false;
        }
        else if(op == "check"){
            cin >> x;
            if(s[x]) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(op == "toggle"){
            cin >> x;
            s[x] = !s[x];
        }
        else if(op == "all"){
            for(int n = 1; n <= 20; n++) s[n] = true;
        }
        else{
            for(int n = 1; n <= 20; n++) s[n] = false;
        }
    }

    return 0;
}