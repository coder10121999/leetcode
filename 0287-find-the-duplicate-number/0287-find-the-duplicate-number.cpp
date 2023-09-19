class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowptr = nums[0];
        int fastptr = nums[0];

        do {
            slowptr = nums[slowptr];
            fastptr = nums[nums[fastptr]];
        } while(slowptr != fastptr);

        fastptr = nums[0];
        while(slowptr != fastptr) {
            slowptr = nums[slowptr];
            fastptr = nums[fastptr];
        }
        return fastptr;
    }
    // 3, 1, 3, 4, 2
    // 1, 2, 3, 4, 5

    // 3 -> 4 -> 2 -> 3 -> 4 -> 2 -> 3

    // 1 3 4 2 2
    // 1 -> 3 -> 2 -> 4 -> 2 -> 4 -> 2 ..

    // 2 2 2 2 2
    // 2 -> 2 -> 2 -> 2 
};