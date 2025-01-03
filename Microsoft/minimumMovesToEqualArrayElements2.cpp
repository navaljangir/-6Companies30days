class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int mid = nums.size()/2;
        int median = nums[mid];
        if(nums.size()%2==0){
            median = (nums[mid]+nums[mid-1])/2;
        }
        int ans =0 ; 
        for(int i =0; i <nums.size();i++){
            ans+=(abs(median - nums[i]));
        }
        return ans;
    }
};
