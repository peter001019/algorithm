#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int V, E;
vector<pair<int, pair<int ,int>>> edge;
int parent[10001];

int Find(int x){
    if(parent[x] == x) return x; //루트 노드인 경우
    return parent[x] = Find(parent[x]); //연결되어 있는 부모 노드를 반환하면서 갱신
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool isConnected(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    return false;
}

void Kruskal(){
    ll ans = 0;
    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        int cost = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;

        if(!isConnected(a, b)){
            ans += cost;
            Union(a, b);
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int a, b, c;

        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    for(int i = 1; i <= V; i++) parent[i] = i;

    Kruskal();

    return 0;
}