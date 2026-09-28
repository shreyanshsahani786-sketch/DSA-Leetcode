class Solution {
public:
    int compress(vector<char>& chars) {
        
        int read = 0;
        int write = 0;

        while (read < chars.size()) {
            
            char current = chars[read];
            int count = 0;

            // Count karenge current character ko
            while (read < chars.size() && chars[read] == current) {
                count++;
                read++;
            }

            // Write character num
            chars[write] = current;
            write++;

            // Write count if greater than 1
            if (count > 1) {
                
                string str = to_string(count);

                for (char ch : str) {
                    chars[write] = ch;
                    write++;
                }
            }
        }

        return write;
    }
};