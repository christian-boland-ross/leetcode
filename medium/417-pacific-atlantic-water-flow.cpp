class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> result;

        if (heights.empty() || heights[0].empty())
            return result;

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        vector<vector<int>> pacificQueue;

        for (int i = 0; i < rows; i++)
            pacificQueue.push_back({i, 0});

        for (int j = 0; j < cols; j++)
            pacificQueue.push_back({0, j});

        for (vector<int> p : pacificQueue)
            pacific[p[0]][p[1]] = true;

        bfs(heights, pacific, pacificQueue);

        vector<vector<int>> atlanticQueue;

        for (int i = 0; i < rows; i++)
            atlanticQueue.push_back({i, cols - 1});

        for (int j = 0; j < cols; j++)
            atlanticQueue.push_back({rows - 1, j});

        for (vector<int> p : atlanticQueue)
            atlantic[p[0]][p[1]] = true;

        bfs(heights, atlantic, atlanticQueue);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void bfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             vector<vector<int>> queue)
    {
        while (!queue.empty())
        {
            vector<int> current = queue[0];
            queue.erase(queue.begin());

            vector<vector<int>> neighbours = getNeighbourList(heights, current);

            for (vector<int> n : neighbours)
            {
                if (!visited[n[0]][n[1]] &&
                    heights[n[0]][n[1]] >= heights[current[0]][current[1]])
                {
                    visited[n[0]][n[1]] = true;
                    queue.push_back(n);
                }
            }
        }
    }

    vector<vector<int>> getNeighbourList(
        const vector<vector<int>>& heights,
        const vector<int>& current)
    {
        vector<vector<int>> neighbours;

        // north
        if (current[0] - 1 >= 0)
            neighbours.push_back({current[0] - 1, current[1]});

        // south
        if (current[0] + 1 < heights.size())
            neighbours.push_back({current[0] + 1, current[1]});

        // east
        if (current[1] + 1 < heights[0].size())
            neighbours.push_back({current[0], current[1] + 1});

        // west
        if (current[1] - 1 >= 0)
            neighbours.push_back({current[0], current[1] - 1});

        return neighbours;
    }
};