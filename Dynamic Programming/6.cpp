//  ██████╗  ██╗  ██╗ ████████╗ █████╗  ██╗     
// ██╔════╝  ██║  ██║     ██║  ██╔══██╗ ██║     
// ╚█████╗   ██║  ██║     ██║  ███████║ ██║     
//  ╚═══██╗  ██║  ██║ ██╗ ██║  ██╔══██║ ██║     
// ██████╔╝  ╚█████╔╝╚█████╔╝  ██║  ██║ ███████╗
// ╚═════╝     ╚════╝  ╚════╝   ╚═╝  ╚═╝ ╚══════╝

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

template<typename T> void ip(T &x){ cin >> x; }
template<typename T> void ip(vector<T> &v){ for(auto &x : v) cin >> x; }

ll n, m;
static const int mod = 1e9+7;

void solve(){
    cin>>n>>m;
    vector<ll>v(n);

    for(auto &x: v)
    cin>>x;

    vector<vector<ll>>dp(n+1, vector<ll>(m+1, 0));
    if(v[0] == 0){
        for(int x=1; x<=m; x++)
            dp[0][x] = 1;
    } 
    else{
        dp[0][v[0]] = 1;
    }

    for(int i=1; i<n; i++){
        for(int x=1; x<=m; x++){
            if(v[i] == 0 || v[i] == x){
                dp[i][x] = dp[i-1][x];

                if(x-1 >= 1)
                    dp[i][x] = (dp[i][x] + dp[i-1][x-1]) % mod;

                if(x+1 <= m)
                    dp[i][x] = (dp[i][x] + dp[i-1][x+1]) % mod;
            }
        }
    }

    ll ans = 0;
    for(int x=1; x<=m; x++)
        ans = (ans + dp[n-1][x]) % mod;

    cout<<ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--) 
    solve();

    return 0;
}