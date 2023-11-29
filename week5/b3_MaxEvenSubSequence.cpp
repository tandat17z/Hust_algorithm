#include<bits/stdc++.h>
using namespace std;
int A[1000001];

long total_even[1000001];
long total_odd[1000001];
bool ch_e, ch_o;

int main(){
    freopen("data3.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    long res = -1e9;
    for( int i = 1; i<=n ;i++){
        scanf("%d", &A[i]);

        if( A[i] % 2  == 0){
            total_even[i] = (total_even[i-1] > 0)? total_even[i-1] + A[i]: A[i];
            if( ch_o ) total_odd[i] = A[i] + total_odd[i-1];
            ch_e = true;
        }
        else{
            total_odd[i] = (total_even[i-1] > 0)? total_even[i-1] + A[i]: A[i];
            if( ch_o ) total_even[i] = A[i] + total_odd[i-1];
            else ch_e = false;
            ch_o = true;
        }
        
        res = max(res, total_even[i]);
    }
    printf("%ld", res);
    return 0;
}