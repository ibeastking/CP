package LC;

import java.util.Scanner;

//* Difficulty -> Medium *

//? Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//? Since the result may be very large, so you need to return a string instead of an integer.

//! Question Tag -> Array, String, Greedy, Sorting

public class Largest_Number {
    public static void main(String[] args) {
        double ib, gti;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int ibcount = 0, gticount = 0;
        for (int i = 0; i < n; i++) {
            int temp = new java.util.Random().nextInt(2);
            if (temp == 1)
                gticount++;
            else
                ibcount++;
        }

        ib = ibcount / n;
        gti = gticount / n;

        System.out.println("IB: " + ib + "\nGTI: " + gti);
        sc.close();
    }
}
