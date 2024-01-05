package Problems;

import java.util.HashMap;

//* Difficulty -> Medium */

//? You are given an integer array cards where cards[i] represents the value of the ith card. 
//? A pair of cards are matching if the cards have the same value.
//? Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. 
//? If it is impossible to have matching cards, return -1.

//! Question Tag -> Array, Hash Table, Sliding Window

class Solution {
    public int minimumCardPickup(int[] cards) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int res = Integer.MAX_VALUE;

        for(int i=0;i<cards.length;i++) {
            int temp = map.getOrDefault(cards[i],i);

            if(temp != i) res = Math.min(res,i-temp+1);

            map.put(cards[i],i);
        }

        return (res == Integer.MAX_VALUE) ? (-1) : (res);
    }
}

public class Minimum_Consecutive_Cards_to_Pick_Up {
    
}
