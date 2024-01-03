#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> a;
vector<set<int>> a_;
bool visited[100000];
int post[100000];
stack<int> st;

bool check[100000];

void input(){
    scanf("%d %d", &n, &m);
    a = vector<set<int>>(n + 1);
    a_ = vector<set<int>>(n + 1);

    for( int _ = 0; _ < m; _ ++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].insert(v);
        a_[v].insert(u);
    }
}

void explore(int k){
    visited[k] = true;
    // printf("%d ", k);
    for( auto i : a[k]){
        if( visited[i] == false) explore(i);
    }
    st.push(k);
}

void dfs(){
    for( int i = 1; i<=n ;i++){
        if( visited[i] == false) {
            explore(i);
        }
    }
}

void explore_(int k){
    check[k] = true;
    for( auto i : a_[k]){
        if( check[i] == false) explore_(i);
    }
}

int compute(){
    dfs();
    int cnt = 0;
    while ( !st.empty() ){
        int k = st.top();st.pop();
        if( check[k] == false ) {
            cnt += 1;
            explore_(k);
        }
    }
    return cnt;
}
int main(){
    freopen("input/data5.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << compute();

    return 0;
}