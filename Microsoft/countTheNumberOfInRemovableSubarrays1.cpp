class Solution {
public:
    int checkIncreasing(vector<int>&nums , int i , int j){
        int prev= -1;
        for(int  k =0 ; k<nums.size();k++){
            if(k<i || k>j){
                if(prev>=nums[k]){
                    return false;
                }else{
                    prev = nums[k];
                }
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans =0 ; 
        for(int i =0 ; i <nums.size(); i++){
            for(int j = i ; j <nums.size();j++){
                if(checkIncreasing(nums, i, j)==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};
