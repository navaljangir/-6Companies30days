class Solution {
public:
    int solve(unordered_map<int,vector<pair<int,int>>> &adj ,int src ,int n , int k){
        queue<pair<int,int>> q;
        q.push({0 , src});
        vector<int> dist(n , INT_MAX);
        int ans= 0 ;
        dist[src]= 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int source = front.second;
            int cost = front.first;
            for(auto nbr: adj[source]){
                int currCost = nbr.second;
                int nebr = nbr.first;
                int total = cost+ currCost;
                if(total<=k){
                   if(total<dist[nebr]){
                     if(dist[nebr]==INT_MAX){
                        ans++;
                    }
                    dist[nebr]= total;
                    q.push({total , nebr});

                   }
                }
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0 ; i <edges.size();i++){
            int u = edges[i][0];
            int v =edges[i][1];
            int cost = edges[i][2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u ,cost});
        } 
        vector<int> ans(n , INT_MAX) ;
        for(int i=0 ;i < n;i++){
            int val =solve(adj, i , n , distanceThreshold);
            ans[i]= val;
        }
        int currMaxi = ans[0];
        int currNode =0;
        for(int i=0 ; i< n;i++){
            if(currMaxi>ans[i]){
                currMaxi = ans[i];
                currNode = i;
            }else if(currMaxi==ans[i]){
                currNode= i;
            }
        }
        return currNode;
    }
};f
