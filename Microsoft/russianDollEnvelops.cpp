class Solution {
public:
    static bool comp(vector<int> &a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , comp);
        vector<int> v;
        int curr =0 ;
        for(int i= 0 ;i <envelopes.size();i++){
            int width = envelopes[i][1];
            if(v.empty() || (v.back()<width && curr != envelopes[i][0])){
                curr = envelopes[i][0];
                v.push_back(width);
            }else if(width < v.back()){
                int findIndex = lower_bound(v.begin() , v.end(), width) - v.begin();
                v[findIndex]= width;
            }
        }
        return v.size();
    }
};
