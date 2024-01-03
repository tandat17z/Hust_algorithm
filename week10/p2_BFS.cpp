#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> a;
bool visited[100000];

void input(){
    scanf("%d %d", &n, &m);
    a = vector<set<int>>(n + 1);

    for( int _ = 0; _ < m; _ ++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].insert(v);
        a[v].insert(u);
    }
}

void bfs(int k){
    queue<int> q;
    q.push(k);
    visited[k] = true;

    while( q.empty() != true){
        int x = q.front(); q.pop();
        printf("%d ", x);
        
        for( auto i : a[x]){
            if( visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    freopen("input/data2.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    for( int i = 1; i<= n; i++){
        if( visited[i] == false) bfs(i);
    }

    return 0;
}