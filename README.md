Pipex


Un programa en C que reproduce el comportamiento de una tubería (pipe) de la
shell: < archivo1 cmd1 | cmd2 > archivo2.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


📖 Descripción

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



🧠 Conceptos trabajados


Gestión de procesos: fork, wait/waitpid.
Comunicación entre procesos mediante pipe.
Redirección de descriptores de fichero con dup2, open, close.
Ejecución de binarios con execve y búsqueda en el PATH.
Manejo de errores con perror y códigos de salida (incluido 127 cuando el
comando no se encuentra).



🗂️ Estructura del proyecto

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




🚀 Compilación y uso

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


👤 Autor

jgodoy-m — Estudiante de 42 Málaga


📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
