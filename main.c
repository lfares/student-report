#include "list.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    bool menu = true;

    List *list;

    create(&list);

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

        switch (n){
            case 1:
                Student student;
                printf("Id do aluno: "); scanf("%d", &student._id);
                printf("Horas de estudo: "); scanf("%f", &student.study_hours);
                printf("Nota da prova 1: "); scanf("%f", &student.grade1);
                printf("Nota da prova 2: "); scanf("%f", &student.grade2);

                insert(&list, student);
                break;

            case 2:
                int id_aux;
                printf("Id do aluno para ser removido: "); scanf("%d", &id_aux);
                remove(&list, id_aux);
                break;
            
            case 3:
                print(&list);
                break;
            
            case 4:
                report(&list);
                break;
            
            case 5:
                average_study(&list);
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
