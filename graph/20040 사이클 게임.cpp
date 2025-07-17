#include <bits/stdc++.h>
using namespace std;

int root[500001];
int node_rank[500001];

int find_root(int x){
    if(root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

bool union_root(int x, int y){
    x = find_root(x);
    y = find_root(y);

    if (x == y) return false;

    if(node_rank[x] < node_rank[y]) root[x] = y;
    else if(node_rank[x] > node_rank[y]) root[y] = x;
    else{
        root[x] = y;
        node_rank[y]++;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) root[i] = i;

    int a, b;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;

        if(!union_root(a, b)){
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}