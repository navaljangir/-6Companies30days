class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int j =0;
        int prev = 0 ;
        bool findInc = true;
        for(int i=1 ; i < arr.size();i++){
            if(i-1>=0 && i+1<arr.size()  && arr[i]> arr[i-1] && arr[i]>arr[i+1]){
                int k = i + 2;
                while(k<arr.size() && arr[k-1]>arr[k]){
                    k++;
                }
                ans= max(ans , k-j);
                i = k-1;
                j = i;
            }else if(i-1>=0 && arr[i-1]<arr[i]){
                continue;
            }else{
                j =i;
            }
        }
        return ans;
    }
};
