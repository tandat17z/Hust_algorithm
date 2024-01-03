#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int n;
int a[N];
int maxVal[N << 2] ; // size  = N * 4

int getMaxFromNode(int id, int left, int right, int x, int y){
    // retrieve the max value of interval [x, y] from node id
    if(x > right || y < left) return 0;
    if(x <= left && right <= y) return maxVal[id];
    int mid = (left + right) / 2;
    int leftId = id * 2;
    int rightId = id * 2 + 1;
    int maxLeft = getMaxFromNode(leftId, left, mid, x, y);
    int maxRight = getMaxFromNode(rightId, mid + 1, right, x, y);
    return max(maxLeft, maxRight);
}

int getMax(int x, int y){
    return getMaxFromNode(1, 1, n, x, y);
}

void updateFromNode(int id, int left, int right, int index, int value){
    if(left > right) return;
    if(left > index || right < index) return;
    if(left == right){
        maxVal[id] = value;
        return;
    }
    int leftId = id * 2;
    int rightId = id * 2 + 1;
    int m = (left + right) / 2;
    updateFromNode(leftId, left, m, index, value);
    updateFromNode(rightId, m + 1, right, index, value);
    maxVal[id] = max(maxVal[leftId], maxVal[rightId]);
}

void update(int i, int value)
{
    updateFromNode(1, 1, n, i, value);
}

void solve(){
    memset(maxVal, 0, sizeof(maxVal));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        update(i, a[i]);
    }
    int m; cin >> m;
    char cmd[20];
    for (int k = 1; k <= m; k++)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "update") == 0){
            int i, v; scanf("%d%d", &i, &v);
            a[i] = v;
            update(i, v);
        }
        else if (strcmp(cmd, "get-max") == 0){
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", getMax(l, r));
        }
    }
}

int main(){
    solve();
    
    return 0;
}