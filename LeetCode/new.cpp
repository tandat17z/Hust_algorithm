#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target, int &l, int &r){
    int i = (l + r)/2;
    while( l < r){
        if( nums[i] == target) return i;
        if( nums[i] > target) r = i;
        if( nums[i] < target) l = i + 1;
        i = (l + r)/2;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    int i = search(nums, target, l, r);
    
    if( i != -1 ){
        int i1 = i, l1 = l, r1;
        while( true){
            r1 = i1;
            i1 = search(nums, target, l1, r1);
            if( i1 == -1 ) break;
        }

        int i2 = i, r2 = r, l2;
        while( true ){
            l2 = i2 + 1;
            i2 = search(nums, target, l2, r2);
            if( i2 == -1 ) break;
        }

        return vector<int>{r1, l2-1};
    }
    else return vector<int>{-1, -1};
    
}
int main()
{
    vector<int> v{5,7,7,8,8,10};
    vector<int> ans = searchRange(v, 11);
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}