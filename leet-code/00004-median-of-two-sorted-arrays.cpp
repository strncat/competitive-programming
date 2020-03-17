class Solution {
public:
    // based on https://www.youtube.com/watch?v=LPFhl65R7ww
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // assume nums1 is the smallest where we'll binary search, if it's not
    // then swap
    int asize = nums1.size();
    int bsize = nums2.size();
    if (asize > bsize) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int first = 0;
    int last = asize - 1;
    
    // two cases odd and even length arrays
    // in both cases don't include the pivot in the left half

    while (1) {
        int apivot = first + (last - first)/2;
        // given a's pivot, we can now decide where we cut array b
        int bpivot = (asize + bsize + 1)/2 - apivot;
        
        // a [        a_min | a_max        ]
        // b [        b_min | b_max        ]
        int a_min = apivot == 0 ? INT_MIN : nums1[apivot - 1];
        int a_max = apivot == asize ? INT_MAX : nums1[apivot];
        
        int b_min = bpivot == 0 ? INT_MIN : nums2[bpivot - 1];
        int b_max = bpivot == bsize ? INT_MAX : nums2[bpivot];
        
    
        if (a_min <= b_max && b_min <= a_max) {
            // return the median
            if ((asize + bsize) & 1) { // odd
                // left side should have one more element so
                return std::max(a_min, b_min);
            } else {
                return ((double)std::max(a_min, b_min) + (double)std::min(a_max, b_max))/2;
            }
        } else if (a_min > b_max) {
            last = apivot - 1;
        } else {
            first = apivot + 1;
        }
    }
    return 0;
}

};