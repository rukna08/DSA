#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
    int* returnArray = (int*)malloc(sizeof(int)*2);
    
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize; j++) {
            if(j != i){
                if(nums[i] + nums[j] == target){
                    returnArray[0] = j;
                    returnArray[1] = i;
                    break;
                }
            }
        }
    }
    
    return returnArray;
}

int main() {
    int nums[] = {2,7,11,15};
    int* indices = twoSum(nums, 4, 9);
    
    printf("[%d, %d]", indices[0], indices[1]);
    
    return 0;
}