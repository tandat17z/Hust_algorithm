#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> d;

int main(){
    int n;
    scanf("%d", &n);
    queue<int> q;
    q.push(n);
    d[n] = 0;
    while( !q.empty() ){
        int u = q.front(); q.pop();
    
        if( u + 2 == 0 || u - 5 == 0) {
            cout << d[u] + 1;
            return 0;
        }
        
        if( d[u + 2] == 0){
            d[u + 2] = d[u] + 1;
            q.push(u + 2);
        }
        if( d[u - 5] == 0){
            d[u - 5] = d[u] + 1;
            q.push(u - 5);
        }
        
    }
    return 0;
}