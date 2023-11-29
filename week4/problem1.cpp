#include<bits/stdc++.h>

using namespace std;

const int N = 1e9 + 7;

int main(){
    freopen("data.txt", "r", stdin);
    string s;
    cin >> s;
    int sum = 0;
    string num;
    for( int i = 0; i<s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9')
            num += s[i];
        else if(s[i] == '+' && i != s.size() - 1 && i != 0){
            sum += stoi(num);
            sum %=N;
            num = "";
        }
        else{
            cout << "NOT_CORRECT";
            return 0;
        }
    }
    sum += stoi(num);
    cout << sum%N;
    return 0;
}
