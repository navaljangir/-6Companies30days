class Solution {
public:
    int getSum(vector<vector<int>>&img  , int row , int col){
        vector<int> a= {-1 , 1, 0, 0 , -1 , 1 , -1 , 1};
        vector<int> b= {0 ,0 , -1 , 1 , -1 , 1 , 1 , -1};
        int n = img.size();
        int m = img[0].size();
        int sum = img[row][col];
        int count=1 ;
        for(int i =0 ; i < 8;i++){
            int newI = row + a[i];
            int newJ = col + b[i];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m){
                sum+=img[newI][newJ];
                count++;
            }
        }
        return (sum/count);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size() , vector<int>(img[0].size()));
        for(int i =0; i < img.size();i++){
            for(int j =0 ; j<img[0].size();j++){
                int val = getSum(img ,i , j);
                ans[i][j] = val;
            }
        }
        return ans;
    }
};
