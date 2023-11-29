//CPP 
#include <bits/stdc++.h> 

using namespace std;

int n, sum;
int curr;
vector<int> result;

void print(vector<int> result){
    for( int &it: result){
        cout<< it << " ";
    }
    cout << endl;
}

void Try(int k){
    for( int i = 1; i <= sum - curr - (n - k - 1); i++){
        curr += i;
        result[k] = i;
        if( k == n - 1 && curr == sum) print(result);
        else if(k < n -1) Try(k + 1);
        curr -= i;
    }
}

int main() 
{ 
    cin >> n >> sum;
    result = vector<int>(n);
    Try(0);
    return 0;
}