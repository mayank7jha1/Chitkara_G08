#include<iostream>
#include<vector>
using  namespace std;



class Solution {
public:
    int solve(int i, vector<int> &energy, int k, vector<int> &dp) {
        if (i >= energy.size())    return 0;

        if (dp[i] != -1) return dp[i];

        int ans = energy[i] + solve(i + k, energy, k, dp);
        return dp[i] = ans;
    }


    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxEnergy = INT_MIN;

        vector<int> dp(n + 1, -1);
        for (int i = 0; i < n; i++) {
            maxEnergy = max(maxEnergy, solve(i, energy, k, dp));
        }
        return maxEnergy;
    }


};


int main() {

}