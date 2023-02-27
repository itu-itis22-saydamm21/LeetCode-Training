/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    
    int* result = (int*) malloc(numsSize * sizeof(int));
    int* stack = (int*) malloc(numsSize * sizeof(int));
    int top = -1;

    // Initialize result array with -1
    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < numsSize * 2; i++) {
        int index = i % numsSize;

        while (top >= 0 && nums[stack[top]] < nums[index]) {
            result[stack[top]] = nums[index];
            top--;
        }

        if (i < numsSize) {
            stack[++top] = index;
        }
    }

    free(stack);
    *returnSize = numsSize;
    return result;
}
