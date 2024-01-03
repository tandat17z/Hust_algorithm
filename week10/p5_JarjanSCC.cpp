#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, m;
vector<int> adj[N];

int num[N], low[N];// Dùng cho Jarjan
int t = 0; // Thời gian -> tính thời điểm duyệt qua các node

int scc = 0; // số thành phần liên thông
stack<int> st;
bool checkSt[N];

void input(){
    freopen("input/data5.txt", "r", stdin);
    cin >> n >> m;
    for( int i = 0; i<m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void dfs(int u){
    t += 1;
    num[u] = t; low[u] = t;
    st.push(u); checkSt[u] = true;

    for( auto v : adj[u]){
        if( num[v] == 0) {// v chưa được duyệt qua
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if( checkSt[v] )
            low[u] = min(low[u], num[v]);
    }

    //Duyệt xong đỉnh u
    if( low[u] == num[u]){
        scc += 1; 
        // in ra thành phần liên thông
        // cout << scc << endl;
        while( true){
            // cout << st.top() << " ";
            int x = st.top();
            checkSt[x] = false;
            st.pop();
            if( u == x) break;
        }
    }
}

void solve(){
    t = 0; scc = 0;
    for( int u = 1; u<=n; u++){
        if( num[u] == 0) dfs(u);
    }
    cout << scc;
}
int main(){
    input();
    solve();
    return 0;
}