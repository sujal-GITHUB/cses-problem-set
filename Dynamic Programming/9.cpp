//  ██████╗  ██╗  ██╗ ████████╗ █████╗  ██╗     
// ██╔════╝  ██║  ██║     ██║  ██╔══██╗ ██║     
// ╚█████╗   ██║  ██║     ██║  ███████║ ██║     
//  ╚═══██╗  ██║  ██║ ██╗ ██║  ██╔══██║ ██║     
// ██████╔╝  ╚█████╔╝╚█████╔╝  ██║  ██║ ███████╗
// ╚═════╝     ╚════╝  ╚════╝   ╚═╝  ╚═╝ ╚══════╝

// Counting towers

// Top Down solution

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

ll n;
const int MAXN = 1e6 + 5;
vector<vector<ll>> dp(MAXN, vector<ll>(2));

ll f(ll i, int state, vector<vector<ll>>& dp){
    if(i == n){
        return 1;
    }

    if(dp[i][state] != -1)
    return dp[i][state];

    if(state == 0){
        return dp[i][state] = (4LL * f(i+1, 0, dp) + f(i+1, 1, dp)) % mod;
    }
    else{
        return dp[i][state] = (f(i+1, 0, dp) + 2LL * f(i+1, 1, dp)) % mod;
    }
}

void solve(){
    cin >> n ;
    vector<vector<ll>> dp(n, vector<ll>(2, -1));

    cout<<(f(1, 0, dp) + f(1, 1, dp))%mod<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}

// Bottom Up solution

void solve(){
    cin >> n ;

    dp[n][0] = 1;
    dp[n][1] = 1;

    for(int i=n-1; i>=1; i--){
        dp[i][0] = (4LL*dp[i+1][0] + dp[i+1][1])%mod;
        dp[i][1] = (dp[i+1][0] + 2LL*dp[i+1][1])%mod;
    }

    cout<<(dp[1][0] + dp[1][1])%mod<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}