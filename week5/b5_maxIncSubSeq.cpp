#include<bits/stdc++.h>

using namespace std;

int a[10001];
int S[10001];
int res = 0;
int pa[10001];

int computeS(int i){
    if( i == 1){
        return 1;
    }
    
    if( S[i] != 0) return S[i];

    S[i] = 1;
    for( int j = 1; j<= i-1; j++)
        if(a[j] < a[i]){
            int tmp = computeS(j);
            if( S[i]< tmp + 1) {
                S[i] = tmp + 1;
                pa[i] = j;
            }
        }
    return S[i];
}
int main(){
    freopen("data5.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for( int i = 1; i<=n ;i++){
        scanf("%d", &a[i]);
    }
    int p;
    for( int i = 1; i<= n; i++){
        if( res < computeS(i) ){
            res = computeS(i);
            p = i;
        }

    }
    printf("%d", res);

    //Truy vet ----------------------
    cout << endl;
    while( true){
        cout << a[p] << " ";
        p = pa[p];
        if( p == 0) break;
    }
    return 0;
}