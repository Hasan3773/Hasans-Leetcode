class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int,int>> neighbors;
        int r = grid.size();
        int c = grid[0].size();
        neighbors.push({row,col});
        while(!neighbors.empty()){
            auto rc_pair = neighbors.front();
            neighbors.pop();
            // check vertical and horizontal neighbors 
            int row = rc_pair.first, col = rc_pair.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1'){
                neighbors.push({row-1,col});
                grid[row-1][col] = '0';
            }
            if (row + 1 < r && grid[row+1][col] == '1'){
                neighbors.push({row+1,col});
                grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1'){
                neighbors.push({row,col-1});
                grid[row][col-1] = '0';
            }
            if (col + 1 < c && grid[row][col+1] == '1'){
                neighbors.push({row,col+1});
                grid[row][col+1] = '0';
            }
        }

    }
    

    int numIslands(vector<vector<char>>& grid) {
        int num_rows = grid.size();
        if (!num_rows) return 0;
        int num_cols = grid[0].size();

        int count = 0;

        for (int i = 0; i < num_rows; ++i){
            for (int j = 0; j < num_cols; ++j){
                if (grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};