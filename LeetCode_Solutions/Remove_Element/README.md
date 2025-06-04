## 27. Remove Element
Given an integer array `nums` and an integer `val`, remove **all occurrences** of `val` in-place.  
The order of the elements **may be changed**.  
Then return the number of elements in `nums` which are **not equal** to `val`.

You **must do this in-place**.

---

## ✅ Custom Judge

The judge will test your solution with the following code:

```c
int[] nums = [...]; // Input array
int val = ...;      // Value to remove
int[] expectedNums = [...]; // Expected result (sorted, no val)

int k = removeElement(nums, val); // Your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}