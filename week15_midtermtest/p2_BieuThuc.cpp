#include<bits/stdc++.h>
using namespace std;

const long long P = 1e9 + 7;
int n;
long long a[200001];

void input(){
    scanf("%d", &n);
    for( int i = 0; i<n; i++) scanf("%lld", &a[i]);
}

void solve(){
    long long res = 0; // đáp án
    long long product = 1;
    int mark = 1; // nhớ dấu trước đó đối với chuỗi phép nhân
    
    int m;
    for( int i =1; i<n; i++){
        scanf("%d", &m);
        if( m == 0 || m == 1){// dấu trừ
            if(mark == 0){ // dấu trừ
                res = res - (product*a[i-1]);
            }
            else if (mark == 1){
                res = res + (product*a[i-1]);
            }
            res = res % P;
            if( res < 0 ) res += P;
            product = 1;
            mark = m;
        }
        else if (m == 2){// dấu nhân
            product = (product*a[i-1])%P;
        }
    }

    if( m == 0 ) res -= a[n-1];
    else if( m == 1 ) res += a[n-1];
    else if( m == 2){
        if(mark == 0){ // dấu trừ
            res = res - (product*a[n-1]);
        }
        else if (mark == 1){
            res = res + (product*a[n-1]);
        }
    }
    if( res < 0 ) res += P;
    printf("%lld", res % P);
}

int main(){
    freopen("input/data2.txt", "r", stdin);
    input();
    solve();
    return 0;
}