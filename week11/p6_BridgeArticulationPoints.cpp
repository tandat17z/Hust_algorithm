#include<bits/stdc++.h>
using namespace std;

const int N = 50000;
int n, m;
vector<int> A[N];
bool visited[N];
int num[N];
int low[N];

int t;
vector<pair<int, int>> bridges;
unordered_set<int> aPoints;
int root;

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
    int cnt = 0;
    for( int i = 0; i< A[s].size(); i++){
        int v = A[s][i];
        if( v == ps) continue; // bỏ qua cha ps của v
        if( visited[v] ){ // back edge là sv
            low[s] = min(low[s], num[v]);
        }else{
            cnt += 1;
            dfs(v, s);
            low[s] = min(low[s], low[v]);
            if( low[v] > num[s]){
                bridges.push_back(make_pair(s, v));
            }
            if( low[v] >= num[s] && ps != -1){
                aPoints.insert(s);
            }
        }
    }
    if( cnt > 1 && ps == -1) aPoints.insert(s);
}

void init(){
    for( int v = 1; v <= n; v++) visited[v] = false;
}
void solve(){
    init();
    t = 0;
    for( int s = 1; s <= n; s++){
        if( !visited[s]) {
            root = s;
            dfs(s, -1);
        }
    }
    // cout << "bridges = ";
    // for( int i = 0; i < bridges.size(); i++){
    //     cout << "(" << bridges[i].first << ", " << bridges[i].second << ")";
    // }
    // for( auto i : aPoints){
    //     cout << i << " ";
    // }
    // cout << endl;
    printf("%d %d", aPoints.size(), bridges.size());
}
int main(){
    freopen("input/data6.txt", "r", stdin);

    input();
    solve();

    return 0;
}