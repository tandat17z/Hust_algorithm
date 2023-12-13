#include<bits/stdc++.h>
using namespace std;

#define N 200000

int n, m;
int d[N];
vector<int> A[N];
vector<int> Ar[N];
bool visited[N];

stack<int> st;
vector<int> list_topo;

int S[N];// S[i] la thoi diem cong viec i co the bat dau thuc hien

void input(){
    scanf("%d %d", &n, &m);
    for( int i =1; i<=n ; i++){
        scanf("%d", &d[i]);
    }
    for( int i =0; i<m ; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        A[u].push_back(v);
    }
}

void dfs(int k){
    visited[k] = true;
    for( auto i : A[k]){
        if( visited[i] == false) dfs(i);
    }
    st.push(k);
}

void dfs(){
    for( int i =1; i<=n; i++){
        if( visited[i] == false) dfs(i);
    }
    // Lay danh sach topo
    while( !st.empty()){
        list_topo.push_back(st.top());
        st.pop();
    }
}
void topoSort(){
    // Sử dụng queue---------------------------------------
}

int solve(){
    dfs();
    // Da co danh sach topo
    int res = 0;
    for( auto u : list_topo){
        for( auto v: A[u]){
            S[v] = max(S[v], S[u] + d[u]);
            res = max(S[v] + d[v], res);
        }
    }
    return res;
}
int main(){
    freopen("input/data4.txt", "r", stdin);
    input();
    cout << solve();
    return 0;
}