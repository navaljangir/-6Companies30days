class Solution {
public:
    bool isValid(vector<vector<char>>& board , int row, int col , char num){
        for(int i =0 ; i <board.size() ; i++){
            if(i!=col && board[row][i]==num){
                return false;
            }
        }
        for(int i =0 ; i <board.size();i++){
            if(i!=row && board[i][col]==num){
                return false;
            }
        }
        int rowStart = row - row % 3;
        int colStart = col - col % 3;
        int rowEnd = rowStart+2;
        int colEnd = colStart+2;
        for(int i = rowStart ; i <=rowEnd; i++){
            for(int j = colStart ; j <=colEnd;j++){
                if(i!=row && j!=col && board[i][j]==num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board ,int row, int col){
        if(row==9){
            return true;
        }
        if(row==8 && col==9){
            return true;
        }
        if(col==9){
            return solve(board , row+1 , 0);
        }
        if(board[row][col]=='.'){
            return solve(board , row , col+1);
        }
        if(isValid(board , row ,col , board[row][col])){
            return solve(board, row, col+1);
        }
        
        return false;
}
    bool isValidSudoku(vector<vector<char>>& board) { 
        return solve(board,  0 ,0 );
    }
};
