#include<bits/stdc++.h>
using namespace std;
int n, k1, k2;
int a[1000001];
int M[1000001];

int main(){
    freopen("data3.txt", "r", stdin);
    scanf("%d %d %d", &n, &k1, &k2);
    for(int i = 1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    int max_gold = 0;

    deque<int> de;
    for( int i = 1; i<= n; i++){
        M[i] = a[i];
        // for( int l = k1; l <= k2 && i - l >= 1; l++){
        //     M[i] = max(M[i], a[i] + M[i-l]);
        // }
        while( !de.empty() && de.front() < i - k2) de.pop_front();
        int j = i -k1;
        if( j >= 1){
            while( !de.empty() && M[de.back()] < M[j]) de.pop_back();
            de.push_back(j);
        }
        M[i] = a[i] + (de.empty() ? 0 : M[de.front()]);
        
        max_gold = max(max_gold, M[i]);
    }
    cout << max_gold;
    return 0;
}