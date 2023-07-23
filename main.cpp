#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to calculate the maximum area of the largest rectangular submatrix containing all 1's
int max_rectangle_area(vector<vector<int>>& matrix) 
{
    int rows = matrix.size();
    if (rows == 0)
        return 0;

    int cols = matrix[0].size();
    int max_area = 0;
    vector<int> heights(cols, 0);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] == 0)
                heights[j] = 0;
            else
                heights[j] += matrix[i][j];
        }

        int area = 0;
        vector<int> stack;
        for (int j = 0; j <= cols; j++) 
        {
            while (!stack.empty() && (j == cols || heights[j] < heights[stack.back()])) 
            {
                int height = heights[stack.back()];
                stack.pop_back();
                int width = stack.empty() ? j : (j - stack.back() - 1);
                area = max(area, height * width);
            }
            stack.push_back(j);
        }

        max_area = max(max_area, area);
    }

    return max_area;
}

// Function to convert the string matrix to a 2D integer matrix
vector<vector<int>> convert_to_matrix(vector<string>& strArr) 
{
    int rows = strArr.size();
    int cols = strArr[0].size();
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            matrix[i][j] = strArr[i][j] - '0';
        }
    }

    return matrix;
}

// Function to calculate the area of the largest rectangular submatrix containing all 1's
int matrix_challenge(vector<string>& strArr) 
{
    vector<vector<int>> matrix = convert_to_matrix(strArr);
    int max_area = max_rectangle_area(matrix);
    return max_area;
}

int main() 
{
    // Test the function with the example inputs
    vector<string> strArr1 = {"10100", "10111", "1111", "10010"};
    vector<string> strArr2 = {"1011", "0011", "0111", "1111"};

    int output1 = matrix_challenge(strArr1);
    int output2 = matrix_challenge(strArr2);

    cout << output1 << endl; // Output: 6
    cout << output2 << endl; // Output: 8

    return 0;
}
