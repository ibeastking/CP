//? Difficulty -> Easy

package Problems;

import java.util.HashSet;
import java.util.Objects;

class Solution {
    public class Coordinates {
        public int x;
        public int y;

        Coordinates(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null || getClass() != obj.getClass())
                return false;

            Coordinates cord = (Coordinates) obj;
            return (x == cord.x && y == cord.y);
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    public boolean isPathCrossing(String path) {
        HashSet<Coordinates> set = new HashSet<>();

        int x = 0;
        int y = 0;

        for (int i = 0; i < path.length(); i++) {
            if (set.contains(new Coordinates(x, y)))
                return true;

            set.add(new Coordinates(x, y));

            if (path.charAt(i) == 'N')
                y++;
            else if (path.charAt(i) == 'S')
                y--;
            else if (path.charAt(i) == 'E')
                x++;
            else
                x--;
        }

        if (set.contains(new Coordinates(x, y))) {
            return true;
        }

        return false;
    }
}

public class Path_Crossing {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Boolean res = sol.isPathCrossing("NESWW");
        System.out.println(res);
    }
}
