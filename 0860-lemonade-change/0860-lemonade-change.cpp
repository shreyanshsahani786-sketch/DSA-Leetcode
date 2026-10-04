class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for(int bill : bills) {

            // Customer gives $5
            if(bill == 5) {
                five++;
            }

            // Customer gives $10
            else if(bill == 10) {

                // Need one $5 as change to give to customer
                if(five == 0) {
                    return false;
                }

                five--;
                ten++;
            }

            // Customer gives $20
            else {

                // Need $15 change
                if(ten > 0 && five > 0) {

                    // Give $10 + $5
                    ten--;
                    five--;
                }

                else if(five >= 3) {

                    // Give three $5
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};