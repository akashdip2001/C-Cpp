# C++ with `C` in [`One Short`]()

---

## 📚 Table of Contents

1. [Hello World](#hello-world)
2. [Input and Output](#input-and-output)
3. [Variables and Data Types](#variables-and-data-types)
4. [Conditionals and Loops](#conditionals-and-loops)
5. [Functions](#functions)
6. [Arrays and Strings](#arrays-and-strings)
7. [Pointers](#pointers)
8. [Structures and Classes](#structures-and-classes)
9. [Object-Oriented Programming (OOP)](#object-oriented-programming)
   * [Concepts and Theories](#object-oriented-programming)
   * [Full Examples with Explanations](#object-oriented-programming)
10. [Memory Management](#memory-management)
11. [File Handling](#file-handling)
12. [Data Structures and Algorithms (DSA)](#data-structures-and-algorithms)
13. [Summary: C vs C++](#summary)
14. [Questions](practice-questions)

---

<a name="hello-world"></a>

## 1. Hello World

### C++

```cpp
#include <iostream> // For standard input and output
using namespace std; // Allows use of standard library without std:: prefix

int main() {
    cout << "Hello, World!" << endl; // Prints message followed by a new line
    return 0; // Indicates successful execution
}
```

### C

```c
#include <stdio.h> // For standard I/O functions like printf

int main() {
    printf("Hello, World!\n"); // Prints message with newline
    return 0; // Exit code
}
```

**Difference**:

* C++ uses `cout` from `<iostream>`.
* C uses `printf` from `<stdio.h>`.

---

<a name="input-and-output"></a>

## 2. Input and Output

### C++

```cpp
int a;
cin >> a; // Takes input from user and stores in 'a'
cout << "You entered: " << a << endl; // Prints the value of 'a'
```

### C

```c
int a;
scanf("%d", &a); // Takes integer input and stores in 'a'
printf("You entered: %d\n", a); // Prints the integer value
```

**Difference**: C++ uses stream-based I/O, which is simpler and more readable than C’s format-based I/O.

---

<a name="variables-and-data-types"></a>

## 3. Variables and Data Types

Both C and C++ support:

* `int`, `float`, `char`, `double`, `long`, `short`

C++ supports additional types:

* `bool`, `string` (class)
* `auto` (type inference)

### C++

```cpp
int a = 10; // Integer variable
float b = 3.14f; // Floating-point variable
bool isAlive = true; // Boolean variable
string name = "Alice"; // String variable
```

### C

```c
int a = 10; // Integer
float b = 3.14f; // Float
// No built-in bool or string in C; use 0/1 for bool, char arrays for strings
```

---

<a name="conditionals-and-loops"></a>

## 4. Conditionals and Loops

### If-Else

```cpp
if (a > 0) cout << "Positive";
else cout << "Non-positive";
```

```c
if (a > 0) printf("Positive");
else printf("Non-positive");
```

### Loops

#### For Loop

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

#### While Loop and Do-While: Same in both

---

<a name="functions"></a>

## 5. Functions

### C++

```cpp
int add(int a, int b) {
    return a + b;
}
```

### C

```c
int add(int a, int b) {
    return a + b;
}
```

**No difference** in basic function syntax. C++ supports **function overloading**.

---

<a name="arrays-and-strings"></a>

## 6. Arrays and Strings

### Arrays

```cpp
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " "; // Prints elements of the array
}
```

```c
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
}
```

<details>
  <summary style="opacity: 0.85;"><b>Why we need `i < 5` ❓ bec already Declared the arr elements</b></summary><br>

### ✅ Why `i < 5`?

You're right that we already declared the array size (`5`), so **why do we need to limit the loop to `i < 5`?**

Because:

* Arrays in C/C++ **do not do bounds checking**.
* `arr[5]` is **out of bounds** — even though `arr[0]` to `arr[4]` are valid.
* If you write `i < 99`, then the loop accesses memory beyond the array's valid size.

---

### 🧠 What happens if we write `i < 99`?

```cpp
for (int i = 0; i < 99; i++) {
    cout << arr[i] << " "; // Accessing out-of-bounds elements!
}
```

#### Possible results:

1. **Junk/garbage values**: You’re reading random memory that your program does not own.
2. **Crash / segmentation fault**: On modern OSes, this can crash the program.
3. **Security risk**: You could be reading or writing sensitive memory (this is how exploits happen).

---

### ✅ Safer Practice in C++:

![size of array](https://github.com/user-attachments/assets/1f6662dc-c9bc-46c8-9a7d-fee8a6ddd66a)

➕✖️➗ [`Calculate total elements = total bytes of array / bytes of one element`](https://www.digitalocean.com/community/tutorials/find-array-length-in-c-plus-plus)

You can use:

```cpp
for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
```

Or better in modern C++:

```cpp
#include <array>
std::array<int, 5> arr = {1, 2, 3, 4, 5};
for (int i = 0; i < arr.size(); i++)
```

---

### ✅ Safer Practice in C:

```c
for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    printf("%d ", arr[i]);
}
```

## ✅ Example: Using `sizeof(arr)/sizeof(arr[0])`

This is a **trick to automatically calculate the number of elements in a C/C++ array**.

---

### 🧪 Full Example in C

```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // Calculate total elements: total bytes of array / bytes of one element
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Array contains %d elements:\n", length);

    for (int i = 0; i < length; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
```

---

### 🔍 Output:

```
Array contains 5 elements:
arr[0] = 10
arr[1] = 20
arr[2] = 30
arr[3] = 40
arr[4] = 50
```

---

### 💡 What does `sizeof(arr)/sizeof(arr[0])` mean?

Let’s say:

* `sizeof(arr)` = total size of array in bytes (e.g., 5 integers × 4 bytes = 20 bytes)
* `sizeof(arr[0])` = size of one element (e.g., 4 bytes for `int`)

Then:

```c
sizeof(arr) / sizeof(arr[0]) = 20 / 4 = 5
```

➡️ You now have the **correct number of elements** in the array.

---

### ❌ What if you just write `i < 99`?

If you did:

```c
for (int i = 0; i < 99; i++) {
    printf("%d\n", arr[i]); // 🚨 i >= 5 is invalid
}
```

#### Result:

* For `i = 0 to 4`, output is fine.
* For `i = 5 to 98`, **you’ll get garbage values** or even crash the program!

</details>

---

### Strings

```cpp
string name = "Bob";
// cout << name << endl; // Prints the string
cout << name.length(); // Outputs length of the string
```

```c
char name[] = "Bob";
printf("%s", name);
```

**Key Points:**

* C++ has `string` class with rich methods.
* C strings are null-terminated char arrays.

### Multi-dimensional Arrays

```cpp
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

```c
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

---

<a name="pointers"></a>

## 7. Pointers

### C++

```cpp
int a = 5;
int *p = &a; // Pointer to variable 'a'
cout << *p; // Dereferencing to get value
```

### C

```c
int a = 5;
int *p = &a;
printf("%d", *p); // Prints value using pointer
```

**Same syntax**, but C++ adds **smart pointers**.

---

<a name="structures-and-classes"></a>

## 8. Structures and Classes

### C

```c
struct Employee {
    char name[20];
    int salary;
};
```

### C++

```cpp
class Employee {
public:
    string name;
    int salary;
    Employee(string n, int s) {
        name = n;
        salary = s;
    }
};
```

**C++ classes** support methods, access modifiers (`public`, `private`).

---

<a name="object-oriented-programming"></a>

## 9. Object-Oriented Programming (Only in C++) [Lern more](#oops-more)

### Key Concepts

| Concept       | Description                        |
| ------------- | ---------------------------------- |
| Class         | Blueprint for creating objects     |
| Object        | Instance of a class                |
| Encapsulation | Wrapping data and methods together |
| Inheritance   | One class inherits from another    |
| Polymorphism  | One function, many forms           |
| Abstraction   | Hiding internal details            |

### Example

```cpp
class Animal {
public:
    void sound() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Bark";
    }
};

int main() {
    Animal* a;
    Dog d;
    a = &d;
    a->sound();  // Output: Animal sound (without virtual)
}
```

**Note**: Use `virtual` for runtime polymorphism.

```cpp
class Animal {
public:
    virtual void sound() {
        cout << "Animal sound";
    }
};
```

---

<a name="memory-management"></a>

## 10. Memory Management

### C

```c
int* p = (int*) malloc(sizeof(int));
free(p);
```

### C++

```cpp
int* p = new int;
delete p;
```
#### or

```cpp
int *p = new int; // Dynamic memory allocation
*p = 10; // Assign value
cout << *p; // Access value
delete p; // Free memory
```

C++ also supports **smart pointers** like `unique_ptr`, `shared_ptr`.

---

<a name="file-handling"></a>

## 11. File Handling

### C

```c
FILE *f = fopen("file.txt", "r");
char ch = fgetc(f);
fclose(f);
```

### C++

```cpp
#include <fstream>
ifstream file("file.txt");
char ch;
file >> ch;
file.close();
```

#### or

```cpp
#include <fstream>
ofstream file("example.txt"); // Create file
file << "Hello, file!"; // Write to file
file.close(); // Close the file
```

---

<a name="data-structures-and-algorithms"></a>

## 12. Data Structures and Algorithms (DSA)

* Arrays
* Linked List
* Stack & Queue
* Trees
* Searching & Sorting

### Arrays

* Fixed-size containers
* Stored in contiguous memory

### Linked List (C: Manual, C++: Can use STL or manual)

```c
struct Node {
    int data;
    struct Node* next;
};
```

```cpp
class Node {
public:
    int data;
    Node* next;
};
```

### Stack & Queue

* In C++: Use STL `stack`, `queue`

```cpp
#include <stack>
stack<int> s;
s.push(1);
s.pop();
```

* In C: Implement manually with arrays or linked lists.

### Tree

```cpp
class Node {
public:
    int data;
    Node* left;
    Node* right;
};
```

### Sorting Algorithms

* Bubble Sort
* Selection Sort
* Merge Sort

Implement in both C and C++ using arrays.

### Searching

* Linear Search
* Binary Search (requires sorted array)

---

## 13. Summary: C vs C++

| Feature            | C            | C++                              |
| ------------------ | ------------ | -------------------------------- |
| Type               | Procedural   | Object-Oriented + Procedural     |
| Input/Output       | scanf/printf | cin/cout                         |
| String             | Char arrays  | string class                     |
| Functions          | Yes          | Yes + Overloading                |
| Classes/Objects    | No           | Yes                              |
| Templates          | No           | Yes                              |
| Exception Handling | No           | Yes                              |
| STL                | No           | Yes (stack, queue, vector, etc.) |

---

# OOPS <a name="oops-more"></a>

---

## 9. Object-Oriented Programming (Only in C++)

### Key Concepts and Descriptions

| Concept       | Description                        |
| ------------- | ---------------------------------- |
| Class         | Blueprint for creating objects     |
| Object        | Instance of a class                |
| Encapsulation | Wrapping data and methods together |
| Inheritance   | One class inherits from another    |
| Polymorphism  | One function, many forms           |
| Abstraction   | Hiding internal details            |

---

### 1. Class and Object

**Theory**:

* A class is like a template or blueprint.
* An object is a real instance of that class.

**Code:**

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void introduce() {
        cout << "Hi, I am " << name << " and I am " << age << " years old." << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Alice";
    s1.age = 20;
    s1.introduce();
    return 0;
}
```

**Explanation**:

* `Student` is the class.
* `s1` is the object.
* We access properties and methods using the object (`s1.name`).

---

### 2. Encapsulation

**Theory**:

* Keeping data safe from outside interference.
* Achieved using `private` and `public` access modifiers.

**Code:**

```cpp
class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(1000);
    cout << "Balance: " << account.getBalance();
    return 0;
}
```

**Explanation**:

* Data `balance` is private.
* Access is only possible via `public` methods.

---

### 3. Inheritance

**Theory**:

* A child class inherits features from the parent class.

**Code:**

```cpp
class Vehicle {
public:
    void start() {
        cout << "Vehicle starting..." << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Driving the car" << endl;
    }
};

int main() {
    Car myCar;
    myCar.start();  // from Vehicle
    myCar.drive();  // from Car
    return 0;
}
```

**Explanation**:

* `Car` inherits `Vehicle`.
* `Car` object can use both `start()` and `drive()`.

---

### 4. Polymorphism

**Theory**:

* One method behaves differently based on the object.
* Achieved using method overloading or virtual functions.

**Code (Runtime Polymorphism):**

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Bark" << endl;
    }
};

int main() {
    Animal* a;
    Dog d;
    a = &d;
    a->speak();  // Output: Bark
    return 0;
}
```

**Explanation**:

* The base class `Animal` has a `speak()` function.
* The derived class `Dog` overrides it.
* Using `virtual`, we ensure correct function is called at runtime.

---

### 5. Abstraction

**Theory**:

* Only show essential features; hide internal details.
* Achieved using abstract classes or interfaces.

**Code:**

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape* s = new Circle();
    s->draw();
    return 0;
}
```

**Explanation**:

* `Shape` is an abstract class.
* `Circle` implements the abstract method.
* This hides how `draw()` works internally.

---

# Practice Questions <a name="practice-questions"></a>

---

### 🔢 **Number-based Problems**

| Problem                   | Description                                                       | Sample Input                | Sample Output  |
| ------------------------- | ----------------------------------------------------------------- | --------------------------- | -------------- |
| **1. Palindrome Number**  | A number that remains same when reversed.                         | 121                         | Palindrome     |
| **2. Armstrong Number**   | Sum of cubes of each digit is equal to the number (for 3-digit).  | 153                         | Armstrong      |
| **3. Prime Number Check** | A number greater than 1 with no divisors other than 1 and itself. | 7                           | Prime          |
| **4. Perfect Number**     | Sum of divisors (excluding itself) equals the number.             | 28                          | Perfect Number |
| **5. Strong Number**      | Sum of factorials of digits equals the number.                    | 145                         | Strong         |
| **6. Neon Number**        | Square of number, sum of digits of square equals number.          | 9 → 9² = 81 → 8+1 = 9       | Neon           |
| **7. Automorphic Number** | A number whose square ends with the number itself.                | 76 → 76² = 5776             | Automorphic    |
| **8. Harshad Number**     | Divisible by sum of its digits.                                   | 18 → 1+8=9 → 18%9==0        | Harshad        |
| **9. Duck Number**        | Contains zero, but not at beginning.                              | 1203                        | Duck Number    |
| **10. Spy Number**        | Sum of digits equals product of digits.                           | 1124 → 1+1+2+4=8; 1×1×2×4=8 | Spy Number     |
| **11. Fibonacci Series**  | Sequence: 0, 1, 1, 2, 3, 5, ...                                   | n = 5                       | 0 1 1 2 3      |
| **12. Factorial**         | Product of all natural numbers up to n.                           | 5                           | 120            |
| **13. Sum of Digits**     | Add all digits.                                                   | 123                         | 6              |
| **14. Reverse Number**    | Reverse the digits.                                               | 1234                        | 4321           |
| **15. GCD / HCF**         | Highest common factor.                                            | 12, 18                      | 6              |
| **16. LCM**               | Lowest common multiple.                                           | 12, 18                      | 36             |
| **17. Swapping Numbers**  | Exchange values using temp or without temp.                       | a=3, b=4                    | a=4, b=3       |
| **18. Count Digits**      | Count how many digits.                                            | 12345                       | 5              |
| **19. Power of a Number** | a^b using loop.                                                   | 2^3                         | 8              |
| **20. Decimal to Binary** | Convert base 10 to base 2.                                        | 10                          | 1010           |

---

### 🔠 **String-based Problems**

| Problem                           | Description                            | Sample Input   | Sample Output  |
| --------------------------------- | -------------------------------------- | -------------- | -------------- |
| **21. Palindrome String**         | Same forward and backward.             | madam          | Palindrome     |
| **22. Reverse String**            | Reverse character order.               | hello          | olleh          |
| **23. Count Vowels & Consonants** | Identify number of vowels.             | apple          | Vowels=2       |
| **24. Check Anagram**             | Same letters in different order.       | listen, silent | Anagram        |
| **25. Frequency of Characters**   | Count occurrence of each character.    | banana         | a=3, b=1, n=2  |
| **26. Toggle Case**               | Convert upper to lower and vice versa. | HeLLo          | hEllO          |
| **27. Remove Spaces**             | Delete all white spaces.               | a b c          | abc            |
| **28. Check Pangram**             | Contains all 26 letters.               | The quick...   | Pangram        |
| **29. Count Words**               | Number of words in string.             | Hello world    | 2              |
| **30. Compare Strings**           | Lexicographically compare.             | apple, banana  | apple < banana |

---

### 🧮 **Pattern Printing Problems**

| Problem                     | Description                        | Sample Input | Sample Output           |
| --------------------------- | ---------------------------------- | ------------ | ----------------------- |
| **31. Right Triangle Star** | Print right-angled triangle.       | 3            | *<br>**<br>***          |
| **32. Pyramid Pattern**     | Center-aligned pyramid.            | 3            |   *<br> ***<br>**\*\*\* |
| **33. Inverted Triangle**   | Reverse triangle.                  | 3            | ***<br>**<br>*          |
| **34. Number Triangle**     | Triangle with numbers.             | 3            | 1<br>12<br>123          |
| **35. Floyd's Triangle**    | Incrementing numbers triangle.     | 3            | 1<br>2 3<br>4 5 6       |
| **36. Pascal’s Triangle**   | Binomial coefficients in triangle. | 3            | 1<br>1 1<br>1 2 1       |
| **37. Alphabet Triangle**   | Print characters in triangle.      | 3            | A<br>AB<br>ABC          |

---

### 🧠 **Logic/Other Problems**

| Problem                            | Description                                         | Sample Input     | Sample Output |
| ---------------------------------- | --------------------------------------------------- | ---------------- | ------------- |
| **38. Leap Year Check**            | Divisible by 4 but not 100 unless divisible by 400. | 2024             | Leap Year     |
| **39. Calculator using switch**    | Perform +, -, \*, /.                                | a=4, b=2, op=/   | 2             |
| **40. Simple Interest**            | (P×R×T)/100                                         | P=1000, R=5, T=2 | 100           |
| **41. Armstrong for n digits**     | Works for any number of digits.                     | 9474             | Armstrong     |
| **42. Sum of N natural numbers**   | n(n+1)/2                                            | 5                | 15            |
| **43. Largest of Three Numbers**   | Use if-else or ternary.                             | 3, 5, 2          | 5             |
| **44. ASCII value**                | Print ASCII of character.                           | A                | 65            |
| **45. Calculator using Functions** | Modular functions for +, -, etc.                    | 5 + 2            | 7             |


