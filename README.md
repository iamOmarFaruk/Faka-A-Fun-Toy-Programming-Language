# Faka Language 🚀

## What is Faka?
Faka (ফাঁকা) means **emptiness, neutrality, and the absence of bias—just like syntax itself**. This experimental programming language follows an **English-like structure** to demonstrate a fundamental truth: **syntax is merely a tool, but concepts define true programming**.

By stripping away complexity, Faka challenges the conventional focus on syntax, emphasizing that **real expertise lies in understanding logic, patterns, and problem-solving**—not just writing code.

---

## Features ✨
- **Minimalist syntax** – Readable, English-like structure.
- **Supports basic types** – `string`, `int`, and `boolean`.
- **Simple variable assignments** – Assign and print values.
- **Basic arithmetic operations** – Addition (+) and subtraction (-) between integer variables.
- **Zero clutter** – Focus purely on logic, not syntax.
- **C++ based interpreter** – Fast and efficient execution.

---

## How to Use 🔥
### 1️⃣ Install & Compile

To compile the Faka interpreter directly from the root folder:

#### macOS/Linux
```sh
# Compile the Faka interpreter from the root folder
g++ -std=c++17 fakacompiler/main.cpp -o faka
```

#### Windows
```sh
# Compile the Faka interpreter from the root folder
g++ -std=c++17 fakacompiler/main.cpp -o faka.exe
```

You only need to compile once unless you make changes to the compiler code.

### 2️⃣ Write a Faka Program
Create a file named `index.faka` and add the following:
```faka
faka start
greeting variable will be string = "Hello, Faka!".
number variable will be int = 42.
status variable will be boolean = true.

print greeting.
print number.
print status.

a variable will be int = 10.
b variable will be int = 5.
calculate sum will be int = a + b.
calculate difference will be int = a - b.

print sum.
print difference.
faka end
```

### 3️⃣ Run Your Program

#### macOS/Linux
Execute the Faka script with:
```sh
./faka index.faka
```

#### Windows
Execute the Faka script with:
```sh
faka.exe index.faka
```

**Expected Output:**
```sh
Hello, Faka!
42
true
15
5
Program executed successfully!
```

---

## Language Syntax 📝

### Comments
```faka
// This is a comment in Faka. Comments start with // and end with \\ \\
```

Faka supports a unique comment style that can span single or multiple lines:
- Comments begin with `//` and end with `\\`
- Everything between these markers is ignored by the compiler
- Comments can span multiple lines

#### Examples:
```faka
// This is a single line comment \\

// This is a 
multi-line comment
that spans several lines \\

x variable will be int = 10. // This is an inline comment \\
```

### Variable Declaration
```faka
name variable will be type = value.
```

### Print Statement
```faka
print variableName.
```

### Arithmetic Operations
```faka
calculate resultVariable will be int = variable1 + variable2.
calculate resultVariable will be int = variable1 - variable2.
```

Currently, Faka supports addition (+) and subtraction (-) operations between integer variables.

#### Example:
```faka
x variable will be int = 20.
y variable will be int = 7.

calculate sum will be int = x + y.      // Creates a new variable 'sum' with value 27
calculate diff will be int = x - y.      // Creates a new variable 'diff' with value 13

print sum.    // Outputs: 27
print diff.   // Outputs: 13
```

Note: Arithmetic operations can only be performed on integer variables and will always result in an integer value.

---

## Project Structure 📂
```sh
project/
│── index.faka                  # Faka program example
│── faka                        # Compiled Faka interpreter executable
│── fakacompiler/               # Compiler implementation directory
│   │── faka_compiler.cpp       # Faka Compiler core implementation
│   │── faka_arithmetic.h       # Arithmetic operations implementation
│   │── faka_comment.h          # Comment processing implementation
│   │── main.cpp                # Main entry point for the Faka compiler
```

If you create more Faka scripts, just run:
```sh
./faka filename.faka
```

---

## Why Faka? 🤔
- **A Statement, Not Just a Language** – Syntax is nothing; thinking is everything.
- **Beginner-Friendly** – A fun way to understand programming concepts.
- **For Developers, By Developers** – Created as an experiment to rethink programming fundamentals.

---

## Credits & Contact 🏆
Created by **Omar Faruk**  
📧 Email: [omarbg.bd@gmail.com](mailto:omarbg.bd@gmail.com)  
🔗 LinkedIn: [Omar's Profile](https://www.linkedin.com/in/omar-expert-webdeveloper/)  

Want to contribute or share feedback? **Pull requests are welcome!** 🚀