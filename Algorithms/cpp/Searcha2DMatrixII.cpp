class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int rowCount = matrix.size();
        if (rowCount == 0) return false;
        int columnCount = matrix[0].size();

        int startRow = 0;
        int startCol = columnCount - 1;

        while (startRow < rowCount && startCol >= 0) {
            int value = matrix[startRow][startCol];
            if (value == target) return true;
            if (value > target) startCol--;
            else startRow++;
        }
        return false;
    }
};
