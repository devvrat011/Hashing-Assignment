// Solution for Problem-2 in java as follows:- 

package code;

import java.util.HashMap;
import java.util.Scanner;

public class Solution_2 {

    public int longestSubarrayWithSumZero(int[] A) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int maxLength = 0;
        map.put(0, -1);

        for (int i = 0; i < A.length; i++) {
            sum += A[i]; 

            if (map.containsKey(sum)) {
                maxLength = Math.max(maxLength, i - map.get(sum));
            } else {
                map.put(sum, i);
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution_2 solution = new Solution_2();
        int n = scanner.nextInt();

        int[] A = new int[n];

        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        } 
        System.out.println("Length of the longest subarray with sum zero: " + solution.longestSubarrayWithSumZero(A));
        scanner.close();

    }
}
