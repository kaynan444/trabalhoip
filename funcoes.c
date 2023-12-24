#include "funcoes.h"
//função para alocar memória para a turma
void InicializarTurma(turma *t) {
  t->alunos = (aluno*) malloc(MAX * sizeof(aluno));
    if(t->alunos == NULL) {
      printf("Erro ao alocar memória\n");
      exit(EXIT_FAILURE);
    }
  t->qtdAlunos = 0;
  t->id = 0;
} //verifica se a matricula cadastrada já existe
int matricula_valida(turma *t, int matricula) {
  for(int i = 0; i < t->qtdAlunos; i++) {
    if(t->alunos[i].matricula == matricula) {
      return 1;
    }
  }
  return 0;
} //função que recebe os dados do aluno e os armazena na estruct
void CadastrarAluno(turma *t) {
  int matricula;
  printf("\nDigite a matrícula do aluno: \n");
  scanf("%d", &t->alunos[t->qtdAlunos].matricula);
  matricula = t->alunos[t->qtdAlunos].matricula;
  if(t->alunos[t->qtdAlunos].matricula <2023001 || t->alunos[t->qtdAlunos].matricula > 2023999) {
    printf("Erro no formato da matricula, informe uma matricula entre 2023001 e 2023999.\n");
    return;
  }
  if(matricula_valida(t, matricula)) {
    printf("Matrícula já cadastrada, pro favor informe uma nova\n");
    return;
  }
  printf("\nInforme o nome do aluno: \n");
  scanf("%s", t->alunos[t->qtdAlunos].nome);
  printf("\nInforme as 7 medias do aluno: \n");
  for(int i = 0; i < 7; i++) {
    scanf("%f", &t->alunos[t->qtdAlunos].notas[i]);
  }
  printf("\n\nInforme a quantidade de faltas do aluno\n");
  for (int i = 0; i < 7; i++) {
     scanf("%d", &t->alunos[t->qtdAlunos].faltas[i]); 
  }
  printf("Informe o codigo da turma do aluno: \n");
  scanf("%d", &t->alunos[t->qtdAlunos].codTurma);

  t->qtdAlunos++;
  printf("Aluno cadastrado om sucesso");

  if(t->qtdAlunos == MAX) {
    t->alunos = (aluno*) realloc(t->alunos, (MAX + 10) * sizeof(aluno));
    if(t->alunos == NULL) {
      printf("Erro ao alocar memória\n");
      exit(EXIT_FAILURE);
    }
  return;
  } 
  FILE *arquivo;
    arquivo = fopen("relatorio.txt", "a");
   if(arquivo == NULL) {
     printf( "Erro ao abrir o arquivo\n");
     exit(EXIT_FAILURE);
   }
    fprintf(arquivo, "Aluno cadastrado\n");
    fprintf(arquivo, "Nome: %s\n", t->alunos[t->qtdAlunos].nome);
    fprintf(arquivo, "Matricula: %d\n", t->alunos[t->qtdAlunos].matricula);
    fprintf(arquivo, "Notas: ");
    for(int j = 0; j < 7; j++) {
      fprintf(arquivo, "%.2f ", t->alunos[t->qtdAlunos].notas[j]);
    }
    fprintf(arquivo, "\nFaltas: ");
    printf("Notas: ");
    for(int k = 0; k < 7; k++) {
      printf("%d ", t->alunos[t->qtdAlunos].faltas[k]);
    }
    fprintf(arquivo, "Codigo da turma: %d\n", t->alunos[t->qtdAlunos].codTurma);
    fprintf(arquivo, "\n\n");
    fclose(arquivo);
} //função para remover o aluno
void RemoverAluno(turma *t) {
  int matricula;
  int encontrar = 0;

  if(t->qtdAlunos == 0) {
    printf("Nenhum aluno cadastrado\n");
    return;
  }
  printf("Digite a matricula do aluno que deseja remover: \n");
  scanf("%d", &matricula);
  for(int i = 0; i < t->qtdAlunos; i++) {
    if(t->alunos[i].matricula == matricula) {
      encontrar = 1;
      for(int j = i; j < t->qtdAlunos - 1; i++) {
        t->alunos[j] = t->alunos[j + 1];
      }
      (t->qtdAlunos)--;
      printf("Aluno removido com sucesso\n");
      break;
    }
  }
  if(!encontrar) {
    printf("Aluno não encontrado\n");
  } 
  FILE *arquivo;
    arquivo = fopen("relatorio.txt", "a");
   if(arquivo == NULL) {
     printf( "Erro ao abrir arquivo\n");
     exit(EXIT_FAILURE);
   }
  if(t->qtdAlunos == 0) {
    fprintf(arquivo, "Nenhum aluno cadastrado\n");
  }
  if(!encontrar) {
    fprintf(arquivo, "Aluno não encontrado\n");
  }
  fprintf(arquivo, "%s removido\n", t->alunos[t->qtdAlunos].nome);
  fclose(arquivo);
} //lista todos os alunos
void ListarTodos(turma *t) {
  if(t->qtdAlunos == 0) {
    printf("Nenhum aluno cadastrado\n");
    return;
  }
  printf( "Alunos cadastrados: \n");
  for(int i = 0; i < t->qtdAlunos; i++) {
    printf("Nome: %s\n", t->alunos[i].nome);
    printf("Matricula: %d\n", t->alunos[i].matricula);
    printf("Notas: ");
      for(int j = 0; j < 7; j++) {
        printf("%.2f ", t->alunos[i].notas[j]);
      }
    printf("\nfaltas: ");
    for(int k = 0; k < 7; k++) {
      printf("%d ", t->alunos[i].faltas[k]);
    }
    printf("\nCodigo da turma: %d\n", t->alunos[i].codTurma);
    printf("\n");
  }
  FILE *arquivo;
    arquivo = fopen("relatorio.txt", "a");
   if(arquivo == NULL) {
     printf( "Erro ao abrir arquivo\n");
     exit(EXIT_FAILURE);
  } 
  if(t->qtdAlunos == 0) {
    fprintf(arquivo, "Nenhum aluno cadastrado\n");
    exit(EXIT_FAILURE);
  } else {
    fprintf(arquivo, "Alunos cadastrados: \n");
    for(int i = 0; i < t->qtdAlunos; i++) {
      fprintf(arquivo, "Nome: %s\n", t->alunos[i].nome);
      fprintf(arquivo, "Matricula: %d\n", t->alunos[i].matricula);
      fprintf(arquivo, "Notas: ");
        for(int j = 0; j < 7; j++) {
          fprintf(arquivo, "%.2f ", t->alunos[i].notas[j]);
        }
        fprintf(arquivo, "\nfaltas: ");
        for(int k = 0; k < 7; k++) {
          fprintf(arquivo, "%d ", t->alunos[i].faltas[k]);
        }
      fprintf(arquivo, "\nCodigo da turma: %d\n", t->alunos[i].codTurma);
      fprintf(arquivo, "\n\n");
    }
  }
  fclose(arquivo);
} //função que ferifica se o aluno está aprovado ou reprovado
int verifica_aprovacao(aluno *a) {
  for(int i = 0; i < 7; i++) {
    if(a->notas[i] < 7) {
      return 0;
    }
  }
  return 1;
} // lista apenas os alunos que obtem retorno 1 da função verifica_aprovacao
void ListarAprovados(turma *t) {
  int aprovados = 0;
  if(t->qtdAlunos == 0) {
    printf("Nenhum aluno cadastrado\n");
    return;
  }
  printf("Alunos aprovados:\n");
  for(int i = 0; i < t->qtdAlunos; i++) {
    aprovados++;
    if(verifica_aprovacao(&t->alunos[i]) == 1) {
      printf("Nome: %s\n", t->alunos[i].nome);
      printf("Matricula: %d\n", t->alunos[i].matricula);
      printf("Codigo da turma: %d\n", t->alunos[i].codTurma);
    }
  }
  if(aprovados == 0) {
    printf("Nenhum aluno aprovado\n");
  } 
  FILE *arquivo;
    arquivo = fopen("relatorio.txt", "a");
   if(arquivo == NULL) {
    printf( "Erro ao abrir arquivo\n");
    exit(EXIT_FAILURE);
  }
  if(t->qtdAlunos == 0) {
    fprintf(arquivo, "Nenhum aluno cadastrado\n");
  } else if(aprovados == 0) {
    fprintf(arquivo, "Nenhum aluno aprovado\n");
  } else {
    fprintf(arquivo, "Alunos aprovados:\n");
    for(int i = 0; i < t->qtdAlunos; i++) {
      if(verifica_aprovacao(&t->alunos[i]) == 1) {
        fprintf(arquivo, "Nome: %s\n", t->alunos[i].nome);
        fprintf(arquivo, "Matricula: %d\n", t->alunos[i].matricula);
        fprintf(arquivo, "Codigo da turma: %d\n", t->alunos[i].codTurma);
      }
    }
  }
  fclose(arquivo);
} //lista apenas os alunos que obtem retorno 0 da função verifica_aprovacao
void ListarReprovados(turma *t){
  int reprovados = 0;
  if(t->qtdAlunos == 0) {
    printf("Nenhum aluno cadastrado\n");
    return;
    }
    printf("Alunos reprovados:\n");
    for(int i = 0; i < t->qtdAlunos; i++) {
      reprovados++;
      if(verifica_aprovacao(&t->alunos[i]) == 0) {
        printf("Nome: %s\n", t->alunos[i].nome);
        printf("Matricula: %d\n", t->alunos[i].matricula);
        printf("Codigo da turma: %d\n", t->alunos[i].codTurma);

      }
    }
    if(reprovados == 0) {
      printf("Nenhum aluno aprovado\n");
    }
    FILE *arquivo;
      arquivo = fopen("relatorio.txt", "a");
      if(arquivo == NULL) {
        printf( "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
      }
      if(t->qtdAlunos == 0) {
        fprintf(arquivo, "Nenhum aluno cadastrado\n");
      } else if(reprovados == 0) {
        fprintf(arquivo, "Nenhum aluno reprovado\n");
      } else {
        fprintf(arquivo, "Alunos reprovados:\n");
        for(int i = 0; i < t->qtdAlunos; i++) {
          if(verifica_aprovacao(&t->alunos[i]) == 0) {
            fprintf(arquivo, "Nome: %s\n", t->alunos[i].nome);
            fprintf(arquivo, "Matricula: %d\n", t->alunos[i].matricula);
            fprintf(arquivo, "Codigo da turma: %d\n", t->alunos[i].codTurma);
            fprintf(arquivo, "\n\n");
          }
        }
      }
      fclose(arquivo);
    }//usa a matricula para encontrar o aluno e mostrar suas informações

void Procurar(turma *t){
  int matricula;
  int encontrado = 0;
    printf("Digite a matricula do aluno:\n");
    scanf("%d", &matricula);
    for(int i = 0; i < t->qtdAlunos; i++) {
      if(matricula == t->alunos[i].matricula) {
        encontrado = 1;
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", t->alunos[i].nome);
        printf("Notas: ");
        for (int j = 0; j < 7; j++) {
          printf("%.2f ", t->alunos[i].notas[j]);
        }
        printf("\nFaltas: ");
        for (int j = 0; j < 7; j++) {
          printf("%d ", t->alunos[i].faltas[j]);
        }
        printf("\nCodigo da turma: %d\n", t->alunos[i].codTurma);
        printf("\n");
        break;
      }
    }
    if(!encontrado) {
      printf("Aluno nao encontrado\n");
    } 
    FILE *arquivo;
      arquivo = fopen("relatorio.txt", "a");
      if(arquivo == NULL) {
        printf( "Erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
      }
      if(t->qtdAlunos == 0) {
        fprintf(arquivo, "Nenhum aluno cadastrado\n");
      } else if(!encontrado) {
        fprintf(arquivo, "Aluno nao encontrado\n");
      } else {
        fprintf(arquivo, "Aluno encontrado:\n");
        for(int i = 0; i < t->qtdAlunos; i++) {
          fprintf(arquivo, "Nome: %s\n", t->alunos[i].nome);
          fprintf(arquivo, "Matricula: %d\n", t->alunos[i].matricula);
          fprintf(arquivo, "Notas: ");
          for(int j = 0; j < 7; j++) {
            fprintf(arquivo, "%.2f ", t->alunos[i].notas[j]);
          }
          fprintf(arquivo, "\nfaltas: ");
          for(int k = 0; k < 7; k++) {
            fprintf(arquivo, "%d ", t->alunos[i].faltas[k]);
          }
          fprintf(arquivo, "\nCodigo da turma: %d\n", t->alunos[i].codTurma);
          fprintf(arquivo, "\n\n");
        }
      }
      fclose(arquivo);
    }

//exibe o numero de alunos cadastrados
void quant_alunos(turma *t) {
  int quantidade = 0;
  quantidade = t->qtdAlunos;
  if(quantidade == 0) {
    printf("Nenhum aluno cadastrado\n");
  } else {
    printf("Quantidade de alunos: %d\n", quantidade);
  }
}
