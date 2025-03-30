# myPipe

## Summary

This project is a simplified recreation of shell piping behavior. It handles input/output redirection, command execution, and piping using UNIX system calls, mimicking:

```bash
< file1 cmd1 | cmd2 > file2
```

It implements process forking, file descriptor manipulation, and command chaining through pipes.

---

## Usage

### Compilation

```bash
make        # compiles mandatory part
make bonus  # compiles bonus part
```

### Execution

**Mandatory:**

```bash
./pipex file1 cmd1 cmd2 file2
```

Equivalent to:

```bash
< file1 cmd1 | cmd2 > file2
```

**Bonus:**

```bash
./pipex file1 cmd1 cmd2 ... cmdn file2
```

Equivalent to:

```bash
< file1 cmd1 | cmd2 | ... | cmdn > file2
```

**Here_doc:**

```bash
./pipex here_doc LIMITER cmd1 cmd2 file
```

Equivalent to:

```bash
cmd1 << LIMITER | cmd2 >> file
```

---

## Features

- Reimplementation of UNIX shell behavior using system calls
- Pipe chaining with an arbitrary number of commands
- Support for *here_doc*
- Norm-compliant structure and memory safety
- Modular codebase

This project makes use of:

- [Libft](https://github.com/pourist/libft_42)
- [get_next_line](https://github.com/pourist/GNL)

---

## Repository Structure

```bash
.
├── gnl/             # [get_next_line](https://github.com/pourist/GNL)
├── include/         # Header files (pipex.h)
├── libft/           # [Libft](https://github.com/pourist/libft_42)
├── pipex_bonus/     # Bonus logic: multiple pipes, here_doc
├── src/             # Mandatory part source files
├── Makefile
└── README.md
```

---

## Functions Used

- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`, `strerror`
- `access`, `dup`, `dup2`
- `execve`, `exit`, `fork`, `pipe`
- `unlink`, `wait`, `waitpid`

---

## Makefile Rules

- `make`, `make all` – build mandatory part
- `make bonus` – build bonus part
- `make clean` – remove object files
- `make fclean` – remove all built files
- `make re` – clean and rebuild everything

---

## Author

 [Pouriya Pourbahrami](https://github.com/pourist)

---

