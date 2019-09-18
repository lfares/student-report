#include "list.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    bool menu = true;

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
                /* code */
                break;
            case 2:
                break;
            
            case 3:
                break;
            
            case 4:
                break;
            
            case 5:
                break;
            
            case 6:
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }
    



    return 0;
}
