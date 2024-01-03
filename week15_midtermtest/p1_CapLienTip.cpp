#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int n;
vector<int> s;
int len[100001];

void input(){
    scanf("%d", &n);
    for( int i = 1; i<=n ;i++){
        int u;
        scanf("%d", &u);
        len[u] += 1;
        if(len[u] == 1) s.push_back(u);
    }
}

void solve(){
    int res = 0;
    sort(s.begin(), s.end());
    int i = 0, j = 1;
    while(j < s.size()){
        if( i == j ) j += 1;
        else{
            if( s[j] - s[i] == 1){
                res = (res + len[s[i]]*len[s[j]])%P;
                j += 1;
            } 
            i += 1;
        }
    }
    
    printf("%d", res);
}

int main(){
    freopen("input/data1.txt", "r", stdin);
    input();
    solve();
    return 0;
}