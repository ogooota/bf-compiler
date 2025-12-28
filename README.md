# Brainfuck Compiler

A simple Brainfuck language compiler in C.

---

## Usage

It's simple:

There are 2 flags: `-h` and `-c`.

- `-h` is used for help (as usual).
- `-c <FILENAME>` is used for compiling the files.

---

## Explanations

This compiler is still to-update, all it does is translate a `.bf` file into a standard C file.

This C file which I called `bf.c` is filled with:
- one include for `stdio.h`
- a `main` function
- a char buffer with 30000 bytes (30kb) allocated on the stack
- a pointer to the first memory address of this buffer

---

## How it works

BF works with 8 valid characters:

- `>`: Increments the pointer value by 1 position.
- `<`: Decrements the pointer value by 1 position.
- `+`: Increments the value pointed to by 1.
- `-`: Decrements the value pointed to by 1.
- `.`: Outputs a value.
- `,`: Takes a value as input.
- `[`: Marks the beginning of a loop.
- `]`: Marks the end of a loop.

---

## Conclusion

Feel free to use this to compile your own `.bf` files  
(I don't know why you would do that lmao).
