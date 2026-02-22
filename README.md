# Pipex

A C implementation of Unix shell piping that replicates the behavior of:

```sh
< infile cmd1 | cmd2 > outfile
```

This project is part of the 42 school curriculum and explores process creation, pipes, file descriptors, and `execve`.

## Usage

```bash
make
./pipex infile "cmd1" "cmd2" outfile
```

### here_doc mode

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

Reads from standard input until `LIMITER` is found, then pipes through the commands and **appends** the result to `outfile`.

### Examples

```bash
# Equivalent to: < infile cat | wc -l > outfile
./pipex infile "cat" "wc -l" outfile

# With arguments
./pipex infile "tr a-z A-Z" "wc -w" outfile

# here_doc mode
./pipex here_doc EOF "cat" "wc -l" outfile
```

## Build

```bash
make        # build pipex and libft
make clean  # remove object files
make fclean # remove object files and binary
make re     # full rebuild
```

## Implementation Details

- Each command runs in its own **child process** via `fork` + `execve`.
- Commands are connected with `pipe(2)` file descriptors; I/O is redirected with `dup2`.
- Command paths are resolved by searching the `PATH` environment variable.
- If a command is not found, exits with code **127** (same as bash).
- The exit code returned is that of the **last command** in the pipeline.
- **here_doc** writes input to a temporary file (`.heredoc_tmp`) before piping.
- All file descriptors, pipes, and allocated memory are properly freed on exit.

## File Structure

| File | Description |
|---|---|
| `include/pipex.h` | `t_pipex` struct and all function prototypes |
| `src/main.c` | Entry point: validation, setup, execution, exit status |
| `src/init_files.c` | Open `infile` / `outfile` descriptors |
| `src/pipes.c` | Create and close pipe file descriptors |
| `src/here_doc.c` | here_doc detection, temp file creation, input reading |
| `src/parse_cmds.c` | Split command strings into argument arrays |
| `src/parse_paths.c` | Resolve full executable paths from `PATH` |
| `src/exec.c` | Fork, I/O redirection, `execve` |
| `src/errors.c` | Error printing helpers |
| `src/cleanup.c` | Free memory and close file descriptors |
| `libft/` | Custom C standard library |

## Author

dancuenc — 42 Madrid
