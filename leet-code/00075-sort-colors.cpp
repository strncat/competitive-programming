// awesome trick, just like quicksort partition
// just this time ALSO move larger items in addition to moving
// smaller items! that's it!! you're moving two kinds of elements
// the smaller ones and the larger ones!
class Solution {
public:
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sortColors(vector<int>& nums) {
        int smaller = 0;
        int i = 0;
        int larger = nums.size() - 1;
        int pivot = 1;
        while (i <= larger) {
            if (nums[i] < pivot) { // smaller
                swap(&nums[i], &nums[smaller]);
                smaller++;
                i++;
            } else if (nums[i] > pivot) { // larger
                swap(&nums[i], &nums[larger]);
                larger--;
            } else { // equal
                i++;
            }
        }
    }
};