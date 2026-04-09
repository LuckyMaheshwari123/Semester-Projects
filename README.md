# 🧮 Console-Based Calculator in C

A clean, well-structured **console calculator** written in pure C (C99), demonstrating core **programming fundamentals** like functions, recursion, control flow, input validation, and modular design.

---

## ✨ Features

### Basic Calculator
| Operation | Symbol |
|-----------|--------|
| Addition | `+` |
| Subtraction | `-` |
| Multiplication | `*` |
| Division | `/` |
| Modulus | `%` |

### Scientific Calculator
| Operation | Notes |
|-----------|-------|
| Square Root | `√x` |
| Power | `xⁿ` — uses **recursion** |
| Factorial | `n!` — uses **recursion** |
| Logarithm (base 10) | `log₁₀` |
| Natural Logarithm | `ln` |
| Sine | degrees input |
| Cosine | degrees input |
| Tangent | degrees input |
| Absolute Value | `\|x\|` |

---

## 🧠 Programming Concepts Demonstrated

| Concept | Where Used |
|--------|------------|
| Variables & Data Types | `double`, `int`, `long long` across all functions |
| Functions & Prototypes | Every operation is its own function |
| `switch` / `if-else` | Menu routing and operation selection |
| `while` / `do-while` | Main loop, input validation loops |
| Recursion | `power_recursive()`, `factorial_recursive()` |
| Input Validation | `get_number()`, `get_menu_choice()` |
| Modular Design | Logic split into small, single-purpose functions |
| Constants (`#define`) | `VERSION`, `APP_NAME`, `DIVIDER` |
| Math Library (`<math.h>`) | `sqrt`, `sin`, `cos`, `tan`, `log`, `fmod`, etc. |

---

## 🛠️ Build & Run

### Requirements
- GCC (or any C99-compatible compiler)
- Standard C math library (`-lm` flag)

### Compile
```bash
gcc -o calculator calculator.c -lm -std=c99
```

### Run
```bash
./calculator        # Linux / macOS
calculator.exe      # Windows
```

---

## 📁 Project Structure

```
console-calculator-c/
├── calculator.c    # Main source file (all logic)
├── README.md       # Project documentation
└── .gitignore      # Ignores compiled binaries
```

---

## 🚀 Getting Started (Clone & Run)

```bash
git clone https://github.com/YOUR_USERNAME/console-calculator-c.git
cd console-calculator-c
gcc -o calculator calculator.c -lm -std=c99
./calculator
```

---

## 📸 Sample Output

```
========================================
   C Console Calculator  v1.0.0
========================================

  MAIN MENU
  1. Basic Calculator  (+  -  *  /  %)
  2. Scientific Calculator
  3. About
  0. Exit
  Your choice [0-3]: 1

  BASIC CALCULATOR
  1. Addition       ( + )
  ...
  Enter first  number : 15
  Enter second number : 4

  15 + 4 = 19
```

---

## 📜 License

This project is licensed under the **MIT License** — feel free to use, modify, and distribute.

---

## 🙋‍♂️ Author

**Your Name**  
GitHub: [@your-username](https://github.com/your-username)
