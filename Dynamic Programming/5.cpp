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

ll n;
static const int mod = 1e9+7;

ll f(int x, vector<ll>&dp){
    if(x == 0){
        return 0;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    ll ans = 1e9;
    int y = x;

    while(y){
        int d = y%10;
        y /= 10;

        if(d > 0){
            ans = min(ans, 1+f(x-d, dp));
        }
    }

    return dp[x] = ans;
}

void solve(){
    cin>>n;
    vector<ll>dp(n+1, -1);

    cout<<f(n, dp)<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--) 
    solve();

    return 0;
}