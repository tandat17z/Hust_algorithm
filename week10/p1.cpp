#include<bits/stdc++.h>

using namespace std;

#define N 1000000007
#define llu long long unsigned

int main(){
    freopen("input/data1.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char c, c_ = '+';
    string s = "";
    llu sum = 0;
    llu p = 1;
    while( cin >> c ){
        if( c >= '0' && c <= '9'){
            s.push_back(c);
        }
        else if( c_ < '0' || c_ > '9' ){
            cout << "NOT_CORRECT";
            return 0;
        }
        else if( c == '*'){
            llu x = stoi(s); s = "";
            p = (p * (x % N)) % N;
            // p *= x;
        }
        else if( c == '+'){
            llu x = stoi(s); s = "";
            sum = (sum + (p * (x%N))%N ) % N;
            // sum = sum + p*x;
            p = 1;
        }
        c_ = c;
    }
    llu x = stoi(s);
    cout << (sum+ (p * (x%N))%N ) % N;
    // cout << (sum + p * x) % N;
    return 0;
}