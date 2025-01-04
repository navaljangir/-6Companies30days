class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string str= "";
        str = s.substr(0, 10);
        unordered_map<string,int> mp;
        mp[str]++;
        for(int i =10;  i < s.length(); i++){
            str = str.substr(1);
            str+=s[i];
            mp[str]++;
        }
        vector<string> ans;
        for(auto i : mp){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;

    }
};
