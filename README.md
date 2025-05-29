# libasm

**libasm** is an assembly project developed at 42 Porto.
The objective is to reimplement a selection of standard C library functions in x86-64 assembly using NASM.
This project provides a hands-on introduction to low-level programming, system calls, and optimization.

## Implemented Functions

- `ft_strlen` – Get the length of a string
- `ft_strcpy` – Copy a string to a destination buffer
- `ft_strcmp` – Compare two strings
- `ft_write` – Write data to a file descriptor
- `ft_read` – Read data from a file descriptor
- `ft_strdup` – Duplicate a string using dynamic memory allocation

## Testing

The `main.c` file is a simple test suite that verifies the functionality of each implemented function.
It compares results with expected outputs, handles error cases (like failed `read`, `write`, or `malloc`),
and prints clear, color-coded output to the terminal for easier debugging.

## Makefile

The project includes a Makefile for building the static library `libasm.a` and compiling a test binary.

### Main Targets

- `make` – Assembles `.s` files into object files and archives them into `lib/libasm.a`.
- `make test` – Compiles `main.c` with the library to create a test executable.
- `make clean` – Removes object files and the test binary.
- `make fclean` – Performs `clean` and also removes generated directories.
- `make re` – Fully rebuilds the project from scratch.

## Technologies

- Language: Assembly (x86_64)
- Assembler: NASM
- Platform: Linux
