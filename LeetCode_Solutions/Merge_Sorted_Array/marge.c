#include <stdio.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);

int main()
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums1size = sizeof(nums1) / sizeof(nums1[0]);
    int m = 3;
    int nums2[] = {2, 5, 6};
    int nums2size = sizeof(nums2) / sizeof(nums2[0]);
    int n = 3;

    merge(nums1, nums1size, m, nums2, nums2size, n);

    for (size_t i = 0; i < m + n; i++)
    {
        printf("%d", nums1[i]);
    }

    return 0;
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int tmpArray[m + n];
    int count = 0;

    for (size_t i = 0; i < m; i++)
    {
        tmpArray[i] = nums1[i];
        count++;
    }

    for (size_t g = 0; g < n; g++)
    {
        tmpArray[count] = nums2[g];
        count++;
    }

    for (size_t u = 0; u < n + m; u++)
    {
        for (size_t i = 0; i < n + m; i++)
        {
            if (tmpArray[u] < tmpArray[i])
            {
                int tmp = tmpArray[i];
                tmpArray[i] = tmpArray[u];
                tmpArray[u] = tmp;
            }
        }
    }

    for (size_t g = 0; g < m + n; g++)
    {
        nums1[g] = tmpArray[g];
    }
}
