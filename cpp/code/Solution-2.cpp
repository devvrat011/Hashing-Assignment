// Solution for Problem-2 in c++ as follows:- 

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubarrayWithSumZero(vector<int>& A) {
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[0] = -1;

    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        if (mp.count(sum)) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"The longest Subarray with zero Sum is: "<<longestSubarrayWithSumZero(A)<<endl;
    return 0;
}
