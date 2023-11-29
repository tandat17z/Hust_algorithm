#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
int n, m;
vector<int> A[N];
bool visited[N];
int num[N];
int low[N];

int t;
vector<pair<int, int>> bridges;

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d %d", &n, &m);
    for( int i = 1; i <= m; i ++){
        int u, v;
        scanf("%d %d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void dfs(int s, int ps){
    t ++;
    num[s] = t;
    low[s] = num[s];
    visited[s] = true;
    for( int i = 0; i< A[s].size(); i++){
        int v = A[s][i];
        if( v == ps) continue;
        if( visited[v] ){
            low[s] = min(low[s], num[v]);
        }else{
            dfs(v, s);
            low[s] = min(low[s], low[v]);
            if( low[v] > num[s]){
                bridges.push_back(make_pair(s, v));
            }
        }
    }
}

void init(){
    for( int v = 1; v <= n; v++) visited[v] = false;
}
void solve(){
    init();
    t = 0;
    for( int s = 1; s <= n; s++){
        if( !visited[s]) dfs(s, -1);
    }
    cout << "bridges = ";
    for( int i = 0; i < bridges.size(); i++){
        cout << "(" << bridges[i].first << ", " << bridges[i].second << ")";
    }
}
int main(){
    freopen("input/data6.txt", "r", stdin);

    input();
    solve();

    return 0;
}