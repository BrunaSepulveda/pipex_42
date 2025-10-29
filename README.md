# pipex_42
O projeto Pipex tem como objetivo compreender e reproduzir o comportamento de execução de comandos do shell, com foco no tratamento de pipes e na comunicação entre processos.

|            Parte Mandatória     | Informação |
| :------------------------------ | :------------------------------------------------------------------------------------------- |
| Nome do programa                | pipex |
| Arquivos para entregar          | Makefile, *.h, *.c |
| Makefile                        | NAME, all, clean, fclean, re |
| Argumentos                      | arquivo1 comando1 comando2 arquivo2 |
| Funções externas autorizadas    | open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid |

## Descrição
O programa deve reproduzir o comportamento do seguinte comando do shell:
```bash
< arquivo1 comando1 | comando2 > arquivo2
```
Exemplo de uso:
```bash
./pipex infile "grep a1" "wc -w" outfile
```
Comportamento equivalente a:
```bash
< infile grep a1 | wc -w > outfile
```
Para isso, o pipex deve receber quatro parâmetros e criar um pipe de execução entre dois comandos, obedecendo aos seguintes critérios:
-  O primeiro comando deve ter como file descriptor de entrada o arquivo1, e sua saída deve ser redirecionada para o buffer do pipe criado.
- O segundo comando deve ter como file descriptor de entrada o pipe e como saída o arquivo2.
- O programa nunca deve terminar inesperadamente (segmentation fault, leaks, etc.).
- O arquivo1 deve existir e ser legível para que o programa seja executado corretamente.
- O arquivo2, caso já exista, deve ter permissão de escrita; caso contrário, o programa deve criá-lo para armazenar a saída final.
- O comportamento deve ser idêntico ao shell na execução equivalente.

## Executando
Comandos para execução:
- Compila o projeto: `make`
- Roda o executável com argumentos: `make run ARGS='infile "cmd1" "cmd2" outfile'`
- Apaga apenas os objetos .o: `make clean`
- Apaga .o, a lib .a: `make fclean`
- Faz fclean e recompila tudo: `make re`
