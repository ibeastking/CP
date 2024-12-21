package GFG;

//* Difficulty -> Medium

//? Given a positive integer N, the task is to find the number of different ways in which N can be written as a sum of two or more positive integers.

//! Question Tag -> Dynamic Programming

public class Ways_to_write_n_as_sum {
    int countWays(int n) {
        // your code here
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - i]) % 1000000007;
            }
        }

        return dp[n];
    }
}
