# 问题1：两数之和（Two Sum）

## 难度：入门

## 问题描述

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那两个整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两次。

### 输入格式
- 第一行包含两个整数 n 和 target，分别表示数组长度和目标值
- 第二行包含 n 个整数，表示数组元素

### 输出格式
- 输出两个整数，表示两个数的下标（下标从0开始）

### 数据范围
- 2 ≤ n ≤ 10^4
- -10^9 ≤ nums[i] ≤ 10^9
- -10^9 ≤ target ≤ 10^9

## 样例

### 样例输入1
```
4 9
2 7 11 15
```

### 样例输出1
```
0 1
```

### 样例输入2
```
3 6
3 2 4
```

### 样例输出2
```
1 2
```

## 解题思路

### 方法1：暴力枚举（时间复杂度 O(n²)）
遍历每个元素 x，并查找是否存在一个值与 target - x 相等的目标元素。

### 方法2：哈希表（时间复杂度 O(n)）
使用哈希表存储已经遍历过的元素及其下标。对于每个元素，检查 target - nums[i] 是否在哈希表中。

## 参考代码

### C++ 解法（哈希表）

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    unordered_map<int, int> hash;
    
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (hash.count(complement)) {
            cout << hash[complement] << " " << i << endl;
            return 0;
        }
        hash[nums[i]] = i;
    }
    
    return 0;
}
```

### Python 解法

```python
def two_sum(nums, target):
    hash_map = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in hash_map:
            return [hash_map[complement], i]
        hash_map[num] = i
    return []

# 输入
n, target = map(int, input().split())
nums = list(map(int, input().split()))

# 求解
result = two_sum(nums, target)
print(result[0], result[1])
```

## 知识点
- 哈希表
- 数组遍历
- 时间复杂度优化

## 扩展思考
1. 如果要求找出所有和为 target 的数对怎么办？
2. 如果数组是有序的，能否有更优的解法？
3. 如果要找三个数的和等于 target 呢？（Three Sum问题）
