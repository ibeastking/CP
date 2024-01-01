package GFG;

import java.util.ArrayList;

class Solution {
    ArrayList<Integer> find3Numbers(ArrayList<Integer> arr, int n) {
        // add code here.
        ArrayList<Integer> list = new ArrayList<>();

        int minidx = 0;
        int[] minarray = new int[n];
        minarray[0] = -1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i) <= arr.get(minidx)) {
                minarray[i] = -1;
                minidx = i;
            } else {
                minarray[i] = minidx;
            }
        }

        int maxidx = arr.size() - 1;
        int[] maxarray = new int[n];
        maxarray[arr.size() - 1] = -1;

        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr.get(i) >= arr.get(maxidx)) {
                maxarray[i] = -1;
                maxidx = i;
            } else {
                maxarray[i] = maxidx;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (maxarray[i] != -1 && minarray[i] != -1) {
                list.add(minarray[i]);
                list.add(arr.get(i));
                list.add(maxarray[i]);
                return list;
            }
        }

        return list;
    }
}

class Sorted_Subsequence_of_Size_3 {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        new Solution().find3Numbers(list, list.size());
    }
}