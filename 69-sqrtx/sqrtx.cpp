class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long long n = 1;
 
        while (n * n <= x) {
            n *= 2;
        }
        
        // Binary search between n//2 and n
        long long low = n / 2, high = n;
        int result = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x) {
                return mid; 
            } else if (mid * mid < x) {
                result = mid;  // Update result with the largest mid whose square is <= x
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;  
    }
};

