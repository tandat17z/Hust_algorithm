#include<bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
int n;
int num[1000001];
vector<int> arr;

void input(){
    scanf("%d", &n);
    for( int i = 1; i<=n; i++){
        int u;
        scanf("%d", &u);
        if(num[u] == 0) arr.push_back(u); // nếu u chưa xuất hiện
        num[u] += 1;// đếm số lượng u
    }
}

void solve(){
    int res = 0;
    sort(arr.begin(), arr.end());
    for(int i =1; i<arr.size(); i++){
        // cout << arr[i] << " " << num[i] << endl;
        if( arr[i] - arr[i-1] == 1) {
            res += (num[arr[i]]*num[arr[i-1]])%P; 
            res = res %P;
        }
    }
    cout << res;
}

int main(){
    freopen("input/data1.txt", "r", stdin);
    input();
    solve();
}