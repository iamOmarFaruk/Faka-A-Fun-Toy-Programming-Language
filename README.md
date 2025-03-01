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

#### macOS
Make sure you have `g++` installed. If not, install it via Homebrew:
```sh
brew install gcc
```
Then, compile the Faka interpreter:
```sh
g++ -std=c++17 faka_compiler.cpp -o faka
```

#### Linux
Install g++ using your distribution's package manager:

For Debian/Ubuntu:
```sh
sudo apt update
sudo apt install g++
```

For Fedora:
```sh
sudo dnf install gcc-c++
```

For Arch Linux:
```sh
sudo pacman -S gcc
```

Then compile the Faka interpreter:
```sh
g++ -std=c++17 faka_compiler.cpp -o faka
```

#### Windows
1. Install MinGW-w64 or MSYS2 for GCC support:
   - Option 1: Download and install [MinGW-w64](https://www.mingw-w64.org/downloads/) 
   - Option 2: Install [MSYS2](https://www.msys2.org/) and then run `pacman -S mingw-w64-x86_64-gcc`

2. Add the compiler to your PATH (if not done automatically by the installer)

3. Open Command Prompt or PowerShell and compile:
```sh
g++ -std=c++17 faka_compiler.cpp -o faka.exe
```

4. Run your Faka programs with:
```sh
faka.exe index.faka
```

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
│── faka_compiler.cpp   # Faka Compiler (C++ source code)
│── faka_arithmetic.h   # Arithmetic operations implementation
│── index.faka          # Faka program example
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
