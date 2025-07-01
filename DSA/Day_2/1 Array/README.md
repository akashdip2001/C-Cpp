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

# Or, ✅ No need to return two values in ihe main()

```
#include <stdio.h>

// Function returns 1 if a pair is found, else 0
int twoSum(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] + arr[j] == target) {
                printf("The painr is %d and %d", arr[i], arr[j]);
                return 1; // Exit early since pair is found
            }
        }
    }
    return 0; // No pair found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 15;

  twoSum(arr, size, target);

    return 0;
}
```

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">


# Q2 Two Sum , But return ARRAY index

![Screenshot (58)](https://github.com/user-attachments/assets/22cd729a-447b-4ece-83c9-8090f3da6f1d)

---

### 🔧 Problem Recap:

**Input:**

```c
numbers = [2,7,11,15]
target = 9
```

**Output:**

```c
[1,2]
```

**Explanation:** `2 + 7 = 9`, and `2` is at index `0`, `7` is at index `1`.
In 1-based indexing → `[1, 2]`.

---

## ✅ C Implementation (Brute-force)

Here’s a simple and correct C program using nested loops:

```c
#include <stdio.h>

void twoSum(int arr[], int size, int target) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                // 1-based indexing
                printf("Output: [%d, %d]\n", i + 1, j + 1);
                return;
            }
        }
    }
    printf("No two numbers found that sum to %d\n", target);
}

int main() {
    int numbers[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    twoSum(numbers, size, target);

    return 0;
}
```

---

## ✅ Output:

```
Output: [1, 2]
```
