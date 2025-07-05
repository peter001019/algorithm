#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int x[10000];
int y[10000];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> x[i] >> y[i];
    
    ll sum = 0;

    for(int i = 1; i < N; i++)
        sum += (ll)x[i - 1] * y[i] - (ll)x[i] * y[i - 1];
    sum += (ll)x[N - 1] * y[0] - (ll)x[0] * y[N - 1];

    double ans = 0.5 * (double)abs(sum);

    cout << fixed;
    cout.precision(1);

    cout << round(ans * 10) / 10;

    return 0;
}