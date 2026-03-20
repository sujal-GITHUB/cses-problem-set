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

void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&subordinates){
    int cnt = 0;

    for(auto n: adj[node]){
        if(n != parent){
            dfs(n, node, adj, subordinates);
            cnt += 1 + subordinates[n];
        }
    }

    subordinates[node] = cnt;
}

void solve() {
    int n;
    cin>>n;

    vector<int>bosses(n-1);
    for(auto &a : bosses){
        cin>>a;
    }

    vector<int>subordinates(n+1);
    vector<vector<int>>adj(n+1);
    for(int i=2; i<=n; i++){
        adj[bosses[i-2]].push_back(i);
    }

    dfs(1, 0, adj, subordinates);
    for(int i = 1; i <= n; i++){
        cout << subordinates[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t--)
        solve();

    return 0;
}
