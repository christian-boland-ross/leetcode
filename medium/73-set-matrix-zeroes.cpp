class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        //log zeroed indices
        unordered_set<int> mZero;
        unordered_set<int> nZero;

        for(int m = 0; m < matrix.size(); m++)
        {
            for(int n = 0; n < matrix[0].size(); n++)
            {
                if(matrix[m][n] == 0)
                {
                    mZero.insert(m);
                    nZero.insert(n);
                }
            }
        }
        
        for(int m : mZero)
        {
            zeroColumn(matrix, m);
        }

        for(int n : nZero)
        {
            zeroRow(matrix, n);
        }
    }

    void zeroColumn(vector<vector<int>>& matrix, int m)
    {
        for(int i = 0; i < matrix[0].size(); i++)
        {
            matrix[m][i] = 0;
        }
    }

    void zeroRow(vector<vector<int>>& matrix, int n)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            matrix[i][n] = 0;
        }
    }
};