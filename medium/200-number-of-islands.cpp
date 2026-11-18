class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (grid[y][x] == '1')
                {
                    islandCount++;
                    dfs(grid, x, y);
                }
            }
        }

        return islandCount;
    }

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m ||
            grid[y][x] == '0')
            return;

        grid[y][x] = '0';

        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
};