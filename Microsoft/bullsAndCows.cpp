class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,bool> correctPlace;
        int correctPosition =0 ;
        for(int i =0 ; i< secret.size();i++){
            if(secret[i]==guess[i]){
                correctPlace[i]= 1;
                correctPosition++;
            }
        }
        unordered_map<char,int> mp;
        for(int i =0 ; i < secret.size();i++){
            if(correctPlace.find(i)==correctPlace.end()){
                mp[secret[i]]++;
            }
        }
        int correct =0; 
        for(int i =0 ; i < guess.size();i++){
            if(correctPlace.find(i)==correctPlace.end()){
                if(mp[guess[i]]>0){
                    correct++;
                    mp[guess[i]]--;
                }
            }
        }
        string ans = "";
        ans+=to_string(correctPosition);
        ans+='A';
        ans+=to_string(correct);
        ans+='B';
        return ans;
    }
};
