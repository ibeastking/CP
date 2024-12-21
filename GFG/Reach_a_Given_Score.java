package GFG;

//? Difficulty -> Easy

//? Consider a game where a player can score 3 or 5 or 10 points in a move. 
//? Given a total score n, find number of distinct combinations to reach the given score.

//! Dynamic Programming, Array

public class Reach_a_Given_Score {
    public long count(int n) {
        // Add your code here.
        long[] dp = new long[(int) n + 1];
        dp[0] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i] + dp[i - 3];
        }

        for (int i = 5; i <= n; i++) {
            dp[i] = dp[i] + dp[i - 5];
        }

        for (int i = 10; i <= n; i++) {
            dp[i] = dp[i] + dp[i - 10];
        }

        return dp[n];
    }
}
