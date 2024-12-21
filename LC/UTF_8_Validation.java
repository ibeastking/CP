package LeetCode;

//* Difficulty -> Medium */

//? Given an integer array data representing the data, 
//? return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).
//? A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
//? For a 1-byte character, the first bit is a 0, followed by its Unicode code.
//? For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.

//! Question Tag -> Array, Bit Manipulation

class Solution {
    public boolean validUtf8(int[] data) {
        int rbytes = 0;

        for(int num: data){
            if(rbytes == 0){
                if(num>>7 == 0b0) rbytes = 0;
                else if(num>>5 == 0b110) rbytes = 1;
                else if(num>>4 == 0b1110) rbytes = 2;
                else if(num>>3 == 0b11110) rbytes = 3;
                else if(num>>7 == 0b1) return false;
            }else{
                if(num>>6 == 0b10) rbytes--;
                else return false;
            }
        }

        return (rbytes == 0);
    }
}

public class UTF_8_Validation {
    
}
