#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> num;
int ans[1000001];
bool isPlayer[1000001];

void sol(){
    for(int n: num){
        for(int i = n * 2; i < 1000001 / n + 1; i += n){
            if(isPlayer[i]){
                ans[n]++;
                ans[i]--;
            }
        }
    }

    for(int n: num) cout << ans[n] << " ";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    int player;

    for(int i = 0; i < N; i++){
        cin >> player;

        num.push_back(player);
        isPlayer[player] = true;
    }

    sol();

    return 0;
}