"""
题目：27. 删除元素
链接：https://leetcode.cn/problems/remove-element/
时间复杂度：O(n) 
空间复杂度：O(1)

【踩坑记录 & 思路总结】
- 关键点：双指针。
"""
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0,i=0,j=0;
        while(j<nums.size()){
            if(nums[j]!=val){
                nums[i]=nums[j];
                j++;
                i++;
                k++;
            }
            else{
                j++;
            }
        }
        return k;
    }
};