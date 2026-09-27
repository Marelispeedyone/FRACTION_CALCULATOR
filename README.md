# FRACTION_CALCULATOR

**A program to calculate fractions without a hitch !**

## Table of contents

- [About](#about)
  - [What it does](#what-it-does)
  - [Who it’s for](#who-its-for)
  - [Why it stands out](#why-it-stands-out)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Quick Start](#quick-start)
  - [Method 1 : With Make (Recommended)](#method-1--with-make-recommended)
  - [Method 2 : Direct command](#method-2--direct-command)
  - [Run the program](#run-the-program)
- [Preview](#preview)
- [Usage](#usage)
- [What i learned](#what-i-learned)
- [Future improvements](#future-improvements)
- [License and author](#license-and-author)

# About

Fractions are everywhere. Whether you're splitting a pizza, adjusting a recipe, or working on a scientific calculation, they’re unavoidable. But handling them manually—simplifying results, converting improper fractions to mixed numbers, or performing operations—can be tedious and error-prone.

**Fraction Calculator** solves this by providing a powerful yet simple command-line tool.

### What it does
- **Simplifies** fractions automatically (using GCD)
- **Calculates** expressions with `+`, `-`, `*`, `/`  
- **Parses** natural input like `1/2 + 3/4` and returns a clean result

### Who it’s for
- **Anyone** who needs a quick and reliable fraction calculator
- **Students** learning Object-Oriented Programming (OOP), expression parsing, or project architecture in C++
- **Engineers** looking for a modular and extensible codebase to integrate into larger projects

### Why it stands out
This project goes beyond a basic calculator. It features a **lexer/parser** that reads space-separated expressions, handles fractions and whole numbers, and displays results in both **simple** and **mixed** formats—just like a real scientific tool.

# Features


- **Arithmetic operations** : $+$, $-$, $\times$, $/$
- **Comparison** : $=$, $<$, $>$, $\leq$, $\geq$, $\neq$
- **Simplification** : automatic reduction using GCD (Euclidean algorithm)
- **Mixed format** : displays $7/3$ as $2+1/3$
- **Expression parser** : handles natural input like $1/2 + 3/4$

# Prerequisites

- **Compiler** : `g++` (version ≥ 7.0) or `clang++`
- **Build tool** : `make` (version ≥ 4.0)
- **C++ Standard** : C++17 (or later)
- **System** : Linux, macOS, or Windows (via WSL or Cygwin)

# Quick Start

### Method 1 : With Make (Recommended)

```bash
make
```

### Method 2 : Direct command

```bash
g++ -std=c++17 -Wall -Wextra -I include/ -o main.cpp src/core/Fraction.cpp src/core/Parsing.cpp
```

### Run the program

```bash
./programme.exe
```

# Preview

```text

> 3/4 + 1/2
  = 5/4

> 7/3
  = 2 + 1/3

> 1/2 * 2
  = 1/1

> 1/0

```

# Usage

1. Launch the program with `./main`.
2. Type a **space-separated** expression (e.g., `1/2 + 3/4`).
3. Press `Enter`.
4. The result is displayed in simplified and mixed format.
5. Type `quit` or press `Enter` on an empty line to exit.

**Supported formats :**

| Input type | Examples |
| :--- | :--- |
| Fractions | `3/4`, `-5/2`, `12/-34` |
| Whole numbers | `5`, `-3` |
| Operators | `+`, `-`, `*`, `/` |
| Expressions | `1/3 / 4/5`, `-3/-9 * -1`|

# What i learned

- **Operator overloading** : implementing `+`, `-`, `*`, `/` and comparison operators for a custom `Fraction` class.
- **Algorithm design** : writing an iterative digit parser (Horner's method) to convert strings into integers.
- **Exception safety** : using `std::invalid_argument` to prevent invalid states (e.g., zero denominator).
- **Parser architecture** : designing an **index-alignment strategy** using placeholder markers to handle operator precedence (`*` and `/` before `+` and `-`) without dynamic vector deletion. This approach avoids common pitfalls like out-of-range errors and keeps the code robust.
- **Project structure** : organizing the code with a clean separation between `core/`, `parser/`, and `app/` layers, following the principle of separation of concerns.

# Future improvements

- [ ] Support for parentheses (e.g., `(1/2 + 1/3) * 2`)
- [ ] Add a `history` command to review the last 10 calculations
- [ ] Implement a variable `ans` to reuse the previous result
- [ ] Add unit tests with Google Test
- [ ] Export calculation history to a `.csv` file

# License and author

Distributed under the MIT License. See `LICENSE` for details.

**Author** : Marc-Eliel Ouattara  
**GitHub** : [Marelispeedyone](https://github.com/Marelispeedyone)
