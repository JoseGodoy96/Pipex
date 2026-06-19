# Pipex
 
> A C program that reproduces the behavior of a **shell pipe**:
> `< file1 cmd1 | cmd2 > file2`.
 
Project completed at the **42** school (42 Málaga campus). Since it is an already
evaluated and closed submission, the repository contains **a single commit**: the
project is **finished** and receives no further changes.
 
---
 
## 📖 Description
 
**Pipex** introduces **process and file descriptor** handling on UNIX. The program
receives two files and two commands, and chains their execution just like the shell
would with a pipe. That is, this execution:
 
```bash
./pipex file1 cmd1 cmd2 file2
```
 
is equivalent to running in a terminal:
 
```bash
< file1 cmd1 | cmd2 > file2
```
 
To achieve this, the program:
 
1. **Creates a pipe** with `pipe()` to connect the two processes.
2. **Forks** with `fork()` into a child process and a parent process.
3. In the **child**: reads from `file1`, redirects its input/output with `dup2()`
   toward the pipe, and runs `cmd1`.
4. In the **parent**: takes the pipe's output as input, redirects the output toward
   `file2`, and runs `cmd2`.
5. **Resolves each command's path** by walking through the `PATH` variable from the
   environment (`envp`) and launches the executable with `execve()`.
---
 
## 🧠 Concepts covered
 
- Process management: `fork`, `wait`/`waitpid`.
- Inter-process communication through `pipe`.
- File descriptor redirection with `dup2`, `open`, `close`.
- Running binaries with `execve` and searching the `PATH`.
- Error handling with `perror` and exit codes (including `127` when the command is
  not found).
---
 
## 🗂️ Project structure
 
```
Pipex/
├── Makefile
├── include/
│   └── pipex.h
├── src/
│   ├── pipex.c      # main, pipe/fork creation, child and parent processes
│   └── utils.c      # PATH lookup and command execution
├── libft/           # own library used as a dependency
└── Personal/        # support material (subject)
```
 
> The project uses **Libft** as a dependency. The Makefile compiles it automatically
> before linking the executable.
 
---
 
## 🚀 Compilation and usage
 
```bash
# Build (also builds libft)
make
 
# General usage
./pipex input_file "command1" "command2" output_file
```
 
### Example
 
```bash
./pipex infile "grep hello" "wc -l" outfile
```
 
is equivalent to:
 
```bash
< infile grep hello | wc -l > outfile
```
 
### Makefile rules
 
| Command        | Description                                                |
| -------------- | ---------------------------------------------------------- |
| `make`         | Builds libft and the `pipex` executable.                   |
| `make clean`   | Removes the object files (`.o`).                          |
| `make fclean`  | Removes the `.o` files, the executable, and the library.   |
| `make re`      | Recompiles everything from scratch.                        |
 
---
 
## 👤 Author
 
**jgodoy-m** — Student at [42 Málaga](https://www.42malaga.com/)
 
---
 
## 📝 Note about this repository
 
This project is part of the **42** curriculum. As it is an already finished and
graded submission, the repository's history consists of **a single commit**. It is
not under active development: the code is complete and meets the requirements of the
assignment.
 

# Pipex


Un programa en C que reproduce el comportamiento de una tubería (pipe) de la
shell: < archivo1 cmd1 | cmd2 > archivo2.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


# 📖 Descripción

Pipex introduce el manejo de procesos y descriptores de fichero en UNIX. El
programa recibe dos archivos y dos comandos, y encadena su ejecución igual que lo
haría la shell con un pipe. Es decir, esta ejecución:

bash./pipex archivo1 cmd1 cmd2 archivo2

equivale a ejecutar en una terminal:

bash< archivo1 cmd1 | cmd2 > archivo2

Para conseguirlo, el programa:


Crea una tubería con pipe() para comunicar los dos procesos.
Bifurca con fork() en un proceso hijo y un proceso padre.
En el hijo: lee de archivo1, redirige su entrada/salida con dup2() hacia
la tubería y ejecuta cmd1.
En el padre: toma la salida de la tubería como entrada, redirige la salida
hacia archivo2 y ejecuta cmd2.
Resuelve la ruta de cada comando recorriendo la variable PATH del entorno
(envp) y lanza el ejecutable con execve().



# 🧠 Conceptos trabajados


Gestión de procesos: fork, wait/waitpid.
Comunicación entre procesos mediante pipe.
Redirección de descriptores de fichero con dup2, open, close.
Ejecución de binarios con execve y búsqueda en el PATH.
Manejo de errores con perror y códigos de salida (incluido 127 cuando el
comando no se encuentra).



# 🗂️ Estructura del proyecto

Pipex/
├── Makefile
├── include/
│   └── pipex.h
├── src/
│   ├── pipex.c      # main, creación de pipe/fork, procesos hijo y padre
│   └── utils.c      # búsqueda en PATH y ejecución del comando
├── libft/           # librería propia usada como dependencia
└── Personal/        # material de apoyo (enunciado)


El proyecto usa Libft como dependencia. El Makefile la compila
automáticamente antes de enlazar el ejecutable.




# 🚀 Compilación y uso

bash# Compilar (también compila la libft)
make

# Uso general
./pipex archivo_entrada "comando1" "comando2" archivo_salida

Ejemplo

bash./pipex infile "grep hola" "wc -l" outfile

Equivale a:

bash< infile grep hola | wc -l > outfile

Reglas del Makefile

ComandoDescripciónmakeCompila la libft y el ejecutable pipex.make cleanElimina los archivos objeto (.o).make fcleanElimina los .o, el ejecutable y la librería.make reRecompila todo desde cero.


# 👤 Autor

jgodoy-m — Estudiante de 42 Málaga


# 📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
