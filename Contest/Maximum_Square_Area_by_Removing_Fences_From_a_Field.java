package Contest;

import java.util.Map;
import java.util.HashMap;

class Solution {
	public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
		HashMap<Integer, Integer> map = new HashMap<>(Map.of(m - 1, m - 1));
        
		for (int i = 0; i < hFences.length; i++) {
			map.put(hFences[i] - 1, hFences[i] - 1);
			map.put(m - hFences[i], m - hFences[i]);
			for (int j = i + 1; j < hFences.length; j++) {
				map.put(Math.abs(hFences[j] - hFences[i]), Math.abs(hFences[j] - hFences[i]));
			}
		}

		long max = map.getOrDefault(n - 1, 0);
		for (int i = 0; i < vFences.length; i++) {
			max = Math.max(max, Math.max(map.getOrDefault(vFences[i] - 1, 0), map.getOrDefault(n - vFences[i], 0)));
			for (int j = i + 1; j < vFences.length; j++) {
				max = Math.max(max, map.getOrDefault(Math.abs(vFences[j] - vFences[i]), 0));
			}
		}
		return (int) (max > 0 ? max * max % 1000000007 : -1);
	}
}


public class Maximum_Square_Area_by_Removing_Fences_From_a_Field {
    public static void main(String[] args){
        Solution sol = new Solution();
        System.out.println(sol.maximizeSquareArea(4, 3, new int[]{2,3}, new int[]{2}));
    }
}