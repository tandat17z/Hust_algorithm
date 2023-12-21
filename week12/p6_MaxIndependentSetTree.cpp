// Sử dụng quy hoạch động trên cây (top-down) --- O(n)

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int n;
int w[N];
vector<int> adj[N];
int pa[N];// pa[u] is the parent of u

int f0[N]; // f0[u] is max independent set (tập con) không chứa u
int f1[N]; // f1[u] is max independent set (tập con) chứa u
int f[N]; // f[u] is max independent set của cây gốc u

void input(){
    cin >> n;
    for( int i = 1; i<=n ; i++){
        cin >> w[i];
    }
    for( int i = 0 ; i<n-1 ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int computeF0(int u){ 
    f0[u] = 0;
    // duyệt qua tất cả các node con trên cây dfs
    for( auto v: adj[u]) if( v != pa[u]){ 
        f0[u] += f[v];
    }
    return f0[u];
}

int computeF1(int u){
    f1[u] = w[u];
    // duyệt qua tất cả các node con trên cây dfs
    for( auto v: adj[u]) if( v != pa[u]){
        f1[u] += f0[v];
    }
    return f1[u];
}

void dfs(int u){
    for( auto v: adj[u]){
        if( pa[v] == 0){
            pa[v] = u;
            dfs(v);
        }
    }
    f[u] = max(computeF0(u), computeF1(u));
}

void solve(){
    int root = 1;
    pa[root] = root;
    dfs(root);
    cout << f[root];
}

int main(){
    freopen("input/data6.txt", "r", stdin);
    input();
    solve();
}