// Solution for Problem-1 in c++ as follows:- 

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isPossible(vector<int>& v) {
    unordered_map<int, int> freq;

    for (int x : v) freq[x]++;

    unordered_map<int, int> need;

    for (int n : v) {
        if (freq[n] == 0) continue;

        if (need[n] > 0) { 
            need[n]--;
            freq[n]--;

            need[n + 1]++;
        } 
        else if (freq[n] > 0 && freq[n + 1] > 0 && freq[n + 2] > 0) {
            freq[n]--;
            freq[n + 1]--;
            freq[n + 2]--;
            need[n + 3]++;
        } 
        else {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(isPossible(v)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}
