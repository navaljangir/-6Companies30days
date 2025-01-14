class Solution {
public:
    vector<int> v;
    vector<vector<int>> rectangles;
    int totalPoints =0;
    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        for(int i =0 ; i <rects.size();i++){
            int pointsInRect = (rects[i][3] - rects[i][1] + 1) * (rects[i][2]-rects[i][0] + 1);
            totalPoints+=pointsInRect;
            v.push_back(totalPoints);
        }
    }
    vector<int> pick() {
        int random = rand() % totalPoints;   
        int index = upper_bound(v.begin() , v.end() , random) - v.begin();
        vector<int> rects = rectangles[index];
        int x = rects[0] + rand() % (rects[2] - rects[0] + 1);
        int y = rects[1] + rand() % (rects[3] - rects[1] + 1);
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
