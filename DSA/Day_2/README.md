## ✅ **LEVEL 2 – ARRAYS, HASHING & TWO POINTERS (\~35 Questions)**

📌 *Goal:* Build confidence with **real Amazon-style problem solving** using patterns that appear **again and again in interviews**.

These are still **easy to medium** level — perfect for SDE-1.

---

### 🔹 **1. Core Array Problems (\~12 questions)**

These form the **backbone of real interview questions**.

1. **Two Sum** (🔥 Amazon must-do)

   * LeetCode 1: [Two Sum](https://leetcode.com/problems/two-sum/)
2. **Move Zeroes to End**

   * LeetCode 283: [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
3. **Sort 0s, 1s, 2s** (Dutch National Flag)

   * LeetCode 75: [Sort Colors](https://leetcode.com/problems/sort-colors/)
4. **Best Time to Buy and Sell Stock**

   * LeetCode 121: [Best Time to Buy and Sell](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
5. **Max Subarray Sum (Kadane’s Algorithm)**

   * LeetCode 53: [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
6. **Product of Array Except Self**

   * LeetCode 238: [Product of Array](https://leetcode.com/problems/product-of-array-except-self/)
7. **Check for Duplicates in Array**

   * LeetCode 217: [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
8. **Maximum Consecutive Ones**

   * LeetCode 485: [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)
9. **Find the Duplicate Number**

   * LeetCode 287: [Find Duplicate](https://leetcode.com/problems/find-the-duplicate-number/)
10. **Majority Element (> n/2 times)**

    * LeetCode 169: [Majority Element](https://leetcode.com/problems/majority-element/)
11. **Merge Intervals**

    * LeetCode 56: [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
12. **Merge Sorted Arrays (In-place)**

    * LeetCode 88: [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

---

### 🔹 **2. Hashing Basics (\~10 questions)**

These problems use **unordered\_map (C++) or HashMap (Java)** — very important for Amazon.

1. **First Non-Repeating Character**

   * LeetCode 387: [First Unique Character](https://leetcode.com/problems/first-unique-character-in-a-string/)
2. **Group Anagrams**

   * LeetCode 49: [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
3. **Top K Frequent Elements**

   * LeetCode 347: [Top K Frequent](https://leetcode.com/problems/top-k-frequent-elements/)
4. **Longest Subarray with 0 Sum**

   * GFG: [Longest Subarray 0 Sum](https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/)
5. **Subarray Sum Equals K**

   * LeetCode 560: [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
6. **Find All Duplicates in an Array**

   * LeetCode 442: [Find All Duplicates](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
7. **Isomorphic Strings**

   * LeetCode 205: [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
8. **Happy Number**

   * LeetCode 202: [Happy Number](https://leetcode.com/problems/happy-number/)
9. **Intersection of Two Arrays**

   * LeetCode 349: [Intersection of Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
10. **Find Missing and Repeating Number**

* GFG: [Missing and Repeating](https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/)

---

### 🔹 **3. Two Pointer Technique (\~10–12 questions)**

Very common in Amazon interviews for space-efficient solutions.

1. **Two Sum - Input Array is Sorted**

   * LeetCode 167: [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
2. **3Sum**

   * LeetCode 15: [3Sum](https://leetcode.com/problems/3sum/)
3. **Container With Most Water**

   * LeetCode 11: [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
4. **Remove Duplicates from Sorted Array (In-place)**

   * LeetCode 26: [Remove Duplicates](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
5. **Sort Squares of a Sorted Array**

   * LeetCode 977: [Squares of Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)
6. **Reverse Vowels of a String**

   * LeetCode 345: [Reverse Vowels](https://leetcode.com/problems/reverse-vowels-of-a-string/)
7. **Remove All Occurrences of a Key in Array (In-place)**

   * Custom pattern for interviews
8. **Find Pair with Given Sum**

   * GFG: [Pair with given sum](https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/)
9. **Minimum Difference Between Pair in Sorted Array**
10. **Check if Array is Palindrome (Two Pointers)**

    * Classic pointer problem

---

## 🔢 Total Questions in Level 2: \~32–35 problems

* Easy → Medium difficulty
* Commonly asked by **Amazon, Flipkart, Microsoft, etc.**

---

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

# Two Sum

```#include<stdio.h>
int main(){
  
  int arr[] = {1,2,3,4,5,6,8,10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int tearget=15;
  
  
  for(int i=0; i < size ; i++){
    for(int j = 1; j < size; j++)
      if(arr[i] + arr[j] == tearget){
        printf("The pair is %d and %d ", arr[i], arr[j]);
        break;
      }
    }
  }
  
  return 0;
}
```

## ❌ output Two times

---

### 🔍 Problem in Your Code

```c
for(int i = 0; i < size; i++) {
    for(int j = 1; j < size; j++) {
        if(arr[i] + arr[j] == tearget) {
            printf("The pair is %d and %d\n", arr[i], arr[j]);
            break;
        }
    }
}
```

Here’s what’s happening:

* When `i = 4` (`arr[i] = 5`) and `j = 7` (`arr[j] = 10`), it prints:
  → `The pair is 5 and 10`

* Later, when `i = 7` (`arr[i] = 10`) and `j = 4` (`arr[j] = 5`), it again matches
  → `The pair is 10 and 5`

This happens because:

* You start `j` from 1 **every time**, so `i` and `j` overlap and repeat combinations.
* You don’t prevent using the same pair in reverse order.

---

### ✅ Fix: Start `j` from `i + 1`

To avoid repeated pairs and self-pairs:

```c
for(int i = 0; i < size; i++) {
    for(int j = i + 1; j < size; j++) {
        if(arr[i] + arr[j] == tearget) {
            printf("The pair is %d and %d\n", arr[i], arr[j]);
        }
    }
}
```

### 🧪 Output for your array:

```c
arr[] = {1,2,3,4,5,6,8,10}
target = 15
```

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Same problem --> using Function 

```
#include <stdio.h>

// Function returns 1 if a pair is found, else 0
int twoSum(int arr[], int size, int target, int *out1, int *out2) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] + arr[j] == target) {
                *out1 = arr[i];
                *out2 = arr[j];
                return 1;  // Pair found
            }
        }
    }
    return 0;  // No pair found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 15;

    int num1, num2;

    if (twoSum(arr, size, target, &num1, &num2)) {
        printf("The pair is %d and %d\n", num1, num2);
    } else {
        printf("No pair found for the sum: %d\n", target);
    }

    return 0;
}
```

# But why * pointers ?? [`Harry Video`](https://m.youtube.com/watch?v=ZSPZob_1TOk&t=29582s&pp=2AGO5wGQAgE%3D)

Great question! You're noticing an important difference between **modifying an array** and **returning multiple individual values** from a function.

Let me explain the difference clearly between these two cases:

---

## 🔹 1. **Why `int *out1, int *out2` in `twoSum()`?**

You're using pointers like `*out1` and `*out2` in this function:

```c
int twoSum(int arr[], int size, int target, int *out1, int *out2)
```

### Why?

Because you want to **return two separate numbers** (the pair that adds to the target) **from inside the function to `main()`**.

* In C, a function can return **only one value directly**.
* So to return multiple values, we **use pointers**: we modify the variables at the memory addresses given by `out1` and `out2`.

🧠 Think of this as: “I can’t return two values, so let me **store them** in variables you give me.”

---

## 🔹 2. **Why you DON’T need pointers in `bubbleShort()`**

Here’s your function:

```c
void bubbleShort(int arr[], int size)
```

| [complete code](https://github.com/akashdip2001/C-Cpp/blob/main/DSA/Day_1/1%20Array/2_2_BubbleShort.c) |
| --- |

### Why no `*` here?

Because arrays in C are **always passed by reference** (even though it looks like they're passed by value).

When you pass `arr[]` into the function, you’re actually giving it a pointer to the array's **original memory**. So **any changes made to the array inside the function affect the original array**.

✅ That’s why this works **without needing** to return anything or use `int *arr`.

---

## 🔁 Comparison Summary

| Case                  | Method           | Why It Works                   |
| --------------------- | ---------------- | ------------------------------ |
| `bubbleShort(arr, n)` | Just `arr[]`     | Arrays are passed by reference |
| `twoSum(..., *a, *b)` | Use `int *a, *b` | Need to return multiple values |

---

## ✅ Visual Example

### Bubble Sort

```c
void sort(int arr[], int size) {
    // arr points to original memory
    arr[0] = 99; // modifies the original array
}
```

### TwoSum

```c
int find(int *a, int *b) {
    *a = 5;
    *b = 10;
    return 1;
}
```

---

### 🧠 Rule of Thumb:

> If you want to **modify the contents of an array**, you don’t need pointers explicitly — arrays are already pointers.

> If you want to **return more than one single value**, use `int *ptr` to pass in **addresses where results can be stored**.

---

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

