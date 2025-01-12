class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bool found= 0;
        for(int i =0 ; i < grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i ,j});
                }else if(grid[i][j]==1){
                    found= 1;
                }
            }
        }
        if(found==0){
            return 0;
        }
        int ans = 0; 
        vector<int> a= {0 , 0 , -1, 1};
        vector<int> b = {1,-1, 0, 0 };
        while(!q.empty()){
            int size =q.size(); 
            while(size>0){
                    pair<int,int> p = q.front();
                    q.pop();
                    int currI = p.first;
                    int currJ = p.second;
                    for(int i=0 ; i < 4;i++){
                        int newI = currI + a[i];
                        int newJ = currJ + b[i];
                        if(newI>=0 && newJ>=0 && newI<grid.size() && newJ < grid[0].size() && grid[newI][newJ]==1){
                            grid[newI][newJ] =-1;
                            q.push({newI , newJ});
                        }
                    }
            size--;
            }
            ans++;
        }
        
        for(auto i : grid){
            for(auto j : i){
                if(j==1){
                    return -1;
                }
            }
        }
        return ans-1;
    }
};
