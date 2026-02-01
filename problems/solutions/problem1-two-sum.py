"""
问题1：两数之和
使用哈希表解法
时间复杂度：O(n)
空间复杂度：O(n)
"""

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
