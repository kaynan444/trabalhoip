#ifndef funcoes_h
#define funcoes_h
#include <stdio.h>
#include <stdlib.h>


typedef struct {
 int faltas[7];
 int matricula;
int codTurma;
float notas[7];
char nome[50];
} aluno;

typedef struct {
    aluno *alunos;
    int qtdAlunos;
    int id;
} turma;

void InicializarTurma(turma *t);
void CadastrarAluno(turma *t);
void RemoverAluno(turma *t);
void ListarTodos(turma *t);
void ListarAprovados(turma *t);
void ListarReprovados(turma *t);
void Procurar(turma *t);

#define MAX 10
#endif
