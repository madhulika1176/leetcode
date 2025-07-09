#include <stdio.h>

// Function to remove duplicates in-place
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j]; // move unique element forward
        }
    }
    return i + 1; // number of unique elements
}

// Function to print first k elements of the array
void printArray(int* nums, int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// Sample usage
int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, size);

    printf("After removing duplicates, k = %d\n", k);
    printf("Unique elements: ");
    printArray(nums, k);

    return 0;
}
