#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int jogo_da_memoria[4][4];
    int resp_jogo_da_memoria[4][4];
    int cont[8];
    int verificador = 0;

    for(int i = 0; i < 8; i++)
    {
        cont[i] = 0;
    }

    srand(time(NULL));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; )
        {
            

            int num = 1 + rand() % 8;
            
            if(num == 1 && cont[0] < 2)
            {
                cont[0]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 2 && cont[1] < 2)
            {
                cont[1]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 3 && cont[2] < 2)
            {
                cont[2]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 4 && cont[3] < 2)
            {
                cont[3]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 5 && cont[4] < 2)
            {
                cont[4]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 6 && cont[5] < 2)
            {
                cont[5]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 7 && cont[6] < 2)
            {
                cont[6]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }
            else if(num == 8 && cont[7] < 2)
            {
                cont[7]++;
                resp_jogo_da_memoria[i][j] = num;
                j++;
            }

            verificador = 0;
            for(int c = 0; c < 8; c++)
            {
                if(cont[c] == 2)
                {
                    verificador++;
                }

                if(verificador == 8)
                {
                    j++;
                }
            }
        }
    }


    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            jogo_da_memoria[i][j] = 0;
        }
    }


    int l[2], c[2];
    int cont_turno = 1; // jg1 -> joga em turno impar / jg2 -> joga em turno par
    int vezes = 0;
    int p1 = 0, p2 = 0;
    char passavez;

    do
    {
        
        if(cont_turno % 2 != 0)
        {   
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    printf("%i   ", jogo_da_memoria[i][j]);
                }
                printf("\n\n");
            }

            printf("\njg1: %i x jg2: %i", p1, p2);
            printf("\njg1 - Digite uma linha\n> "); // Nao digitaremos linha 0
            scanf("%i", &l[vezes]);
            l[vezes] = l[vezes] - 1;
            printf("\njg1 - Digite uma coluna\n> ");// nao digitaremos coluna 0
            scanf("%i", &c[vezes]);
            c[vezes] = c[vezes] - 1;

            if (l[vezes] < 0 || l[vezes] > 3 || c[vezes] < 0 || c[vezes] > 3)
            {
                printf("Posicao invalida! Tente novamente.\n");
                printf("Pressione 's' para continuar...\n> ");
                scanf(" %c", &passavez);
                system("cls");
                continue; 
            }

            vezes++;

            jogo_da_memoria[l[vezes - 1]][c[vezes - 1]] = resp_jogo_da_memoria[l[vezes - 1]][c[vezes - 1]];
            
            if (vezes == 1) 
            {
                system("cls");
                continue; 
            }

            if(vezes == 2 && l[0] == l[1] && c[0] == c[1])
            {
                printf("Voce escolheu a mesma carta duas vezes!\n");
                jogo_da_memoria[l[0]][c[0]] = 0; 
            }
            else if((resp_jogo_da_memoria[l[0]][c[0]] == resp_jogo_da_memoria[l[1]][c[1]]) && vezes == 2)
            {
                p1++;
            }
            

            if(vezes == 2)
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        printf("%i   ", jogo_da_memoria[i][j]);
                    }
                    printf("\n\n");
                }
            }

            if((resp_jogo_da_memoria[l[0]][c[0]] != resp_jogo_da_memoria[l[1]][c[1]]) && vezes == 2)
            {
                jogo_da_memoria[l[0]][c[0]] = 0;
                jogo_da_memoria[l[1]][c[1]] = 0;
            }

            if(vezes == 2)
            {
                printf("Para passar a vez digite 's'\n> ");
                scanf(" %c", &passavez);
                cont_turno++;
                vezes = 0;
                system("cls");
            }

        }
        else if(cont_turno % 2 == 0)
        {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    printf("%i   ", jogo_da_memoria[i][j]);
                }
                printf("\n\n");
            }

            
            printf("\njg1: %i x jg2: %i", p1, p2);
            printf("\njg2 - Digite uma linha\n> "); // Nao digitaremos linha 0
            scanf("%i", &l[vezes]);
            l[vezes] = l[vezes] - 1;
            printf("\njg2 - Digite uma coluna\n> ");// nao digitaremos coluna 0
            scanf("%i", &c[vezes]);
            c[vezes] = c[vezes] - 1;

            if (l[vezes] < 0 || l[vezes] > 3 || c[vezes] < 0 || c[vezes] > 3)
            {
                printf("Posicao invalida! Tente novamente.\n");
                printf("Pressione 's' para continuar...\n> ");
                scanf(" %c", &passavez);
                system("cls");
                continue; 
            }

            vezes++;

            jogo_da_memoria[l[vezes - 1]][c[vezes - 1]] = resp_jogo_da_memoria[l[vezes - 1]][c[vezes - 1]];

            if (vezes == 1) 
            {
                system("cls");
                continue; 
            }

            if(vezes == 2 && l[0] == l[1] && c[0] == c[1])
            {
                printf("Voce escolheu a mesma carta duas vezes!\n");
                jogo_da_memoria[l[0]][c[0]] = 0; 
            }
            else if((resp_jogo_da_memoria[l[0]][c[0]] == resp_jogo_da_memoria[l[1]][c[1]]) && vezes == 2)
            {
                p2++;
            }
            
            if(vezes == 2)
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        printf("%i   ", jogo_da_memoria[i][j]);
                    }
                    printf("\n\n");
                }
            }

            if((resp_jogo_da_memoria[l[0]][c[0]] != resp_jogo_da_memoria[l[1]][c[1]]) && vezes == 2)
            {
                jogo_da_memoria[l[0]][c[0]] = 0;
                jogo_da_memoria[l[1]][c[1]] = 0;
            }

            if(vezes == 2)
            {
                printf("Para passar a vez digite 's'\n> ");
                scanf(" %c", &passavez);
                cont_turno++;
                vezes = 0;
                system("cls");
            }
        }
    }while(p1 + p2 != 8);

    system("cls");
    if(p1 > p2)
    {
        printf("O jg1 GANHOU!!");
    }
    else if(p1 < p2)
    {
        printf("O jg2 GANHOU!!");
    }
    else
    {
        printf("Empatou!!");
    }

}
