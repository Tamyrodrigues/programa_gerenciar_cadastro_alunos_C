#include <stdio.h>
#include <string.h>

#define MAX_ESTUDANTES 100
// TAMYRIS SILVA RODRIGUES DOS SANTOS GRR20242732

/* Crie um programa para gerenciar cadastro de alunos:
   Matrícula, deve permitir letras e números com no máximo 15 caracteres;
   Nome, pode conter 50 caracteres;
   Idade, inteiro;
   Curso (enum: Engenharia, Computação, Matemática).
   Funcionalidades: Crie um menu que possibilite o usuário do programa: 
   cadastrar um novo aluno, buscar um aluno por matrícula, e listar todos 
   os alunos de um curso específico.
*/

enum Curso {
    ENGENHARIA,
    COMPUTACAO,
    MATEMATICA
};

struct estudante {
    char matricula[15];
    char nome[50];
    int idade;
    enum Curso curso; 
};

// Função para cadastrar aluno

/*Ao passar um ponteiro para a função CadastrarAluno, você permite que a função modifique diretamente o valor da variável que armazena o total de alunos na função main. Se você passasse totalAlunos como uma variável normal (passagem por valor), a função CadastrarAluno só poderia modificar uma cópia desse valor, e a alteração não afetaria a variável original na função main. Usar um ponteiro permite que a função CadastrarAluno altere o número total de alunos diretamente.*/
void CadastrarAluno(struct estudante estudantes[], int *totalAlunos, char matricula[], char nome[], int idade, enum Curso curso) {
  
    // Verifica espaço para cadastrar um novo aluno
    if (*totalAlunos >= MAX_ESTUDANTES) {
        printf("Não há mais vaga para cadastrar novos estudantes.\n");
        return;
    }

    // Atribuindo os valores do aluno à posição
    strcpy(estudantes[*totalAlunos].matricula, matricula);
    strcpy(estudantes[*totalAlunos].nome, nome);
    estudantes[*totalAlunos].idade = idade;
    estudantes[*totalAlunos].curso = curso;

    printf("Estudante adicionado com sucesso! Matrícula: %s\n", matricula);
    (*totalAlunos)++; // Incrementa o total de alunos cadastrados
}

// Função para imprimir o nome do curso
const char* ObterNomeCurso(enum Curso curso) {
    switch (curso) {
        case ENGENHARIA:
            return "Engenharia";
        case COMPUTACAO:
            return "Computação";
        case MATEMATICA:
            return "Matemática";
        default:
            return "Curso desconhecido";
    }
}

// Função para pesquisar um estudante pelo número da matrícula/GRR
/*Loop que itera sobre todos os estudantes. Compara a matrícula/GRR de cada estudante com a o GRR usando strcmp.*/
void BuscarAluno(struct estudante estudantes[], int tamanho, const char* GRR) {
    for (int i = 0; i < tamanho; i++) {
        /*strcmp é uma função da biblioteca de strings (<string.h>) em C que compara duas strings.
            A função tem a seguinte assinatura:
            int strcmp(const char *str1, const char *str2);
            
            Ela recebe dois ponteiros para strings (cadeias de caracteres) como parâmetros.
            
            Retorno da função:
            A função strcmp retorna um inteiro que indica o resultado da comparação:
            Menor que 0: Se str1 é lexicograficamente menor que str2.
            Igual a 0: Se str1 é igual a str2.
            Maior que 0: Se str1 é lexicograficamente maior que str2.
            
            aqui if os GRRs for Igual a 0 : ALUNO ENCONTRADO*/
        if (strcmp(estudantes[i].matricula, GRR) == 0) { // Compara a matrícula
            printf("Aluno encontrado:\n");
            printf("Matrícula: %s\n", estudantes[i].matricula);
            printf("Nome: %s\n", estudantes[i].nome);
            printf("Idade: %d\n", estudantes[i].idade);
            /* Para imprimir o nome correspondente à posição
               de um enum em C, você precisará criar uma função
               ou um array de strings que associe cada valor do
               enum ao seu nome. */
            printf("Curso: %s\n", ObterNomeCurso(estudantes[i].curso));
            return; // Sai da função após encontrar o aluno
        }
    }
    printf("Aluno com matrícula '%s' não foi encontrado.\n", GRR);
}

