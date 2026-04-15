//  ██████╗  ██╗  ██╗ ████████╗ █████╗  ██╗     
// ██╔════╝  ██║  ██║     ██║  ██╔══██╗ ██║     
// ╚█████╗   ██║  ██║     ██║  ███████║ ██║     
//  ╚═══██╗  ██║  ██║ ██╗ ██║  ██╔══██║ ██║     
// ██████╔╝  ╚█████╔╝╚█████╔╝  ██║  ██║ ███████╗
// ╚═════╝     ╚════╝  ╚════╝   ╚═╝  ╚═╝ ╚══════╝

// Array Description

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

ll n, m;
vector<ll> v;

ll f(int i, int last, vector<vector<ll>>& dp){
    if(i == n) return 1;

    if(last != -1 && dp[i][last] != -1)
        return dp[i][last];

    ll total = 0;

    if(v[i] != 0){
        if(last == -1 || abs(v[i] - last) <= 1){
            total = f(i+1, v[i], dp);
        }
    }
    else{
        if(last == -1){
            for(int val = 1; val <= m; val++){
                total = (total + f(i+1, val, dp)) % mod;
            }
        }
        else{
            for(int nxt = last-1; nxt <= last+1; nxt++){
                if(nxt >= 1 && nxt <= m){
                    total = (total + f(i+1, nxt, dp)) % mod;
                }
            }
        }
    }

    if(last != -1)
        dp[i][last] = total;

    return total;
}

void solve(){
    cin >> n >> m;
    v.resize(n);
    for(auto &x : v) cin >> x;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, -1));

    cout << f(0, -1, dp) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}