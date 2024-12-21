package LC;

//* Difficulty -> Medium 

//? You are given a 0-indexed integer array arr, and an m x n integer matrix mat. 
//? arr and mat both contain all the integers in the range [1, m * n].
//? Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
//? Return the smallest index i at which either a row or a column will be completely painted in mat.

//! Question Tag -> Array, Matrix, Hash Table

class First_Completely_Painted_Row_or_Column {
    public static int firstCompleteIndex(int[] arr, int[][] mat) {
        int len = arr.length;

        int[] indices = new int[len + 1]; // store index of number in array
        for (int i = 0; i < len; i++)
            indices[arr[i]] = i;

        int m = mat.length, n = mat[0].length;
        int ans = len;

        for (int i = 0; i < m; i++) {
            int min = 0;
            for (int j = 0; j < n; j++) {
                int index = indices[mat[i][j]];
                min = Math.max(min, index);
            }
            ans = Math.min(ans, min);
        }
        for (int j = 0; j < n; j++) {
            int min = 0;
            for (int i = 0; i < m; i++) {
                int index = indices[mat[i][j]];
                min = Math.max(min, index);
            }
            ans = Math.min(ans, min);
        }

        return ans;
    }

    public static void main(String[] args) {

    }
}