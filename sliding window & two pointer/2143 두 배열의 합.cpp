#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T;
int n, m;
vector<ll> A;
vector<ll> B;
vector<ll> A_sum;
vector<ll> B_sum;
ll ans;

void cul_sum(){
    //A 누적합
    for(int i = 0; i < n; i++){
        int sum = A[i];
        A_sum.push_back(sum);
        for(int j = i + 1; j < n; j++){
            sum += A[j];
            A_sum.push_back(sum);
        }
    }

    //B 누적합
    for(int i = 0; i < m; i++){
        int sum = B[i];
        B_sum.push_back(sum);
        for(int j = i + 1; j < m; j++){
            sum += B[j];
            B_sum.push_back(sum);
        }
    }
}

void sol(){
    cul_sum();

    sort(A_sum.begin(), A_sum.end());
    sort(B_sum.begin(), B_sum.end());

    int a = 0;
    int b = B_sum.size() - 1;

    while(a < A_sum.size() && b > -1){
        int sum = A_sum[a] + B_sum[b];

        if(sum > T) b--;
        if(sum < T) a++;

        if(sum == T){
            ll tmpA = A_sum[a];
            ll tmpB = B_sum[b];
            ll cntA = 0;
            ll cntB = 0;

            while(a < A_sum.size() && A_sum[a] == tmpA){
                cntA++;
                a++;
            }
            while(b > -1 && B_sum[b] == tmpB){
                cntB++;
                b--;
            }

            ans += cntA * cntB;
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;
    cin >> n;
    
    ll num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        A.push_back(num);
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> num;
        B.push_back(num);
    }

    sol();

    return 0;
}