#include<bits/stdc++.h>
using namespace std;

int findAns(vector<int> &nums){
    int cnt = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size()-i-1; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<int> rnums = nums;
    reverse(rnums.begin(), rnums.end());
    int a = findAns(nums);
    int b = findAns(rnums);
    cout << a << " " << b << endl;
}