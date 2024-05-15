#include<iostream>
#include<vector>
using  namespace std;



class Solution {
    int dp[1000][1000];
public:
    int maxScore(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        dp[n - 1][m - 1] = a[n - 1][m - 1];
        int maxans = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1) {
                    continue;
                } else if (i == n - 1) {
                    dp[i][j] = max(a[i][j], dp[i][j + 1]);
                    int ans = dp[i][j + 1] - a[i][j];
                    maxans = max(ans, maxans);

                }
                else if (j == m - 1) {
                    dp[i][j] = max(a[i][j], dp[i + 1][j]);
                    int ans = dp[i + 1][j] - a[i][j];
                    maxans = max(ans, maxans);

                }
                else {
                    dp[i][j] = max(a[i][j], max(dp[i + 1][j], dp[i][j + 1]));

                    int ans = max(dp[i + 1][j], dp[i][j + 1]) - a[i][j];
                    maxans = max(ans, maxans);

                }
            }
        }

        return maxans;
    }

};

int main() {

}
