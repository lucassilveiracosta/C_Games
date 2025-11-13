#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void)
{
    srand(time(NULL));
    int tam = 10;
    char tabuleiro[10][10];

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++) // preenchendo o tabuleiro com '_'
        {
            tabuleiro[i][j] = '_';
        }

    }

    int R_l = rand() % tam;
    int R_c = rand() % tam;

    tabuleiro[R_l][R_c] = 'R'; // Colocando Rick no tabuleiro
    int contX = 0, contZ = 0, contB = 0;
    for(int i = 0; i < 8; )
    {
        int X_l = rand() % 10;
        int X_c = rand() % 10;
        if(tabuleiro[X_l][X_c] == '_' && contX < 8)
        {
            // printf("ENTROU");
            tabuleiro[X_l][X_c] = 'X';
            contX++;
        }
        
        int Z_l = rand() % 10;
        int Z_c = rand() % 10;
        if(tabuleiro[Z_l][Z_c] == '_' && contZ < 8)
        {
            // printf("ENTROU");
            tabuleiro[Z_l][Z_c] = 'Z';
            contZ++;
        }

        int B_l = rand() % 10;
        int B_c = rand() % 10;
        if(tabuleiro[B_l][B_c] == '_' && contB < 8)
        {
            // printf("ENTROU");
            tabuleiro[B_l][B_c] = '.';
            contB++;
        }
        

        if(contX + contZ + contB  == 24)
        {
            i = 9;
        }
    }

    int s_l, s_c;
    
    for(int i = 0; i < 1; ) // fazendo a saída
    {
        s_l = rand() % 10;
        s_c = rand() % 10;
        if(tabuleiro[s_l][s_c] == '_')
        {
            tabuleiro[s_l][s_c] = '[';
            i++;
        }
            
    }



    printf("\n");
    
    char mov;
    int balas = 0;
    int vidas = 3;
    int cont_vidas = 3;
    int confirmacao = 0;
    int Zumbis = 0;
    int saida = 0;
    do
    {
        system("cls");
        if(vidas == 0)
        {
            confirmacao = 1;
        }
        
        for(int i = 0; i < tam; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                printf("%c  ",tabuleiro[i][j]);
            }
            printf("\n");
        }

        if(confirmacao != 1)
        {
            printf("\nVidas: %i", vidas);
            printf("\nZumbis derrotados: %i", Zumbis);
            printf("\nQntd Balas: %i", balas);
            printf("\n> ");
            scanf("%c", &mov);
            getchar();
        }

        switch(mov)//              MOVIMENTACAO RICK
        {
            case 'w':
                if(R_l - 1 >= 0 && tabuleiro[R_l - 1][R_c] != 'X')
                {
                    tabuleiro[R_l][R_c] = '_';
                    if(tabuleiro[R_l - 1][R_c] == '.')
                    {
                        balas++;
                    }

                    if(tabuleiro[R_l - 1][R_c] == '[')
                    {
                        saida++;
                        tabuleiro[R_l][R_c] = '_';
                    }
                    
                    if(tabuleiro[R_l - 1][R_c] == 'Z' && balas > 0)
                    {
                        balas--;
                        Zumbis++;
                    }
                    else if(tabuleiro[R_l - 1][R_c] == 'Z' && balas == 0)
                    {
                        vidas--;
                        cont_vidas--;

                        if(vidas == 0)
                        {
                            tabuleiro[R_l - 1][R_c] = 'Z';
                            cont_vidas--;
                        }
                    }
                    if(vidas != 0)
                    {
                        tabuleiro[R_l - 1][R_c] = 'R';
                        R_l--;
                    }
                }
            break;
            case 's':
                if(R_l + 1 < tam && tabuleiro[R_l + 1][R_c] != 'X')
                {
                    tabuleiro[R_l][R_c] = '_';
                    if(tabuleiro[R_l + 1][R_c] == '.')
                    {
                        balas++;
                    }

                    if(tabuleiro[R_l + 1][R_c] == '[')
                    {
                        saida++;
                        tabuleiro[R_l][R_c] = '_';
                    }
                    
                    if(tabuleiro[R_l + 1][R_c] == 'Z' && balas > 0)
                    {
                        balas--;
                        Zumbis++;
                    }
                    else if(tabuleiro[R_l + 1][R_c] == 'Z' && balas == 0)
                    {
                        vidas--;
                        cont_vidas--;

                        if(vidas == 0)
                        {
                            tabuleiro[R_l + 1][R_c] = 'Z';
                            cont_vidas--;
                        }
                    }
                    if(vidas != 0)
                    {
                        tabuleiro[R_l + 1][R_c] = 'R';
                        R_l++;
                    }
                }
            break;
            case 'd':
                if(R_c + 1 < tam && tabuleiro[R_l][R_c + 1] != 'X')
                {
                    tabuleiro[R_l][R_c] = '_';
                    if(tabuleiro[R_l][R_c + 1] == '.')
                    {
                        balas++;
                    }
                    
                    if(tabuleiro[R_l][R_c + 1] == '[')
                    {
                        saida++;
                        tabuleiro[R_l][R_c] = '_';
                    }
                    
                    if(tabuleiro[R_l][R_c + 1] == 'Z' && balas > 0)
                    {
                        balas--;
                        Zumbis++;
                    }
                    else if(tabuleiro[R_l][R_c + 1] == 'Z' && balas == 0)
                    {
                        vidas--;
                        cont_vidas--;

                        if(vidas == 0)
                        {
                            tabuleiro[R_l][R_c + 1] = 'Z';
                            cont_vidas--;
                        }
                    }
                    if(vidas != 0)
                    {
                        tabuleiro[R_l][R_c + 1] = 'R';
                        R_c++;
                    }
                }
            break;
            case 'a':
                if(R_c - 1 >= 0 && tabuleiro[R_l][R_c - 1] != 'X')
                {
                    tabuleiro[R_l][R_c] = '_';
                    if(tabuleiro[R_l][R_c - 1] == '.')
                    {
                        balas++;
                    }

                    if(tabuleiro[R_l][R_c - 1] == '[')
                    {
                        saida++;
                        tabuleiro[R_l][R_c] = '_';
                    }
                    
                    if(tabuleiro[R_l][R_c - 1] == 'Z' && balas > 0)
                    {
                        balas--;
                        Zumbis++;
                    }
                    else if(tabuleiro[R_l][R_c - 1] == 'Z' && balas == 0)
                    {
                        cont_vidas--;
                        vidas--;
                        

                        if(vidas == 0)
                        {
                            tabuleiro[R_l][R_c - 1] = 'Z';
                            cont_vidas--;
                        }
                    }

                    if(vidas != 0)
                    {
                        tabuleiro[R_l][R_c - 1] = 'R';
                        R_c--;
                    }
                }
            break;
            default:;
        }

        /*for(int i = 0; i < tam; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(tabuleiro[i][j] == 'Z')
                {
                    mov_Z = rand() % 4;

                    switch(mov_Z)
                    {
                        case 0:
                            if(i - 1 >= 0 && tabuleiro[i - 1][j] != 'X' && tabuleiro[i - 1][j] != 'Z' && tabuleiro[i - 1][j] != '.')
                            {
                                tabuleiro[i][j] = '_';
                                tabuleiro[i - 1][j] = 'Z';
                                
                            }
                        break;
                        case 1:
                            if(j + 1 < tam && tabuleiro[i][j + 1] != 'X' && tabuleiro[i][j + 1] != 'Z' && tabuleiro[i][j + 1] != '.')
                            {
                                tabuleiro[i][j] = '_';
                                tabuleiro[i][j + 1] = 'Z';
                            }
                        break;
                        case 2:
                            if(i + 1 < tam && tabuleiro[i + 1][j] != 'X' && tabuleiro[i + 1][j] != 'Z' && tabuleiro[i + 1][j] != '.')
                            {
                                tabuleiro[i][j] = '_';
                                tabuleiro[i + 1][j] = 'Z';
                                
                            }
                        break;
                        case 3:
                            if(j - 1 >= 0 && tabuleiro[i][j - 1] != 'X' && tabuleiro[i][j - 1] != 'Z' && tabuleiro[i][j - 1] != '.')
                            {
                                tabuleiro[i][j] = '_';
                                tabuleiro[i][j - 1] = 'Z';
                                
                            }
                        break;
                        default:;
                    }
                }
            }
        }*/    

        int antisurf = 0;
        for(int i = R_l - 2; i <= R_l + 2; i++)
        {
            if(i < 0 || i >= tam)
            {
                continue;
            }
            for(int j = R_c - 2; j <= R_c + 2; j++)
            {
                if(j < 0 || j >= tam)
                {
                    continue;
                }
                if(i == R_l && j < R_c)// a esquerda de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i][j + 1] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                        }
                        else if(tabuleiro[i][j + 1] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i][j + 1] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i < R_l && j == R_c)// acima de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i + 1][j] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                        }
                        else if(tabuleiro[i + 1][j] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i + 1][j] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i > R_l && j == R_c)// abaixo de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i - 1][j] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                        }
                        else if(tabuleiro[i - 1][j] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i - 1][j] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i == R_l && j > R_c)// a direita de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i][j - 1] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                            
                        }
                        else if(tabuleiro[i][j - 1] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i][j - 1] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i < R_l && j < R_c)// Canto superior esquerdo de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i][j + 1] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                        }
                        else if(tabuleiro[i][j + 1] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i][j + 1] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i < R_l && j > R_c)// Canto superior direito de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i + 1][j] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                        }
                        else if(tabuleiro[i + 1][j] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i + 1][j] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i > R_l && j > R_c)// Canto inferior direito de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i][j - 1] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                            
                        }
                        else if(tabuleiro[i][j - 1] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i][j - 1] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
                else if(i > R_l && j < R_c)// Canto inferior esquerdo de rick
                {
                    if(tabuleiro[i][j] == 'Z' && antisurf == 0)
                    {
                        if(tabuleiro[i - 1][j] == 'R')
                        {
                            if(balas == 0)
                            {
                                vidas--;
                                tabuleiro[i][j] = '_';
                            }
                            else
                            {
                                tabuleiro[i][j] = '_';
                                balas--;
                                Zumbis++;
                            }
                            antisurf = 1;
                        }
                        else if(tabuleiro[i - 1][j] == '_')
                        {
                            tabuleiro[i][j] = '_';
                            tabuleiro[i - 1][j] = 'Z';
                            antisurf = 1;
                        }
                    }
                }
            }
        }

        if(saida == 1)
        {
            break;
        }

        int zumbis_mortos = 0;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(tabuleiro[i][j] == 'Z')
                {
                    zumbis_mortos++;
                }
            }
        }

        if(zumbis_mortos == 0)
        {
            confirmacao = 1;
        }
    }while(confirmacao != 1);

    if(saida == 1)
    {
        printf("\nVoce escapou!!");
    }
    
    int cont_zumbi = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(tabuleiro[i][j] == 'Z')
            {
                cont_zumbi++;
            }
        }
    }
    if(cont_zumbi == 0)
    {
        printf("\nVoce derrotou todos os zumbis!");
    }

    if(vidas == 0)
    {
        printf("\nVoce morreu");
    }
}
