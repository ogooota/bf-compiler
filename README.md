# Brainfuck Compiler
A simple Brainfuck language compiler in C.

# Usage
It's simple:<br>
There are 2 flags: -h and -c.<br>
  -h is used for help (as usual).<br>
  -c <FILENAME> is used for compiling the files.

# Explanations
This compiler is still to-update, all it does is translate a .bf file into a standard C file.<br>
This C file which I called bf.c is filled with one include for stdio.h, a main function, <br>
a char buffer with 30000 bytes(30kb) allocated on the stack, and a pointer to the first memory address of this buffer.

# How it works
BF works with 8 valid characters:<br>
  '>': Increments the pointer value by 1 position.<br>
  '<': Decrements the pointer value by 1 position.<br>
  '+': Increments the value pointed to by 1.<br>
  '-': Decrements the value pointed to by 1.<br>
  '.': Outputs a value.<br>
  ',': Takes a value as input.<br>
  '[': Marks the beginning of a loop.<br>
  ']': Marks the end of a loop.

# Conclusion
Feel free to use this to compile your own .bf files (I don't know why you would do that lmao).
