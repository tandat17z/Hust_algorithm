#include<bits/stdc++.h>
using namespace std;

int n, k1, k2;
int M[1001];// chuỗi bit thỏa mãn bắt đầu bằng 1

int computeM(int x){
    if( x < 0) return 0;
    if( M[x] ) return M[x];
    if( x >= k1 && x <= k2) M[x] = 1; // Luôn có 1 lựa chọn là tất cả các bit = 1
    
    for( int i = k1; i<= k2; i++){
        M[x] += computeM(x - i - 1);
    }
    return M[x];
}

int main(){
    scanf("%d %d %d", &n, &k1, &k2);
    M[0] = 1; //------------------------------
    cout << computeM(n) + computeM(n-1);
    return 0;
}