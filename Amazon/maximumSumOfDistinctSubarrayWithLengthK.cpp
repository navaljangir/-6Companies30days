class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int j = 0 ;
        unordered_map<int,int> mp;
        long long ans =0 ;
        for(int i =0 ;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
            while(mp[nums[i]]>1){
                sum-=nums[j];
                mp[nums[j++]]--;
            }
        }
            if(j==0){
                ans = sum;
            }
        for(int i = k;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            while(mp[nums[i]]>1 || i-j+1>k){
                sum-=nums[j];
                mp[nums[j++]]--;
            }
            if(i-j+1==k){
            ans=max(ans , sum);
            }
        }
        return ans;
    }
};
