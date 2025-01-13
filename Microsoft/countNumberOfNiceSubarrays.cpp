class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddNum =0;
        int j =0 ;
        unordered_map<int, int> mp;
         int ans =0 ;
         mp[0] = 1;
        for(int i= 0; i <nums.size();i++){
            if(nums[i]%2!=0){
                oddNum++;
            }
                ans+=mp[oddNum-k];
            mp[oddNum]++;
        }
        return ans;
    }
};
