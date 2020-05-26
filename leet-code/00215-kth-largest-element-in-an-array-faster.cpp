215. Kth Largest Element in an Array

class Solution {
public:
    int randomized_partition(std::vector<int>& a, int first, int last) {
    // (1) We choose a random pivot
    srand(time(NULL));
    int random_pivot = rand() % (last+1-first) + first;
    //int random_pivot = first;
    // otherwise could choose just the first element

    // (2) We put the pivot element at the end of the array
    std::swap(a[random_pivot], a[last]);

    // (3) our pivot pointer is now pointing at the last element of the array
    int pivot = last;

    int index = first;
    for (int i = first; i < last; i++) {
        if (a[i] < a[pivot]) {
            std::swap(a[i], a[index]);
            index++;
        }
    }
    std::swap(a[pivot], a[index]);
    return index;
}

// k = 1 is the smallest element in a
// k = n is the largest element in a
int quickselect(std::vector<int>& a, int first, int last, int k) {
    if (last - first < 4) {
        std::partial_sort(a.begin()+first, a.begin()+last, a.end());
        return a[first+k-1];
    }

    // else, partition the array around a random pivot
    int p = randomized_partition(a, first, last);


    int left_length = p - first;

    if (k-1 == left_length) { // lucked out
        return a[first+k-1];
    }

    // otherwise
    if (k-1 < left_length) {
        return quickselect(a, first, p-1, k);
    } else {
        return quickselect(a, p+1, last, k-left_length-1);
    }
}
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, nums.size()-k+1);
    }
};