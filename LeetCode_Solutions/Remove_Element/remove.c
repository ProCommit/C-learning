#include <stdlib.h>
#include <stdio.h>

int removeElement(int *nums, int numsSize, int val);

int main()
{
    int nums[] = {3,2,2,3};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    int k = removeElement(nums, numSize, val);

    printf("nums = [");
    for (size_t h = 0; h < k; h++)
    {
        printf("%d,", nums[h]);
    }  
    printf("]");


    return 0;
}

int removeElement(int *nums, int numsSize, int val)
{

    int count = 0;

    for (size_t p = 0; p < numsSize; p++)
    {
        if (nums[p] == val)
        {
            count++;
        }
    }

    for (size_t i = 0; i < numsSize; i++)
    {
        for (size_t g = 0; g < numsSize; g++)
        {
            if (nums[i] != val && nums[g] == val)
            {
                int tmp = nums[i];
                nums[i] = nums[g];
                nums[g] = tmp;
               
            }
            else if (nums[i] == val && nums[g] == val)
            {
                int tmp = nums[i];
                nums[i] = nums[g];
                nums[g] = tmp;
                
            }
        }
    }

    return numsSize - count;
}