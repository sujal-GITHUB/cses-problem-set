//  ██████╗  ██╗  ██╗ ████████╗ █████╗  ██╗     
// ██╔════╝  ██║  ██║     ██║  ██╔══██╗ ██║     
// ╚█████╗   ██║  ██║     ██║  ███████║ ██║     
//  ╚═══██╗  ██║  ██║ ██╗ ██║  ██╔══██║ ██║     
// ██████╔╝  ╚█████╔╝╚█████╔╝  ██║  ██║ ███████╗
// ╚═════╝     ╚════╝  ╚════╝   ╚═╝  ╚═╝ ╚══════╝
 
#include <iostream>
#include <vector>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
 
template<typename T> void ip(T &x){ cin >> x; }
template<typename T> void ip(vector<T> &v){ for(auto &x : v) cin >> x; }
 
int n;
vector<ll>dp;
int mod = 1e9+7;
 
ll f(int sum){
    if(sum == n){
        return 1;
    }
 
    if(dp[sum] != -1)
    return dp[sum];
 
    ll cnt = 0;
    for(int i=1; i<=6; i++){
        if(sum+i <= n){
            cnt = (cnt + f(sum+i))%mod;
        }
    }
 
    return dp[sum] = cnt;
}
 
void solve(){
    cin >> n;
    dp.resize(n, -1);
    cout << f(0) << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
 
    while(t--) 
    solve();
 
    return 0;
}