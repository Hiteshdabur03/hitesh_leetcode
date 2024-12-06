class Solution {
public:
    int climbStairs(int n) {
      if (n == 1) return 1; 
        
        int prev2 = 1; 
        int prev1 = 2; 
        
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2; // ways(i) = ways(i-1) + ways(i-2)
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;  
    }
};