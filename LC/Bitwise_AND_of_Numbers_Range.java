package LC;

//* Difficulty -> Medium 

//? Given two integers left and right that represent the range [left, right], 
//? return the bitwise AND of all numbers in this range, inclusive.

//! Question Tag -> Bit Manipulation

public class Bitwise_AND_of_Numbers_Range {
    public int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1);
        }

        return right;
    }
}
