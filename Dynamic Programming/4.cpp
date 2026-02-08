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

    for(int coin : coins){
        for (ll s = coin; s <= x; s++) {
            dp[s] = (dp[s] + dp[s - coin]) % mod;
        }
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