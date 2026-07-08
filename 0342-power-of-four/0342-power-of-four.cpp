class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // Base Case
        if(n == 1)
            return true;

        // Invalid number
        if(n <= 0)
            return false;

        // Not divisible by 3
        if(n % 4 != 0)
            return false;

        // Recursive call krenge
        return isPowerOfFour(n / 4);
    }
};