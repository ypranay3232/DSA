# C++ Character Arrays — Placement‑Ready Notes

---

## 1. What is `char` in C++?

* `char` is a **1‑byte** data type.
* Used to store **single characters** (ASCII based).

```cpp
char c = 'A';
```

---

## 2. Character Array (C‑Style String)

A **character array** is used to store a sequence of characters.

```cpp
char arr[10];   // can store up to 9 characters + '\0'
```

⚠️ **Important**: One extra space is required for the **null character `\0`**.

---

## 3. Signed vs Unsigned `char`

| Type            | Range       |
| --------------- | ----------- |
| `signed char`   | −128 to 127 |
| `unsigned char` | 0 to 255    |

Why?

* `char` uses **1 byte = 8 bits**
* Signed: −2⁷ to 2⁷−1
* Unsigned: 0 to 2⁸−1

---

## 4. Ways to Take Input in Character Array

### ✅ Method 1: Sequence Input (Whole Word)

```cpp
char name[100];
cin >> name;
```

* Reads input **until space / tab / newline**
* Automatically adds **null character `\0`** at the end

Example input:

```
demo
```

Stored as:

```
[d][e][m][o][\0]
```

---

### ❌ Problem with `cin >>`

```text
Input:  hello world
Output: hello
```

Why?

* `cin >>` **stops reading at space, tab, or newline**

---

### ✅ Method 2: Character‑by‑Character Assignment

```cpp
char ch[10];
ch[0] = 'a';
ch[1] = 'b';
ch[2] = 'c';
ch[3] = 'd';

cout << ch[0] << ch[1] << ch[2] << ch[3];
```

Used when:

* You want **manual control** over characters

---

## 5. Null Character (`\0`) — VERY IMPORTANT 🔥

* `\0` marks the **end of a string**
* ASCII value of `\0` is **0**

Example:

```cpp
char c[10];
cin >> c;

int check = (int)c[4];
cout << check;   // prints 0 → NULL character
```

If input length < array size:

* Characters after `\0` are **garbage values**

---

## 6. Printing Internal Values (Debug Trick)

```cpp
for (int i = 0; i < 7; i++) {
    cout << "index " << i << " value " << c[i] << endl;
}
```

Helps to:

* Visualize `\0`
* Understand garbage values

---

## 7. Reading Full Line with Spaces (Correct Way)

### ❌ Wrong Way

```cpp
cin >> task;   // stops at space
```

---

### ✅ Correct Way: `cin.getline()`

```cpp
cin.ignore();              // clear input buffer
cin.getline(task, 100);    // reads full line with spaces
```

Why `cin.ignore()`?

* Clears leftover `\n` from previous input
* Prevents skipping of input

---

## 8. Complete Example Program

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. Sequence input
    char ch[100];
    cout << "Enter your name: ";
    cin >> ch;
    cout << "Your name is " << ch << endl;

    // 2. Character by character
    char cha[10];
    cha[0] = 'a';
    cha[1] = 'b';
    cha[2] = 'c';
    cha[3] = 'd';
    cout << cha[0] << cha[1] << cha[2] << cha[3] << endl;

    // 3. Null character demo
    char c[10];
    cin >> c;
    int check = (int)c[4];
    cout << check << endl;  // prints 0 if null character

    // 4. Full line input with spaces
    char task[100];
    cin.ignore();
    cout << "Enter full input: ";
    cin.getline(task, 100);
    cout << "The fix is: " << task << endl;
}
```