class Solution {
public:

 bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.length() - 1;


        while (left < right) {

            // left vowel nahi hai
            if (!isVowel(s[left])) {
                left++;
            }

            // right vowel nahi hai
            else if (!isVowel(s[right])) {
                right--;
            }

            // dono vowels hain
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
        
    }
};