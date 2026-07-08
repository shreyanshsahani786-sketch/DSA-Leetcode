class Solution {
public:
    bool isPowerOfThree(int n) {

        //base case
        if (n == 1)
        return true;

        // not valid number
        if (n <= 0)
            return false;
        // not divisible by 3
        if(n % 3 != 0)
        return false;
        
        // recursive call krenge
        return isPowerOfThree(n/3);
    }
};