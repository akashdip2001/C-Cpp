### 🧠 **What is Bubble Sort?**

Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.

Let’s take an example array:
`[5, 3, 8, 4, 2]`

### 🔄 Working of Bubble Sort:

* **1st pass:**
  `[3, 5, 4, 2, 8]` → largest number (8) moved to the end
* **2nd pass:**
  `[3, 4, 2, 5, 8]`
* **3rd pass:**
  `[3, 2, 4, 5, 8]`
* **4th pass:**
  `[2, 3, 4, 5, 8]` → now sorted!

---

## ✅ Bubble Sort Syntax in All Three Languages

### 🔷 Java

```java
public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2};
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // print sorted array
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
```

---

### 🔷 C

```c
#include <stdio.h>

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

---

### 🔷 C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
```

---

## 🧠 Key Concepts Behind the Code

| Step        | Meaning                                                                 |
| ----------- | ----------------------------------------------------------------------- |
| `for` loops | Outer loop controls the number of passes, inner loop compares elements. |
| `if` check  | Compares two elements and swaps if out of order.                        |
| `n - i - 1` | Reduces comparisons as the largest elements "bubble" to the end.        |

---

<img src="https://github.com/user-attachments/assets/c452512b-5206-4481-9228-eb61cd18e8e1">

---

## ⚡ What is Quick Sort?

Quick Sort is a **divide-and-conquer** algorithm.
It works by choosing a **pivot** element, then rearranging the array so that:

* All elements smaller than pivot are on the **left**
* All elements greater than pivot are on the **right**

Then it recursively applies the same logic to the left and right subarrays.

---

### 🧠 Quick Sort Example (Array: `[5, 3, 8, 4, 2]`)

1. Choose a **pivot** (say, last element → 2)
2. Partition the array around the pivot:
   → `[2, 3, 8, 4, 5]` — everything ≤2 left, >2 right
3. Repeat recursively on left and right subarrays

---

## ✅ Quick Sort Code in Java, C, and C++

---

### 🔷 Java

```java
public class QuickSort {
    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);  // left side
            quickSort(arr, pi + 1, high); // right side
        }
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];  // pivot
        int i = low - 1;        // smaller element index

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i+1] and pivot (arr[high])
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2};
        quickSort(arr, 0, arr.length - 1);

        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
```

---

### 🔷 C

```c
#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

---

### 🔷 C++

```cpp
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## 🔍 Bubble Sort vs Quick Sort

| Feature      | **Bubble Sort**              | **Quick Sort**                    |
| ------------ | ---------------------------- | --------------------------------- |
| Type         | Simple, comparison-based     | Divide-and-conquer                |
| Time (avg)   | O(n²)                        | O(n log n)                        |
| Time (worst) | O(n²)                        | O(n²) (rare, when pivot is worst) |
| Space        | O(1)                         | O(log n) (due to recursion stack) |
| Use case     | Small inputs, learning phase | Fastest in real-world use         |

---

<img src="https://github.com/user-attachments/assets/c452512b-5206-4481-9228-eb61cd18e8e1">

---

## 🔥 Top Sorting Algorithms You Should Know

| Algorithm      | Time Complexity                 | Space          | Stable | In-place | Use Case / Notes                                          |
| -------------- | ------------------------------- | -------------- | ------ | -------- | --------------------------------------------------------- |
| **Quick Sort** | O(n log n) avg <br> O(n²) worst | O(log n) stack | ❌      | ✅        | Fast, used in system libraries, bad pivot = worst case    |
| **Merge Sort** | O(n log n)                      | O(n)           | ✅      | ❌        | Always stable, used in external sorting (like files)      |
| **Heap Sort**  | O(n log n)                      | O(1)           | ❌      | ✅        | Fast & in-place, **great balance**, used in large systems |
| **Timsort**    | O(n log n)                      | O(n)           | ✅      | ❌        | Hybrid of Merge + Insertion, used in Python & Java sort() |

---

### ✅ Best Balanced Sorting Algorithm: **Heap Sort**

If you’re asking:

> "Is there a sorting algorithm that is fast **and** doesn't use extra space?"

**✔️ Heap Sort** is the closest match:

* Time: **O(n log n)** even in the worst case.
* Space: **O(1)** (in-place).
* No recursion required.
* Used in **real-time systems** and large data applications.
* Good for systems with **limited memory**.

But remember: Heap Sort is **not stable** (if that’s important for your project).

---

## 🚀 So what do companies use?

* **Java's `Arrays.sort()` for primitives → uses Dual Pivot QuickSort** (in-place, fast).
* **Java's `Arrays.sort()` for objects → uses TimSort** (stable, hybrid).
* **Python's built-in `sort()` → uses TimSort**.
* **C++ STL `std::sort()` → uses IntroSort** (mix of Quick + Heap + Insertion).

These are:

* Extremely optimized
* Safe for interviews
* Used in real-world production systems

---

## 🧩 Summary

| Goal                        | Best Algorithms                         |
| --------------------------- | --------------------------------------- |
| **Speed only**              | Quick Sort, Merge Sort                  |
| **Speed + Space efficient** | **Heap Sort**, Quick Sort               |
| **Stable + practical**      | TimSort, Merge Sort                     |
| **Used in real systems**    | TimSort, QuickSort, HeapSort, IntroSort |

