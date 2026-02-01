/*
 * 问题1：两数之和
 * 使用哈希表解法
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

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
