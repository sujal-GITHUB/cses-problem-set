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

ll n, x;
static const int mod = 1e9+7;

void solve(){
    cin>>n>>x;

    vector<int>coins;
    coins.reserve(n);

    for(int i=0; i<n; i++){
        int c;
        cin>>c;
        if(c <= x) 
        coins.push_back(c);
    }

    vector<int>dp(x+1, 0);
    dp[0] = 1;

    int m = coins.size();

    for(int i=1; i<=x; i++){
        int ways = 0;
        for(int k=0; k<m; k++){
            if((i-coins[k]) >= 0){
                ways += dp[i - coins[k]];
                if(ways >= mod) 
                ways -= mod;
            }
        }

        dp[i] = ways;
    }

    cout<<dp[x]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--) 
    solve();

    return 0;
}