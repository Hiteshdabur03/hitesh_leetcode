class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++; 
                return digits;
            }
            digits[i] = 0; 
        }

        // below condn we come only when unable to return in for loop
        digits.insert(digits.begin(), 1); // Add '1' to the beginning
        return digits;
    }
};
