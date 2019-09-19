#include "list.h"
#include <stdio.h>
#include <stdbool.h>

#define ERROR_MESSAGE "Lista vazia.\n"
#define TAM_MAX 100

int main(){
    bool menu = true;

    List *list;

    create_list(&list);

    while (menu == true){
        printf("Escolha uma opção do menu principal.\n");
        printf("(1) Inserir novo registro.\n"
            "(2) Remover registro.\n"
            "(3) Imprimir registros.\n"
            "(4) Imprimir relatório de aprovação.\n"
            "(5) Imprimir média de horas de estudo.\n"
            "(6) Sair.\n");
        
        int n;
        scanf("%d", &n);

        Student students[TAM_MAX];
        int i = 0;
        int id_aux;
        switch (n){
            case 1:
                printf("Id do aluno: "); scanf("%d", &students[i]._id);
                printf("Horas de estudo: "); scanf("%f", &students[i].study_hours);
                printf("Nota da prova 1: "); scanf("%f", &students[i].grade1);
                printf("Nota da prova 2: "); scanf("%f", &students[i].grade2);

                insert_elem(list, students[i]);
                i++;
                break;

            case 2:
                printf("Id do aluno para ser removido: "); scanf("%d", &id_aux);
                if (remove_elem(list, id_aux) == 1)
                    printf(ERROR_MESSAGE);
                break;
            
            case 3:
                if (print(list) == 1)
                    printf(ERROR_MESSAGE);
                break;
            
            case 4:
                if (report(list) == 1)
                    printf(ERROR_MESSAGE);
                break;
            
            case 5:
                if (average_study(list) == 1)
                    printf(ERROR_MESSAGE);
                break;
            
            case 6:
                destroy(&list);
                menu = false;
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
