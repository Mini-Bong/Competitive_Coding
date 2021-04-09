/* Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

*/

class Solution {
public:
    bool binarySearch(vector<int> arr, int l, int r, int target){
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1; 
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target<matrix[0][0] || target > matrix[m-1][n-1]){
            return false;
        }
        int up = 0, down = m-1;
        int mid = 0;
        while(up<=down){
            mid = (up+down)/2;
            if(matrix[mid][n-1]==target){
                return true;
            }
            else if(target > matrix[mid][n-1]){
                up = mid+1;
            }
            else{
                down = mid-1;
            }
        }
       if(target > matrix[mid][n-1]){
           return binarySearch(matrix[mid+1], 0, n-1, target);
       }
        return binarySearch(matrix[mid], 0, n-1, target);
    }
};