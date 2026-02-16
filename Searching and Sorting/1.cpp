//  ██████╗  ██╗  ██╗ ████████╗ █████╗  ██╗     
// ██╔════╝  ██║  ██║     ██║  ██╔══██╗ ██║     
// ╚█████╗   ██║  ██║     ██║  ███████║ ██║     
//  ╚═══██╗  ██║  ██║ ██╗ ██║  ██╔══██║ ██║     
// ██████╔╝  ╚█████╔╝╚█████╔╝  ██║  ██║ ███████╗
// ╚═════╝     ╚════╝  ╚════╝   ╚═╝  ╚═╝ ╚══════╝

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

void solve() {
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
    if(i == 0 || v[i] != v[i-1])
        ans++;
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t--)
        solve();

    return 0;
}
