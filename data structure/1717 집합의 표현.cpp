#include <bits/stdc++.h>
using namespace std;

int parent[1000001];
int height[1000001];

int find_parent(int n){
    if(parent[n] == n) return n;

    return parent[n] = find_parent(parent[n]);
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a == b) return;

    if(height[a] > height[b]){
        swap(a, b);
    }

    parent[a] = b;

    if(height[a] == height[b]) height[b]++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) parent[i] = i;

    int num, a, b;
    for(int i = 0; i < m; i++){ 
        cin >> num >> a >> b;

        if(num == 0){
            union_parent(a, b);
        } else {
            if(find_parent(a) == find_parent(b)) cout << "yes" << "\n";
            else cout << "no" << "\n";
        }
    }

    return 0;
}