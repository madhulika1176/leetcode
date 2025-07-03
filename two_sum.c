#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Static array to return result
    static int result[2];
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0; // If no solution found
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = twoSum(nums, size, target, &returnSize);
    
    if (returnSize == 2) {
        printf("Output: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
