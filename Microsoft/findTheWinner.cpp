//Using array
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i =0 ; i < n;i++){
            v[i] = i+1;
        }
        int i = 0;
        while(v.size()>1){
            int size =v.size(); 
            int toErase = (i+k-1)%size;
            v.erase(v.begin() + toErase);
            i = toErase;
        }
        return v[0];
    }
};
