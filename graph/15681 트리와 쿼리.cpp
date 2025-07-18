#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
vector<int> graph[100001];

vector<int> child[100001];
int parent[100001];
int tree_size[100001];

void makeTree(int currentNode, int p){
    for(int n: graph[currentNode]){
        if(n != p){
            child[currentNode].push_back(n);
            parent[n] = currentNode;
            makeTree(n, currentNode);
        }
    }
}

void countSubtreeNodes(int currentNode){
    tree_size[currentNode] = 1;

    for(int n: child[currentNode]){
        countSubtreeNodes(n);
        tree_size[currentNode] += tree_size[n];
    }
}

void sol(){
    makeTree(R, -1);
    countSubtreeNodes(R);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> R >> Q;

    int u, v;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    sol();

    for(int i = 0; i < Q; i++){
        cin >> u;

        cout << tree_size[u] << "\n";
    }

    return 0;
}