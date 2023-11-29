#include<bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

int main(){
    int k, n;
    scanf("%d %d", &k, &n);

    vector< vector<int>> d(n + 1, vector<int>(n + 1, 0));
    for( int i = 1; i<= n; i++){
        for( int j = 0; j <= i; j++){
            if( j == 0 || j == i ) d[i][j] = 1;
            else   
                d[i][j] = (d[i-1][j-1]%P + d[i-1][j]%P)%P;
        }
    }
    cout << d[n][k];
    return 0;
}