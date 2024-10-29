# ShellBrunbaix

## Description 📜

ShellBrunbaix is a basic shell written in C that reads user input, tokenizes the input, and executes commands. It mimics some basic functionalities of standard Unix shells by allowing users to execute external commands like `ls`, `pwd`, `echo`, etc., and includes the ability to exit the shell with the `exit` command and to change directory with the `cd` command.

### Features ⚙️

- Reads and processes user commands.
- Tokenizes the input into command and arguments.
- Uses `fork` and `execvp` to execute external commands in child processes.
- Handles simple error cases and displays appropriate messages.
- Allows exiting the shell with the `exit` command.
- Allows to change directory with `cd`.
- Prompt change based on the `username` & the `current directory`.

### Future Improvements 🔄

Here are some features that could be added to enhance the functionality of ShellBrunbaix:

- **Input/Output Redirection**: Allow users to redirect the output of commands using `>` or `<`.
- **Pipe Handling**: Implement support for piping (`|`) between commands.
- **Command History**: Keep track of previously entered commands and allow the user to access them.
- **Autocomplete**: Add support for tab-completion of commands and file paths.

### File Structure 📂

```bash
├── include
│   └── shell.h
├── LICENSE
├── Makefile
├── README.md
└── src
    ├── config.c
    ├── executor.c
    ├── intern.c
    ├── main.c
    └── parser.c
```

## Compilation and Execution 🛠️

To compile and run the ShellBrunbaix, follow these steps:

1. **Clone the Repository** (if hosted on GitHub):

    ```bash
    git clone https://github.com/your-username/shellbrunbaix.git
    cd shellbrunbaix
    ```

2. **Compile the Source Code**:

    The project uses a `Makefile` to simplify the compilation process. Simply run:

    ```bash
    make
    ```

    This will generate an executable named `shellbrunbaix`.

3. **Run the Shell**:

    To start the shell, run:

    ```bash
    ./shellbrunbaix
    ```

    You will see a custom prompt (`/>`) where you can enter commands.

4. **Use the Shell**:

    - Enter commands like `ls`, `pwd`, or `echo Hello`.
    - Type `exit` to close the shell.