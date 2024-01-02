package Problems;

import java.util.ArrayList;
import java.util.Collections;

//* Difficulty -> Medium *

//? Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//? Since the result may be very large, so you need to return a string instead of an integer.

//! Question Tag -> Array, String, Greedy, Sorting

class Solution {
    public String largestNumber(int[] nums) {
        ArrayList<String> list = new ArrayList<>();

        for (int num : nums)
            list.add(String.valueOf(num));

        Collections.sort(list, (a, b) -> (b + a).compareTo(a + b));

        StringBuilder sb = new StringBuilder();

        for (String str : list) {
            sb.append(str);
        }

        return (sb.charAt(0) == '0') ? ("0") : (sb.toString());
    }
}

public class Largest_Number {

}
