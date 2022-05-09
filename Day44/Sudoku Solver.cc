int N = 9;
    
    bool isSafe(int row, int col, vector<vector<char>> board, char ch){
        for(int i=0; i<N; i++) {
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
        }
        
        int beg_row = (row/3)*3;
        int beg_col = (col/3)*3;
        for(int i = beg_row; i<beg_row+3; i++) {
            for(int j = beg_col; j<beg_col+3; j++)
                if(board[i][j] == ch) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isSafe(i,j,board,ch)) {
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }   
                    }
                    return false;
                } 
            }  
        }
        return true;
    } 
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