void listar_alunos_de_um_curso(struct estudante estudantes[], int tamanho, enum Curso curso) {
    int encontrados = 0;//contar quantos alunos do curso especificado foram encontrados.

    /*int tamanho: O número total de alunos cadastrados, 
    que será usado para determinar até onde o loop deve percorrer. */
    for (int i = 0; i < tamanho; i++) {

        /*se o curso do aluno atual == curso que estamos buscando. Se for verdade, o bloco de código interno será executado.*/
        if (estudantes[i].curso == curso) {
            if (encontrados == 0) {
                printf("Alunos do curso de %s:\n", ObterNomeCurso(curso));
            }
            printf("Matrícula: %s\n", estudantes[i].matricula);
            printf("Nome: %s\n", estudantes[i].nome);
            printf("Idade: %d\n", estudantes[i].idade);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum aluno encontrado no curso de %s.\n", ObterNomeCurso(curso));
    }
}

int main() {
    struct estudante estudantes[MAX_ESTUDANTES]; // Array para armazenar os estudantes
    int totalAlunos = 0; // Contador de alunos cadastrados
    
    char matricula[15];
    char nome[50];
    int idade;
    enum Curso curso; 
    
    char continuar = ' ';

while (1) {
    
    while (1) { // 1°while
        // Pergunta para cadastrar um novo aluno
        printf("Cadastrar um novo aluno (s ou n): ");
        scanf(" %c", &continuar);

        if (continuar == 's') {
            // Dados do estudante
            printf("Digite a matrícula do aluno (GRRXX = GRR00) : ");
            scanf("%s", matricula);
            
            int matriculaDuplicada = 0; // Variável para verificar se a matrícula já existe

            for (int i = 0; i < totalAlunos; i++) {
                if (strcmp(estudantes[i].matricula, matricula) == 0) { 
                    printf("Matrícula já cadastrada, tente outra.\n");
                    matriculaDuplicada = 1; // Define que a matrícula já foi encontrada
                    break; // Sai do loop de verificação
                }
            }

            // Se não houver matrícula duplicada, continua o cadastro
            if (matriculaDuplicada) {
                continue; // Volta ao início do loop principal para pedir nova matrícula
            }

            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]s", nome); // Permite espaços no nome

            printf("Digite a idade do aluno: ");
            scanf("%d", &idade);

            printf("Selecione o curso (0 = Engenharia, 1 = Computação, 2 = Matemática): ");
            scanf("%d", (int*)&curso); // O curso (convertido para enum automaticamente)

            // O curso é válido
            if (curso < 0 || curso > 2) {
                printf("Curso inválido. Tente novamente.\n");
                continue; // Volta para o início do loop se o curso for inválido
            }

            // Chama a função para cadastrar o aluno
            CadastrarAluno(estudantes, &totalAlunos, matricula, nome, idade, curso);
            /*Aqui, &totalAlunos passa o endereço da variável totalAlunos para a função. 
            Isso significa que a função CadastrarAluno pode acessar e modificar o valor original da variável.*/

        } else {
            break; // Sai do loop se a resposta não for 's'
        }
    }

    while (1) { // 2°while
        // Pergunta para buscar um aluno
        printf("Buscar um aluno por matrícula (s ou n): ");
        scanf(" %c", &continuar);
        if (continuar == 's') {
            printf("Digite a matrícula do aluno: ");
            scanf("%s", matricula);
            BuscarAluno(estudantes, totalAlunos, matricula);
        } else {
            break; // Sai do loop se a resposta não for 's'
        }
    }

    while (1) { // 3°while
        // Pergunta para listar todos os alunos
        printf("Listar todos os alunos de um curso específico (s ou n): ");
        scanf(" %c", &continuar);
        if (continuar == 's') {
            printf("Selecione o curso (0 = Engenharia, 1 = Computação, 2 = Matemática): ");
            scanf("%d", (int*)&curso); // O curso (convertido para enum automaticamente)
            
            // O curso é válido
            if (curso < 0 || curso > 2) {
                printf("Curso inválido. Tente novamente.\n");
                continue; // Volta para o início do loop se o curso for inválido
            }
            listar_alunos_de_um_curso(estudantes, totalAlunos, curso);
        } else {
            break; // Sai do loop se a resposta não for 's'
        }
    }

    printf("Deseja cadastrar novos alunos (s ou n): ");
    scanf(" %c", &continuar);
    if (continuar == 's') {
        continue; // Voltar para o início dos loops
    } else {
        break; // Sai do loop principal
    }
}

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
