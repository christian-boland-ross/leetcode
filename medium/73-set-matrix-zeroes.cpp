class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<bool> zeroRows(matrix.size(), false);
        vector<bool> zeroCols(matrix[0].size(), false);

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(matrix[row][col] == 0)
                {
                    zeroRows[row] = true;
                    zeroCols[col] = true;
                }
            }
        }

        for(int row = 0; row < m; row++)
        {
            if(zeroRows[row])
                zeroRow(matrix, row);
        }

        for(int col = 0; col < n; col++)
        {
            if(zeroCols[col])
                zeroColumn(matrix, col);
        }
    }

    void zeroColumn(vector<vector<int>>& matrix, int col)
    {
        for(int i = 0; i < matrix.size(); i++)
            matrix[i][col] = 0;
    }

    void zeroRow(vector<vector<int>>& matrix, int row)
    {
        for(int i = 0; i < matrix[0].size(); i++)
            matrix[row][i] = 0;
    }
};