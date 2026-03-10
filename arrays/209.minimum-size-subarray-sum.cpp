1.蛮力法：时间复杂度n²，超时
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int m=INT_MAX,sum=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>=target){
                    m=min(m,j-i+1);
                    break;
                }
            }
        }
        return m==INT_MAX?0:m;
    }
};
2.滑动窗口：时间复杂度n
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,m=INT_MAX,n=nums.size(),sum=0;
        while(end<n){
            sum+=nums[end];
            while(sum>=target){
                m=min(m,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return m==INT_MAX?0:m;
    }
};
3.二分法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),m=INT_MAX;
        vector<int> sum(n+1);
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++){
            int s=target+sum[i-1];
            auto bound=lower_bound(sum.begin(),sum.end(),s);
            if(bound!=sum.end()){
                m=min(m,static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return m==INT_MAX?0:m;
    }
};