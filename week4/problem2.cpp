#include<bits/stdc++.h>
using namespace std;

int n, m;
int period[17];
int load[6];
int A[17][17];
int c[17];
int min_load = 1e9;

void input(){
    cin >> n >> m;
    for( int i = 1; i<= n ; i++){
        cin >> c[i];
    }

    for( int i =1; i<=n ; i++){
        for( int j = 1; j<= n; j++){
            cin >> A[i][j];
        }
    }
}

bool check(int i, int k){
    for( int j = 1; j < k; j++){
        if( A[k][j] == 1 && period[j] <= i) return false;
        if( A[j][k] == 1 && period[j] >= i) return false;
    }
    return true;
}
void solution(){
    int max_load = 0;
    for( int i = 1; i<= m; i++){
        max_load = max(max_load, load[i]);
    }
    if( max_load < min_load) min_load = max_load;
}
void Try(int k){
    for( int i = 1; i<=m ; i++){
        if( check(i, k)){
            period[k] = i;
            load[i] += c[k];
            if( load[i] < min_load){
                if( k == n) solution();
                else Try(k + 1);
            }
            period[k] = 0;
            load[i] -= c[k];
        }
    }
}
int main(){
    freopen("data2.txt", "r", stdin);
    input();
    Try(1);
    cout << endl << min_load;
    return 0;
}
