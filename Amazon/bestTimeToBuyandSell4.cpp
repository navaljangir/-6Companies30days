class Solution {
public:
    int solve(vector<int>&prices ,  int i , int buy ,int cap , int &k , vector<vector<vector<int>>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(cap>k){
            return 0;
        }
        if(dp[i][cap][buy]!=-1){
            return dp[i][cap][buy];
        }
        int ans1 =0 ;
        if(buy==0){
            ans1 = -prices[i] + solve(prices , i+1 , 1 , cap+1 ,k ,dp);
        }
        if(buy==1){
            ans1=  prices[i] + solve(prices ,i+1 , 0 ,cap , k ,dp);
        }
        int ans2 = solve(prices , i+1 , buy ,cap , k ,dp);
        return dp[i][cap][buy] = max(ans1 , ans2);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(prices ,0 ,0, 0 , k ,dp);
    }
};
