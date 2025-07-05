#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> input;

void sol(){
    int start = 0;
    int end = input.size() - 1;
    int min = INT_MAX;
    pair<int, int> ans;

    while(start < end){
        int sum = input[start] + input[end];

        if(min > abs(sum)) {
            min = abs(sum);
            ans = {input[start], input[end]};
        }

        if(sum < 0) start++;
        else end--;
    }

    printf("%d %d", ans.first, ans.second);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    sol();

    return 0;
}