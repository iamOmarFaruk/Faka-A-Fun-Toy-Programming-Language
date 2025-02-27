# Faka Language 🚀

## What is Faka?
Faka (ফাঁকা) means **emptiness, neutrality, and the absence of bias—just like syntax itself**. This experimental programming language follows an **English-like structure** to demonstrate a fundamental truth: **syntax is merely a tool, but concepts define true programming**.

By stripping away complexity, Faka challenges the conventional focus on syntax, emphasizing that **real expertise lies in understanding logic, patterns, and problem-solving**—not just writing code.

---

## Features ✨
- **Minimalist syntax** – Readable, English-like structure.
- **Supports basic types** – `string`, `int`, and `boolean`.
- **Simple variable assignments** – Assign and print values.
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
```

---

## Project Structure 📂
```sh
project/
│── faka_compiler.cpp   # Faka Compiler (C++ source code)
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
