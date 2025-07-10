#include <stdio.h>

int binarySearch(int* nums, int numsSize, int target, int findFirst) {
    int left = 0, right = numsSize - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            if (findFirst)
                right = mid - 1;  // keep searching left side
            else
                left = mid + 1;   // keep searching right side
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

void searchRange(int* nums, int numsSize, int target, int* returnArray) {
    returnArray[0] = binarySearch(nums, numsSize, target, 1);  // First position
    returnArray[1] = binarySearch(nums, numsSize, target, 0);  // Last position
}

// Example use
int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int result[2];

    searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, result);
    printf("Output: [%d, %d]\n", result[0], result[1]);
    
    return 0;
}
