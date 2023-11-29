#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int n;
int a[1000000];
int ta[1000000];

int merge(int l, int m, int r){
    int count = 0;
    int i = l, j = m;
    for( int k = l; k < r; k++){
        if( i >= m){
            ta[k] = a[j]; j ++;
        }
        else if( j >= r){
            ta[k] = a[i]; i++;
        }
        else if( a[i] > a[j] ){
            ta[k] = a[j]; j++;
            count = (count + (m - i))%P;
        }
        else{
            ta[k] = a[i]; i++;
        }
    }
    for( int k = l; k < r; k++){
        a[k] = ta[k];
    }
    return count;
}

int inversion(int l, int r){
    if( r - l <= 1) return 0;
    int m = (l + r)/2;
    return ((inversion(l, m) + inversion(m, r))%P + merge(l, m, r) )%P;
}
int main(){
    freopen("data5.txt", "r", stdin);
    scanf("%d", &n);
    for( int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    cout << inversion(0, n);
    return 0;
}