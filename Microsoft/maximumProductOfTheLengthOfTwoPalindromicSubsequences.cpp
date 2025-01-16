class Solution {
public:
    bool isPalindrome(string &str){
        int i =0 ; 
        int j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s , int index ,  string &str1 , string &str2 ){
        if(index>=s.length()){
            if(isPalindrome(str1) && isPalindrome(str2)){
                return str1.size() * str2.size();
            }
            return 0;
        }
            str1+=s[index];
            int include1 = solve(s , index+1,  str1, str2);
            str1.pop_back();
            str2+=s[index];
            int include2 = solve(s, index+1 , str1 , str2);
            str2.pop_back(); 
            int exclude= solve(s , index+1 ,str1, str2);
            return max({include1 , include2 , exclude});  
    }
    int maxProduct(string s) {
        string s1 ="";
        string s2 ="";
        int ans = solve(s ,0 , s1 ,s2 );
        return ans;
    }
};
