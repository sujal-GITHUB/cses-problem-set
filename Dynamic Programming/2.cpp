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
 
int n, x;
vector<vector<ll>>dp;
int mod = 1e9+7;
 
void solve(){
    cin >> n >> x;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
 
    if(n == 0){
        cout << (x == 0 ? 0 : -1) << "\n";
        return;
    }
 
    const ll INF = 1e8;
 
    vector<ll> next(x + 1, INF), curr(x + 1, INF);
 
    // Base: last coin
    for(int sum = 0; sum <= x; sum++){
        if(nums[n-1] != 0 && (x - sum) % nums[n-1] == 0)
            next[sum] = (x - sum) / nums[n-1];
        else
            next[sum] = INF;
    }
 
    // Other coins
    for(int idx = n - 2; idx >= 0; idx--){
        curr[x] = 0;
        for(int sum = x; sum >= 0; sum--){
            ll skip = next[sum];
            ll take = INF;
 
            if(sum + nums[idx] <= x)
                take = 1 + curr[sum + nums[idx]];
 
            curr[sum] = min(take, skip);
        }
        next = curr;
    }
 
    cout << (next[0] >= INF ? -1 : next[0]) << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
 
    while(t--) 
    solve();
 
    return 0;
}