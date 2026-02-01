# 问题3：最长公共子序列（Longest Common Subsequence, LCS）

## 难度：中等偏难

## 问题描述

给定两个字符串 `s1` 和 `s2`，找出它们的最长公共子序列的长度。

一个字符串的子序列是指，通过删除原字符串中的某些字符（可以不删除）但不改变剩余字符的相对位置，所得到的新字符串。

### 输入格式
- 第一行包含字符串 s1
- 第二行包含字符串 s2

### 输出格式
- 输出一个整数，表示最长公共子序列的长度

### 数据范围
- 1 ≤ len(s1), len(s2) ≤ 1000
- 字符串仅包含小写字母

## 样例

### 样例输入1
```
abcde
ace
```

### 样例输出1
```
3
```
说明：最长公共子序列是 "ace"，长度为3

### 样例输入2
```
abc
abc
```

### 样例输出2
```
3
```

### 样例输入3
```
abc
def
```

### 样例输出3
```
0
```

## 解题思路

### 动态规划（Dynamic Programming）

定义状态：`dp[i][j]` 表示 s1 的前 i 个字符和 s2 的前 j 个字符的最长公共子序列长度。

**状态转移方程**：
- 如果 `s1[i-1] == s2[j-1]`，则 `dp[i][j] = dp[i-1][j-1] + 1`
- 否则，`dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

**初始状态**：
- `dp[0][j] = 0`（s1为空串）
- `dp[i][0] = 0`（s2为空串）

**时间复杂度**：O(m × n)，其中 m 和 n 分别是两个字符串的长度  
**空间复杂度**：O(m × n)，可以优化到 O(min(m, n))

## 参考代码

### C++ 解法

```cpp
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
```

### Python 解法

```python
def longest_common_subsequence(s1, s2):
    m, n = len(s1), len(s2)
    
    # 创建DP表
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # 填充DP表
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]

# 输入
s1 = input().strip()
s2 = input().strip()

# 输出
print(longest_common_subsequence(s1, s2))
```

### 空间优化版本（C++）

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    // 只使用两行空间
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = prev[j-1] + 1;
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        swap(prev, curr);
    }
    
    return prev[n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << longestCommonSubsequence(s1, s2) << endl;
    
    return 0;
}
```

## 如何输出具体的LCS序列

```cpp
string getLCS(string s1, string s2, vector<vector<int>>& dp) {
    string result = "";
    int i = s1.length(), j = s2.length();
    
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result = s1[i-1] + result;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return result;
}
```

## 知识点
- 动态规划
- 二维DP
- 空间优化技巧
- 字符串处理

## 相关问题
1. **最长公共子串**（要求连续）
2. **编辑距离**（Levenshtein Distance）
3. **最长上升子序列**（LIS）
4. **最短公共超序列**

## 扩展思考
1. 如果要求输出所有可能的LCS怎么办？
2. 能否将空间复杂度优化到 O(n)？
3. 三个字符串的LCS如何求解？
4. 如何判断一个字符串是否是另外两个字符串的公共子序列？
