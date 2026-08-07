class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Source or destination blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // Single cell
        if(n == 1)
            return 1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},1});

        visited[0][0] = true;

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            int row = front.first.first;
            int col = front.first.second;
            int dist = front.second;

            for(int i = 0; i < 8; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 &&
                   newRow < n &&
                   newCol >= 0 &&
                   newCol < n &&
                   grid[newRow][newCol] == 0 &&
                   !visited[newRow][newCol])
                {
                    if(newRow == n-1 && newCol == n-1)
                        return dist + 1;

                    visited[newRow][newCol] = true;

                    q.push({{newRow,newCol}, dist + 1});
                }
            }
        }

        return -1;
    }
};