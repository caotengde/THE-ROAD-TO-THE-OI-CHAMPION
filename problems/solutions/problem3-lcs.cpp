/*
 * 问题3：最长公共子序列
 * 动态规划解法
 * 时间复杂度：O(m * n)
 * 空间复杂度：O(m * n)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    // dp[i][j] 表示 s1[0..i-1] 和 s2[0..j-1] 的LCS长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << longestCommonSubsequence(s1, s2) << endl;
    
    return 0;
}
