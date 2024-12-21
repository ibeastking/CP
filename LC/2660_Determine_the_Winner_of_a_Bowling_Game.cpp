//? Difficulty -> Easy

//? You are given two 0-indexed integer arrays player1 and player2,
//? that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.
//? The bowling game consists of n turns, and the number of pins in each turn is exactly 10.
//? Assume a player hit xi pins in the ith turn. The value of the ith turn for the player is:
//? 2xi if the player hit 10 pins in any of the previous two turns.
//? Otherwise, It is xi.
//? The score of the player is the sum of the values of their n turns.
//? Return
//? 1 if the score of player 1 is more than the score of player 2,
//? 2 if the score of player 2 is more than the score of player 1, and
//? 0 in case of a draw.

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int isWinner(vector<int> &v1, vector<int> &v2)
    {
        int x = v1[0], y = v2[0]; // for size 1 score = index 0 score
        int i = 0, n = v1.size();
        for (i = 1; i < n; i++)
        {
            if (i == 1)
            { // for index 1 check for index 0
                if (v1[i - 1] == 10)
                    x += v1[i] * 2;
                else
                    x += v1[i];
                if (v2[i - 1] == 10)
                    y += v2[i] * 2;
                else
                    y += v2[i];
            }
            else
            { // for other indexs check for i-1 || i-2
                if (v1[i - 1] == 10 or v1[i - 2] == 10)
                {
                    x += v1[i] * 2;
                }
                else
                {
                    x += v1[i];
                }
                if (v2[i - 1] == 10 or v2[i - 2] == 10)
                    y += v2[i] * 2;
                else
                    y += v2[i];
            }
        }
        if (x > y)
            return 1;
        if (y > x)
            return 2;
        return 0;
    }
};