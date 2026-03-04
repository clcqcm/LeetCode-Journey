"""
题目：977.有序数组的平方
链接：https://leetcode.cn/problems/squares-of-a-sorted-array/
时间复杂度：O(n^2) 
空间复杂度：O(1)

【踩坑记录 & 思路总结】
- 体会：选择排序不熟练且效率低。
- 正解：用双指针进行排序并将结果储存到新的数组中，以空间换时间。
- 关键点：双指针。
"""
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int min=0,t=0,m;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        for(int i=0;i<nums.size()-1;i++){
            min=nums[i];
            m=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<=min){
                    min=nums[j];
                    m=j;
                }
            }
            t=nums[i];
            nums[i]=min;
            nums[m]=t;
        }
        return nums;
    }
};
改进（双指针）：
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int left=0,right=n-1;
        for(int i=n-1;i>=0;i--){
            if(abs(nums[left])>abs(nums[right])){
                res[i]=nums[left]*nums[left];
                left++;
            }
            else{
                res[i]=nums[right]*nums[right];
                right--;
            }
        }
        return res;
    }
};