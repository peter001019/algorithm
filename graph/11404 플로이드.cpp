#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[101][101];
const int INF = 1e9;

void floyd(){
    for(int k = 1; k < n + 1; k++)
        for(int i = 1; i < n + 1; i++)
            for(int j = 1; j < n + 1; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    int a, b, c;

    for(int i = 1; i < n + 1; i++) //무한대로 초기화
        for(int j = 1; j < n + 1; j++)
            graph[i][j] = (i == j) ? 0 : INF;
    
    for(int i = 0; i < m; i++){ //graph 입력
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    floyd();

    for(int i = 1; i < n + 1; i++){ //graph 출력
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == INF) graph[i][j] = 0;

            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}