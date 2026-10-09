class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        // Sort according to units per box
        sort(boxTypes.begin(), boxTypes.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] > b[1];
            });

        int totalUnits = 0;

        for(auto box : boxTypes) {

            int boxes = box[0];
            int units = box[1];

            // How many boxes can we take?
            int take = min(boxes, truckSize);

            totalUnits += take * units;

            truckSize -= take;

            // Truck is full
            if(truckSize == 0)
                break;
        }

        return totalUnits;
    }
};