---

<img src="https://github.com/user-attachments/assets/c452512b-5206-4481-9228-eb61cd18e8e1">

---

## 🚀 **What is Heap Sort?**

Heap Sort uses a **Binary Heap** (usually a **Max Heap**) to sort the array:

1. **Build a Max Heap** from the array.
2. **Swap** the largest element (root of heap) with the last element.
3. **Reduce heap size** by 1 and **heapify** the root.
4. Repeat until the array is sorted.

---

## 📦 Let's sort this array: `[5, 3, 8, 4, 2]`

* Step 1: Build Max Heap → `[8, 4, 5, 3, 2]`
* Step 2: Swap 8 with last → `[2, 4, 5, 3, 8]`
* Step 3: Heapify root → `[5, 4, 2, 3, 8]`
* Keep going...

---

## 🔷 Java Code for Heap Sort

```java
public class HeapSort {
    public static void heapSort(int[] arr) {
        int n = arr.length;

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Extract elements from heap
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Heapify the reduced heap
            heapify(arr, i, 0);
        }
    }

    static void heapify(int[] arr, int n, int i) {
        int largest = i;       // root
        int left = 2 * i + 1;  // left child
        int right = 2 * i + 2; // right child

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            // Swap
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2};
        heapSort(arr);
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
```

---

## 🔷 C Code for Heap Sort

```c
#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
```

---

## 🔷 C++ Code for Heap Sort

```cpp
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

---

## 🔍 Interview-Ready Summary

| Feature        | Heap Sort ✅                             |
| -------------- | --------------------------------------- |
| Time           | O(n log n) always                       |
| Space          | O(1) (in-place)                         |
| Stability      | ❌ Not stable                            |
| Real-world use | Used in OS schedulers, embedded systems |
| Interview tag  | ⭐️ Efficient + Memory-Friendly          |

---

<img src="colour_line" src="https://github.com/user-attachments/assets/1eac1ee1-5070-4cf4-8232-f9a0dafa16a3">

---

# **searching algorithms** 🔍

---

## 🔶 STEP 1: Linear Search

### 🧠 **What is Linear Search?**

* Check each element **one by one**
* Time Complexity: **O(n)**
* Simple but **slow** for large data

---

### ✅ Java – Linear Search

```java
public class LinearSearch {
    public static void main(String[] args) {
        int[] arr = {10, 25, 30, 5, 70};
        int key = 5;
        boolean found = false;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                System.out.println("Found at index: " + i);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Not found");
        }
    }
}
```

---

### ✅ C – Linear Search

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 25, 30, 5, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5, found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index: %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Not found\n");

    return 0;
}
```

---

### ✅ C++ – Linear Search

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 30, 5, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Not found" << endl;

    return 0;
}
```

---

### 📌 When to Use Linear Search

* When data is **unsorted**
* For small arrays
* When only **one or two searches** are needed

---

## 🔶 STEP 2: Binary Search

### 🧠 **What is Binary Search?**

* **Divide & conquer** algorithm
* Requires **sorted array**
* Time Complexity: **O(log n)** — much faster than linear

---

### ✅ Java – Binary Search

```java
public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {5, 10, 25, 30, 70}; // sorted
        int key = 25;
        int low = 0, high = arr.length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == key) {
                System.out.println("Found at index: " + mid);
                return;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        System.out.println("Not found");
    }
}
```

---

### ✅ C – Binary Search

```c
#include <stdio.h>

int main() {
    int arr[] = {5, 10, 25, 30, 70}; // sorted
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 25;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Found at index: %d\n", mid);
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Not found\n");
    return 0;
}
```

---

### ✅ C++ – Binary Search

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 25, 30, 70}; // sorted
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 25;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Found at index: " << mid << endl;
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return 0;
}
```

---

## 🔍 Linear Search vs Binary Search

| Feature          | **Linear Search**    | **Binary Search**     |
| ---------------- | -------------------- | --------------------- |
| Data requirement | Unsorted / Any order | Must be sorted        |
| Time complexity  | O(n)                 | O(log n)              |
| Space complexity | O(1)                 | O(1)                  |
| Practical use    | Small or rare search | Large sorted datasets |
| Interviews       | Common               | **Very important**    |

---

## 🔶 STEP 3: Most Optimized Search Techniques (For Interviews & Projects)

### ✅ 1. **Hashing (HashMap / Unordered Map)**

* Time: **O(1)** average
* Ideal for **frequent lookups**
* Used in:

  * Frequency counting
  * Checking duplicates
  * Fast searching in unsorted data

### ✅ 2. **Binary Search on Trees (BST / AVL / Segment Trees)**

* Trees allow fast searching, insertion, deletion
* **Balanced BST → O(log n)**

### ✅ 3. **Exponential Search + Binary**

* Used in **very large infinite-like data** (e.g., web pages)

### ✅ 4. **Jump Search, Interpolation Search**

* Used in very specific conditions
* Not common in interviews, but good to know

---
