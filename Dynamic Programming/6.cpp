//  ██████╗  ██╗  ██╗ ████████╗ █████╗  ██╗     
// ██╔════╝  ██║  ██║     ██║  ██╔══██╗ ██║     
// ╚█████╗   ██║  ██║     ██║  ███████║ ██║     
//  ╚═══██╗  ██║  ██║ ██╗ ██║  ██╔══██║ ██║     
// ██████╔╝  ╚█████╔╝╚█████╔╝  ██║  ██║ ███████╗
// ╚═════╝     ╚════╝  ╚════╝   ╚═╝  ╚═╝ ╚══════╝

// Grid Paths I

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const long long mod = 1e9+7;
ll n, x;

void solve() {
    cin >> n >>x;
    vector<ll>h(n), s(n);

    for(auto &x: h)
    cin>>x;

    for(auto &x: s)
    cin>>x;

    vector<vector<int>>dp(n+1, vector<int>(x+1, 0));

    for(int i=n-1; i>=0; i--){
        for(int m=0; m<=x; ++m){
            int skip = dp[i+1][m];
            int pick = -1e8;

            if(m-h[i] >= 0){
                pick = s[i] + dp[i+1][m-h[i]];
            }

            dp[i][m] = max(pick, skip);
        }
    }

    cout<<dp[0][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
