#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int D[1000];
vector<int> graph[1001];

void sol(){

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> N >> K;

        for(int j = 0; j < N; j++) cin >> D[j];
        for(int k = 0; k < K; k++){
            int x, y;
            cin >> x >> y;

            graph[x].push_back(y);
        }

        sol();
    }

    return 0;
}

/*
DAG -> 위상 정렬 //특정 경로를 찾을 수 있음

*/
