# Descrição do Programa
Este programa em C gerencia o cadastro de alunos em uma instituição, permitindo cadastrar novos alunos, buscar alunos por matrícula e listar todos os alunos de um curso específico. Utiliza estruturas e enums para organizar os dados dos alunos e apresenta um menu interativo para o usuário.

# Funcionalidades
- Estruturas de Dados:

estudante: Armazena informações de cada aluno, incluindo matrícula, nome, idade e curso (representado por um enum).
enum Curso: Define três opções de cursos: Engenharia, Computação e Matemática.

- Cadastro de Alunos:

A função CadastrarAluno permite adicionar um novo aluno, verificando se já existe uma matrícula cadastrada.
Busca de Alunos:

A função BuscarAluno permite procurar um aluno com base na matrícula, exibindo suas informações se encontrado.
Listagem de Alunos por Curso:

A função listar_alunos_de_um_curso lista todos os alunos que estão matriculados em um curso específico.
Interface Interativa:

- O programa apresenta um menu onde o usuário pode escolher diferentes ações, como cadastrar um aluno, buscar um aluno ou listar alunos de um curso.
Código

O código está bem estruturado, utilizando funções para modularizar as operações e comentários explicativos para facilitar o entendimento.

# Instruções de Uso

Compile o código com um compilador C.
Execute o programa.
Siga as instruções no menu para cadastrar alunos, buscar informações ou listar alunos de um curso específico.
Você pode continuar realizando operações até decidir encerrar o programa.
Exemplo de Uso
Para cadastrar um novo aluno, insira a matrícula, nome, idade e selecione o curso.
Para buscar um aluno, forneça a matrícula.
Para listar alunos, escolha um dos cursos disponíveis.
