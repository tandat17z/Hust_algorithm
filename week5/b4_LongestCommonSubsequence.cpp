#include<bits/stdc++.h>

using namespace std;

#define N 10001

int X[N], Y[N];
int n, m;
int S[N][N];
int pa[N][N];

void input(){
    scanf("%d %d", &n, &m);
    for( int i = 1; i<= n ;i++){
        scanf("%d", &X[i]);
    }
    for( int i = 1; i<= m ;i++){
        scanf("%d", &Y[i]);
    }
}

int main(){
    freopen("data4.txt", "r", stdin);
    input();

    for( int i = 1; i<= n; i++){
        for( int j = 1; j <= m ; j++){
            if( X[i] == Y[j]){
                pa[i][j] = 1;
                S[i][j] = S[i-1][j-1] + 1;
            }
            else{
                S[i][j] = max(S[i-1][j], S[i][j-1]);
                if( S[i][j] == S[i][j-1] ) pa[i][j] = 2;
                else pa[i][j] = 3;
            }
        }
    }
    printf("%d", S[n][m]);
    
    // Truy vet---------------------
    int p = pa[n][m];
    int i = n, j = m;
    stack<int> st;
    while( p != 0){
        if( p == 1){
            st.push(X[i]);
            i--; j--;
        }
        else if( p == 2){
            j--;
        }
        else{
            i--;
        }
        p = pa[i][j];
    }
    while( !st.empty() ){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}