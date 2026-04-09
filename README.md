# C-Compiler

A C compiler implemented in C++ using the Qt framework. It reads a C source file and processes it through lexical and syntax analysis stages.

## Features

- **Lexical Analysis**: Tokenizes C source code into keywords, identifiers, operators, numbers, punctuation, and characters.
- **Syntax Analysis**: Parses the token stream (in progress).

### Supported Keywords

`if`, `else`, `while`, `int`, `char`, `bool`, `null`, `true`, `false`

### Token Types

| Type          | Description                          |
|---------------|--------------------------------------|
| `Keyword`     | Reserved language keywords           |
| `Identifier`  | Variable and function names          |
| `Operator`    | Arithmetic and logical operators     |
| `Number`      | Integer literals                     |
| `Punctuation` | Semicolons, braces, parentheses, etc.|
| `Character`   | Character literals                   |

## Requirements

- Qt 5 or later
- C++11 compatible compiler
- qmake

## Building

```bash
qmake C-Compiler.pro
make
```

## Usage

Place your C source code in a file named `code.c` in the same directory as the compiled binary, then run:

```bash
./C-Compiler
```

The compiler will open `code.c`, perform lexical analysis, and print the results to the console.

### Example `code.c`

```c
int value = 154 ;
bool mahi = false ;
```

## Project Structure

| File                   | Description                              |
|------------------------|------------------------------------------|
| `main.cpp`             | Entry point; opens `code.c` and runs the compiler |
| `compiler.h/cpp`       | Top-level `Compiler` class; orchestrates analysis phases |
| `lexicalanalyzer.h/cpp`| Lexical analyzer; tokenizes source input |
| `syntaxanalyzer.h/cpp` | Syntax analyzer (in progress)            |
| `base.h`               | Shared types: `TokenType`, `KeywordType`, `IdentifierData`, `NumberData` |
| `code.c`               | Sample C source file used as compiler input |
| `C-Compiler.pro`       | qmake project file                       |
