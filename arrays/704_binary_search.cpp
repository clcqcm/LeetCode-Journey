"""
题目：704. 二分查找 (Binary Search)
链接：https://leetcode.cn/problems/binary-search/
时间复杂度：O(log n) 
空间复杂度：O(1)

【踩坑记录 & 思路总结】
- 误区：一开始没注意是升序数组。
- 正解：用二分法查找。
- 关键点：mid=left+(right-left)/2。
"""

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid;
        while(right>=left)
        {
            mid=(right-left)/2+left;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else 
                return mid;
        }
        return -1;
    }
};