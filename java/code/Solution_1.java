// Solution for Problem-1 in java as follows:- 

package code;

import java.util.HashMap;
import java.util.Scanner;

public class Solution_1 {

    public boolean isPossible(int[] nums) {
        HashMap<Integer, Integer> availabilityMap = new HashMap<>();
        
        HashMap<Integer, Integer> wantMap = new HashMap<>();
        
        for (int num : nums) {
            availabilityMap.put(num, availabilityMap.getOrDefault(num, 0) + 1);
        }
        
        for (int num : nums) {
            if (availabilityMap.get(num) <= 0) {
                continue;
            }
            
            else if (wantMap.getOrDefault(num, 0) > 0) {
                availabilityMap.put(num, availabilityMap.get(num) - 1);
                
                wantMap.put(num, wantMap.get(num) - 1);
                
                wantMap.put(num + 1, wantMap.getOrDefault(num + 1, 0) + 1);
            }
            
            else if (availabilityMap.getOrDefault(num, 0) > 0 && 
                     availabilityMap.getOrDefault(num + 1, 0) > 0 && 
                     availabilityMap.getOrDefault(num + 2, 0) > 0) {
                availabilityMap.put(num, availabilityMap.get(num) - 1);
                availabilityMap.put(num + 1, availabilityMap.get(num + 1) - 1);
                availabilityMap.put(num + 2, availabilityMap.get(num + 2) - 1);
                
                wantMap.put(num + 3, wantMap.getOrDefault(num + 3, 0) + 1);
            }
            
            else {
                return false;
            }
        }
        
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution_1 solution = new Solution_1();
        int n = scanner.nextInt();

        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        } 
        System.out.println(solution.isPossible(nums)); 
        scanner.close();
    }
}
