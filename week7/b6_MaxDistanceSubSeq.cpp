#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;

int t;
int n, c;
int x[N];

bool check(int d){
    int last = 1, count = 0;
    while( last <= n){
        count += 1;
        if( count >= c) return true;
        
        int _ = last++;
        while( last <= n && x[last] - x[_] < d){
            last += 1;
        }
    }
    return false;
}

int findD(){
    int l = 0, r = x[n] - x[1];
    while( l <= r){
        int d = (l + r)/2;
        if( check(d)) l = d + 1;
        else r = d - 1;
    }
    return r;
}
int main(){
    scanf("%d", &t);
    for( int _ = 0; _ < t; _ ++){
        scanf("%d %d", &n, &c);
        for( int i = 1; i <= n; i++){
            scanf("%d", &x[i]);
        }
        sort(x + 1, x + n + 1);
        printf("%d\n", findD());
    }
    return 0;
}