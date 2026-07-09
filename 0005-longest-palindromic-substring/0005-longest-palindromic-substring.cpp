class Solution {
public:

    int start = 0;
    int maxLen = 0;

    void expand(string &s, int left, int right){

        while(left >= 0 &&
              right < s.length() &&
              s[left] == s[right]){

            if(right - left + 1 > maxLen){

                start = left;
                maxLen = right - left + 1;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        for(int i = 0; i < s.length(); i++){

            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};