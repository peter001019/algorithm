#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, string> listen;
vector<string> ans;
int cnt;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    string name;
    for(int i = 0; i < N; i++){
        cin >> name;
        listen.insert({name, name});
    }

    for(int i = 0; i < M; i++){
        cin >> name;

        if(listen.find(name) != listen.end()){
            ans.push_back(name);
            cnt++;
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << "\n";
    for(string s: ans) cout << s << "\n";

    return 0;
}

/*
듣못
보못
-> 교집합 듣보잡

듣못 -> hash map key

보못 조회


*/