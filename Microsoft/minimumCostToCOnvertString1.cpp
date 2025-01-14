class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> costToChange(26, vector<int>(26,1e9));
        unordered_map<int,vector<int>> adj;
        for(int i =0 ; i<26;i++){
            costToChange[i][i] =0 ;
        }
        for(int i =0 ; i <original.size();i++){
            int originalChar = original[i]-'a';
            int changedChar = changed[i]-'a';
            if(costToChange[originalChar][changedChar]>cost[i]){
                costToChange[originalChar][changedChar]= cost[i];
            }
        }
        long long ans=0;
        for(int helper=0 ; helper< 26;helper++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j< 26;j++){
                    int sum = INT_MAX;
                    if(costToChange[i][helper]!=1e9 && costToChange[helper][j]!=1e9){
                        sum = costToChange[i][helper]+ costToChange[helper][j]; 
                        if(costToChange[i][j] > sum){
                            costToChange[i][j] = sum;
                        }
                    }
                }
            }
        }
        for(int i =0 ; i < source.size();i++){
            int originalChar = source[i]-'a';
            int changedChar = target[i]-'a';
            if(costToChange[originalChar][changedChar]==1e9){
                cout<<originalChar<<" "<<changedChar;
                return -1;
            }
            ans+=costToChange[originalChar][changedChar];
        }
        return ans;
    }
};
