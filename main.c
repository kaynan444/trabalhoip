#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void) {
  turma t;
  InicializarTurma(&t);

  int opcao, opcao2;

do {
  printf("\nDigite uma opção: \n\n1 - Cadastrar aluno\n2 - Remover aluno\n3 - Listar alunos\n4 - Procurar aluno\n0 - Para encerrar\n\n");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1: {
      CadastrarAluno(&t);
    } break;
    case 2:{
      RemoverAluno(&t);
    }break;
    case 3:{
      printf("\nDigite uma opção: \n1 - Listar todos os alunos\n2 - Listar aprovados\n3 - Listar reprovados\n");
      scanf("%d", &opcao2);
        switch(opcao2){
          case 1:{
            ListarTodos(&t);
          }break;
          case 2:{
            ListarAprovados(&t);
          }break;
          case 3:{
            ListarReprovados(&t);
          }break;
          default:{
            printf("Opção inválida");
          }break;
        }
        }break;
        case 4:{
          Procurar(&t);
        }break;
        default:{
          if(opcao == 0){
            printf("Você encerrou sessão");
          } else {
            printf("Opção Inválida");
          }
        }break;
    }
} while (opcao != 0);

    free(t.alunos);

    return 0;
}
