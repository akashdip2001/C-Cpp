# C++ with `C` in [`One Short`]()

---

## 📚 Table of Contents

1. Hello World
2. Input and Output
3. Variables and Data Types
4. Conditionals and Loops
5. Functions
6. Arrays and Strings
7. Pointers
8. Structures and Classes
9. Object-Oriented Programming (OOP)
    * Concepts and Theories
    * Full Examples with Explanations
10. Memory Management
11. File Handling
12. Data Structures and Algorithms (DSA)
13. Summary: C vs C++

---

## 1. Hello World

### C++

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

### C

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

**Difference**:

* C++ uses `cout` from `<iostream>`.
* C uses `printf` from `<stdio.h>`.

---

## 2. Input and Output

### C++

```cpp
int a;
cin >> a;
cout << "You entered: " << a << endl;
```

### C

```c
int a;
scanf("%d", &a);
printf("You entered: %d\n", a);
```

**Difference**: C++ is more readable with stream I/O; C uses format specifiers.

---

## 3. Variables and Data Types

Both C and C++ support:

* `int`, `float`, `char`, `double`, `long`, `short`

C++ supports additional types:

* `bool`, `string` (class)
* `auto` (type inference)

### C++

```cpp
int a = 10;
float b = 3.14;
bool isAlive = true;
string name = "Alice";
```

### C

```c
int a = 10;
float b = 3.14;
// no bool or string
```

---

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

## 6. Arrays and Strings

### Arrays

```cpp
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

```c
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
}
```

### Strings

```cpp
string name = "Bob";
cout << name.length();
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

## 7. Pointers

### C++

```cpp
int a = 5;
int *p = &a;
cout << *p;
```

### C

```c
int a = 5;
int *p = &a;
printf("%d", *p);
```

**Same syntax**, but C++ adds **smart pointers**.

---

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

C++ also supports **smart pointers** like `unique_ptr`, `shared_ptr`.

---

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

---

## 12. Data Structures and Algorithms (DSA)

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

