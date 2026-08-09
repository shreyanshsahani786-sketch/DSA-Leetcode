class Solution {
public:
    int maximumSwap(int num) {

        string s = to_string(num);

        // Store last occurrence of each digit
        vector<int> last(10, -1);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - '0'] = i;
        }

        // Try to make each digit as large as possible
        for (int i = 0; i < s.size(); i++) {

            int current = s[i] - '0';

            // Check larger digits
            for (int digit = 9; digit > current; digit--) {

                if (last[digit] > i) {

                    swap(s[i], s[last[digit]]);

                    return stoi(s);
                }
            }
        }

        return num;
    }
};