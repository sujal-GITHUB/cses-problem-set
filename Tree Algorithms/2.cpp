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

vector<vector<int>>adj;
vector<bool>vis;
int cnt = 0;

void dfs(int node, int parent){
    for(auto c : adj[node]){
        if(c == parent) 
        continue;

        dfs(c, node);

        if(!vis[node] && !vis[c]){
            cnt++;
            vis[node] = vis[c] = 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    adj.resize(n+1);
    vis.resize(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    cout<<cnt<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t--)
        solve();

    return 0;
}
