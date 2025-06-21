#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> b;

void printV(){
    for(int i: b) cout << i << " ";
    cout << '\n';
}

void combination(int start){
    if(b.size() == M){
        printV();
    }

    for(int i = start + 1; i < N + 1; i++){
        b.push_back(i);
        combination(i);
        b.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    vector<int> b;
    combination(0);

    return 0;
}
