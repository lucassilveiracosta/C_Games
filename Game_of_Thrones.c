#include <stdio.h>
#include <time.h>

void main()
{
    int jogar_novamente = 1;
    
    do
    {
        system("cls");
        char westeros[10][10];
        srand(time(NULL));
        int morreu = 0;
        char ganha_tempo;

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                westeros[i][j] = '_'; // Formando Westeros
            }
        }
        
        int l_j = 0, c_j = 1;
        westeros[l_j][c_j] = 'J'; // Jon Snow

        westeros[0][0] = 'W'; // Winterfell
        westeros[4][4] = 'C'; // Cersei
        westeros[9][9] = 'N'; // Rei da Noite

        /*for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                printf("%c  ", westeros[i][j]);   APENAS PARA VERIFICAR O TABULEIRO
            }
            printf("\n");
        }*/

        int cont_x = 0;
        while(cont_x <= 10)
        {
            int l_x, c_x;
            l_x = rand() % 10;
            c_x = rand() % 10;
            if(westeros[l_x][c_x] == '_')
            {
                westeros[l_x][c_x] = 'x';  // OBSTACULOS
                cont_x++;
            }
        }

        int cont_i = 0;
        while(cont_i <= 20)
        {
            int l_i, c_i;
            l_i = rand() % 10;
            c_i = rand() % 10;
            if(westeros[l_i][c_i] == '_')
            {
                westeros[l_i][c_i] = 'i';  // INIMIGOS
                cont_i++;
            }
        }

        int cont_v = 0;
        while(cont_v <= 10)
        {
            int l_v, c_v;
            l_v = rand() % 10;
            c_v = rand() % 10;
            if(westeros[l_v][c_v] == '_')
            {
                westeros[l_v][c_v] = 'o';  // PORCOES DE VIDA
                cont_v++;
            }
        }

        /*for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                printf("%c  ", westeros[i][j]);   APENAS PARA VERIFICAR O TABULEIRO
            }
            printf("\n");
        }*/

        char mov;
        int vida_j = 100;
        
    
        do
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    printf("%c  ", westeros[i][j]);
                }
                printf("\n");
            }

            //Movimentacao Jon Snow
            printf("\nVida: %i", vida_j);
            printf("\nMovimente Jon Snow no tabuleiro -> (WASD)---'obs: Caso John trave, digite a mesma letra duas vezes ex.:'ss''\n> ");
            scanf("%c", &mov);
            getchar();

            switch(mov)
            {
                case 'w':
                    if(l_j - 1 >= 0 && westeros[l_j - 1][c_j] != 'x')
                    {
                        if(westeros[l_j - 1][c_j] == 'i')
                        {
                            vida_j--;
                        }
                        if(westeros[l_j - 1][c_j] == 'o')
                        {
                            if(vida_j <= 95)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 95 && vida_j <= 100)
                            {
                                vida_j = 100;
                            }
                            else if(vida_j <= 195 && vida_j > 100)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 195)
                            {
                                vida_j = 200;
                            }
                        }
                        westeros[l_j][c_j] = '_';
                        westeros[l_j - 1][c_j] = 'J';
                        l_j--; // POSICAO ATUALIZADA

                        if(westeros[l_j - 1][c_j] == 'C' || westeros[l_j][c_j - 1] == 'C' || westeros[l_j + 1][c_j] == 'C' || westeros[l_j][c_j + 1] == 'C') // NEGOCIACAO COM CERESEI
                        {
                            system("cls");

                            for(int i = 0; i < 10; i++)
                            {
                                for(int j = 0; j < 10; j++)
                                {
                                    printf("%c  ", westeros[i][j]);
                                }
                                printf("\n");
                            }
                        
                            
                            printf("\nVoce se encontrou com Cersei, negocie com ele\npara convence-lo a participar da batalha contra o\nRei da Noite.");
                            printf("Digite 's' para iniciar\n> ");
                            scanf("%c", &ganha_tempo);
                            getchar();
                            int dado1, dado2, cont_n = 0, tentativas = 0;
                            do
                            {
                                printf("\nNegociacao - Caso voce tire mais de 60/100 3 vezes, sua negociacao tera sucesso,\ncaso contrario, vera as consequencias...");
                                printf("\nJoguemos os dados...");

                                dado1 = 1 + rand() % 6;
                                dado2 = 1 + rand() % 6;

                                float p_de_negociacao = (float)(dado1+dado2) / 12; 
                                if(p_de_negociacao > 0.6)
                                {
                                    cont_n++;
                                }
                                tentativas++;
                                printf("\nNegociacao: %i/3\nTenteativas: %i\nResultado:\nDado 1: %i\nDado 2: %i\nPoder de negociacao: %.1f",cont_n, tentativas, dado1, dado2, p_de_negociacao * 100);
                                printf("\nDigite 's' para ir para a proxima rodada\n> ");
                                scanf("%c", &ganha_tempo);
                                getchar();
                            }while(tentativas <= 4);


                            if(cont_n >= 3)//Negociacao sucesso
                            {
                                system("cls");
                                printf("\nSua negociacao foi um sucesso!\nVoce ganhou mais 100 pontos de vida!");
                                vida_j += 100;
                                westeros[4][4] = '_';
                                printf("\nDigite 's' para voltar ao tabuleiro\n> ");
                                scanf("%c", &ganha_tempo);
                                
                            }
                            else    //Negociacao fracasso
                            {
                                system("cls");
                                int turnos = 1;
                                int dado_ataque1, dado_ataque2;
                                float ataque;
                                int vida_c = 100;
                                printf("\nSua negociacao falhou...\nVoce entrou em guerra com Cersei");
                                printf("\nAlcance mais de 50/100 no dado para atacar Ceresei,\nporem o mesmo vale para Cersei lhe atacar!");
                                printf("Sua vida: %i\nVida inicial de Cersei: 100", vida_j);

                                do
                                {
                                    if(turnos == 1)// John Snow
                                    {   
                                        printf("\n\n***JOHN SNOW***");
                                        printf("\njoguem os dados...");
                                        
                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_c -= 10;
                                            printf("\nVoce atacou Cersei! <--");
                                        }
                                        else
                                        {
                                            printf("\nSeu ataque falhou <--");
                                        }

                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 0;
                                    }
                                    else    // Cersei
                                    {
                                        printf("\n\n***CERSEI***");
                                        printf("\njoguem os dados...");
                                        

                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_j -= 10;
                                            printf("\nCersei lhe atacou! <--");
                                        }
                                        else
                                        {
                                            printf("\nO ataque de Cersei falhou <--");
                                        }


                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 1;
                                    }

                                    if(vida_j <= 0)
                                    {
                                        system("cls");
                                        printf("\nCersei matou voce...");
                                        printf("\nFIM DE JOGO");
                                        morreu = 1;
                                        printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                        scanf("%i", &jogar_novamente);
                                        break;
                                    }
                                    else if(vida_c <= 0)
                                    {
                                        system("cls");
                                        printf("\nVoce matou Cersei!");
                                        westeros[4][4] = '_';
                                        printf("\nDigite 's' para voltar a westeros\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        break;
                                    }
                                }while(vida_j > 0);
                            }
                        }
                    }
                break;
                case 'a':
                    if(c_j - 1 >= 0 && westeros[l_j][c_j - 1] != 'x')
                    {
                        if(westeros[l_j][c_j - 1] == 'i')
                        {
                            vida_j--;
                        }
                        if(westeros[l_j][c_j - 1] == 'o')
                        {
                            if(vida_j <= 95)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 95 && vida_j <= 100)
                            {
                                vida_j = 100;
                            }
                            else if(vida_j <= 195 && vida_j > 100)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 195)
                            {
                                vida_j = 200;
                            }
                        }
                        westeros[l_j][c_j] = '_';
                        westeros[l_j][c_j - 1] = 'J';
                        c_j--; // POSICAO ATUALIZADA

                        if(westeros[l_j - 1][c_j] == 'C' || westeros[l_j][c_j - 1] == 'C' || westeros[l_j + 1][c_j] == 'C' || westeros[l_j][c_j + 1] == 'C') // NEGOCIACAO COM CERESEI
                        {
                            system("cls");

                            for(int i = 0; i < 10; i++)
                            {
                                for(int j = 0; j < 10; j++)
                                {
                                    printf("%c  ", westeros[i][j]);
                                }
                                printf("\n");
                            }
                        
                            char ganha_tempo;
                            printf("\nVoce se encontrou com Cersei, negocie com ele\npara convence-lo a participar da batalha contra o\nRei da Noite.");
                            printf("Digite 's' para iniciar\n> ");
                            scanf("%c", &ganha_tempo);
                            getchar();
                            int dado1, dado2, cont_n = 0, tentativas = 0;
                            do
                            {
                                printf("\nNegociacao - Caso voce tire mais de 60/100 3 vezes, sua negociacao tera sucesso,\ncaso contrario, vera as consequencias...");
                                printf("\nJoguemos os dados...");

                                dado1 = 1 + rand() % 6;
                                dado2 = 1 + rand() % 6;

                                float p_de_negociacao = (float)(dado1+dado2) / 12; 
                                if(p_de_negociacao > 0.6)
                                {
                                    cont_n++;
                                }
                                tentativas++;
                                printf("\nNegociacao: %i/3\nTenteativas: %i\nResultado:\nDado 1: %i\nDado 2: %i\nPoder de negociacao: %.1f",cont_n, tentativas, dado1, dado2, p_de_negociacao * 100);
                                printf("\nDigite 's' para ir para a proxima rodada\n> ");
                                scanf("%c", &ganha_tempo);
                                getchar();
                            }while(tentativas <= 4);


                            if(cont_n >= 3)//Negociacao sucesso
                            {
                                system("cls");
                                printf("\nSua negociacao foi um sucesso!\nVoce ganhou mais 100 pontos de vida!");
                                vida_j += 100;
                                westeros[4][4] = '_';
                                printf("\nDigite 's' para voltar ao tabuleiro\n> ");
                                scanf("%c", &ganha_tempo);
                                
                            }
                            else    //Negociacao fracasso
                            {
                                system("cls");
                                int turnos = 1;
                                int dado_ataque1, dado_ataque2;
                                float ataque;
                                int vida_c = 100;
                                printf("\nSua negociacao falhou...\nVoce entrou em guerra com Cersei");
                                printf("\nAlcance mais de 50/100 no dado para atacar Ceresei,\nporem o mesmo vale para Cersei lhe atacar!");
                                printf("Sua vida: %i\nVida inicial de Cersei: 100", vida_j);

                                do
                                {
                                    if(turnos == 1)// John Snow
                                    {   
                                        printf("\n\n***JOHN SNOW***");
                                        printf("\njoguem os dados...");
                                        
                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_c -= 10;
                                            printf("\nVoce atacou Cersei! <--");
                                        }
                                        else
                                        {
                                            printf("\nSeu ataque falhou <--");
                                        }

                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 0;
                                    }
                                    else    // Ceresei
                                    {
                                        printf("\n\n***CERSEI***");
                                        printf("\njoguem os dados...");
                                        

                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_j -= 10;
                                            printf("\nCersei lhe atacou! <--");
                                        }
                                        else
                                        {
                                            printf("\nO ataque de Cersei falhou <--");
                                        }


                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 1;
                                    }

                                    if(vida_j <= 0)
                                    {
                                        system("cls");
                                        printf("\nCersei matou voce...");
                                        printf("\nFIM DE JOGO");
                                        morreu = 1;
                                        printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                        scanf("%i", &jogar_novamente);
                                    }
                                    else if(vida_c <= 0)
                                    {
                                        system("cls");
                                        printf("\nVoce matou Cersei!");
                                        westeros[4][4] = '_';
                                        printf("\nDigite 's' para voltar a westeros\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        break;
                                    }
                                }while(vida_j > 0);
                            }
                        }
                    }
                break;
                case 's':
                    if(l_j + 1 < 10 && westeros[l_j + 1][c_j] != 'x')
                    {
                        if(westeros[l_j + 1][c_j] == 'i')
                        {
                            vida_j--;
                        }
                        if(westeros[l_j + 1][c_j] == 'o')
                        {
                            if(vida_j <= 95)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 95 && vida_j <= 100)
                            {
                                vida_j = 100;
                            }
                            else if(vida_j <= 195 && vida_j > 100)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 195)
                            {
                                vida_j = 200;
                            }
                        }
                        westeros[l_j][c_j] = '_';
                        westeros[l_j + 1][c_j] = 'J';
                        l_j++;// POSICAO ATUALIZADA

                        if(westeros[l_j - 1][c_j] == 'C' || westeros[l_j][c_j - 1] == 'C' || westeros[l_j + 1][c_j] == 'C' || westeros[l_j][c_j + 1] == 'C') // NEGOCIACAO COM CERESEI
                        {
                            system("cls");

                            for(int i = 0; i < 10; i++)
                            {
                                for(int j = 0; j < 10; j++)
                                {
                                    printf("%c  ", westeros[i][j]);
                                }
                                printf("\n");
                            }
                        
                            char ganha_tempo;
                            printf("\nVoce se encontrou com Cersei, negocie com ele\npara convence-lo a participar da batalha contra o\nRei da Noite.");
                            printf("Digite 's' para iniciar\n> ");
                            scanf("%c", &ganha_tempo);
                            getchar();
                            int dado1, dado2, cont_n = 0, tentativas = 0;
                            do
                            {
                                printf("\nNegociacao - Caso voce tire mais de 60/100 3 vezes, sua negociacao tera sucesso,\ncaso contrario, vera as consequencias...");
                                printf("\nJoguemos os dados...");

                                dado1 = 1 + rand() % 6;
                                dado2 = 1 + rand() % 6;

                                float p_de_negociacao = (float)(dado1+dado2) / 12; 
                                if(p_de_negociacao > 0.6)
                                {
                                    cont_n++;
                                }
                                tentativas++;
                                printf("\nNegociacao: %i/3\nTenteativas: %i\nResultado:\nDado 1: %i\nDado 2: %i\nPoder de negociacao: %.1f",cont_n, tentativas, dado1, dado2, p_de_negociacao * 100);
                                printf("\nDigite 's' para ir para a proxima rodada\n> ");
                                scanf("%c", &ganha_tempo);
                                getchar();
                            }while(tentativas <= 4);


                            if(cont_n >= 3)//Negociacao sucesso
                            {
                                system("cls");
                                printf("\nSua negociacao foi um sucesso!\nVoce ganhou mais 100 pontos de vida!");
                                vida_j += 100;
                                westeros[4][4] = '_';
                                printf("\nDigite 's' para voltar ao tabuleiro\n> ");
                                scanf("%c", &ganha_tempo);
                                
                            }
                            else    //Negociacao fracasso
                            {
                                system("cls");
                                int turnos = 1;
                                int dado_ataque1, dado_ataque2;
                                float ataque;
                                int vida_c = 100;
                                printf("\nSua negociacao falhou...\nVoce entrou em guerra com Cersei");
                                printf("\nAlcance mais de 50/100 no dado para atacar Ceresei,\nporem o mesmo vale para Cersei lhe atacar!");
                                printf("Sua vida: %i\nVida inicial de Cersei: 100", vida_j);

                                do
                                {
                                    if(turnos == 1)// John Snow
                                    {   
                                        printf("\n\n***JOHN SNOW***");
                                        printf("\njoguem os dados...");
                                        
                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_c -= 10;
                                            printf("\nVoce atacou Cersei! <--");
                                        }
                                        else
                                        {
                                            printf("\nSeu ataque falhou <--");
                                        }

                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 0;
                                    }
                                    else    // Ceresei
                                    {
                                        printf("\n\n***CERSEI***");
                                        printf("\njoguem os dados...");
                                        

                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_j -= 10;
                                            printf("\nCersei lhe atacou! <--");
                                        }
                                        else
                                        {
                                            printf("\nO ataque de Cersei falhou <--");
                                        }


                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 1;
                                    }

                                    if(vida_j <= 0)
                                    {
                                        system("cls");
                                        printf("\nCersei matou voce...");
                                        printf("\nFIM DE JOGO");
                                        morreu = 1;
                                        printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                        scanf("%i", &jogar_novamente);
                                    }
                                    else if(vida_c <= 0)
                                    {
                                        system("cls");
                                        printf("\nVoce matou Cersei!");
                                        westeros[4][4] = '_';
                                        printf("\nDigite 's' para voltar a westeros\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        break;
                                    }
                                }while(vida_j > 0);
                            }
                        }

                        if(westeros[l_j - 1][c_j] == 'N' || westeros[l_j][c_j - 1] == 'N' || westeros[l_j + 1][c_j] == 'N' || westeros[l_j][c_j + 1] == 'N')
                        {
                            system("cls");

                            int turnos;
                            int dado_ataque1, dado_ataque2;
                            float ataque;
                            int vida_rn = 200;
                            int tem_c;
                            int decisao;
                            
                            for(int i = 0; i < 10; i++)
                            {
                                for(int j = 0; j < 10; j++)
                                {
                                    printf("%c  ", westeros[i][j]);
                                    if(westeros[i][j] == 'C')
                                    {
                                        tem_c = 1;
                                    }
                                }
                                printf("\n");
                            }

                            if(tem_c == 1)
                            {
                                printf("\nVoce tem certeza que quer enfrentar o Rei da Noite sem falar com Cersei?\n1 - Sim\n2 - Nao\n> ");
                                scanf("%i", &decisao);
                                if(decisao == 2)
                                {
                                    break;
                                }
                            }

                            printf("\nVoce encontrou o Rei da Noite...\nSe prepare pelo que ha por vir...");
                            
                            printf("\nCaso voce acerte seu ataque voce causa 10 de dano no Rei da Noite\nCaso o Rei da noite lhe acerte,\n ele dara 5 de dano, porem recuperara 5 de vida.");
                            printf("\nVida inicial de John Snow: %i\nVida inicial Rei da Noite: 200", vida_j);
                            do
                            {
                                if(turnos == 1)// John Snow
                                {   
                                    printf("\n\n***JOHN SNOW***");
                                    printf("\njoguem os dados...");
                                    
                                    dado_ataque1 = 1 + rand() % 6;
                                    dado_ataque2 = 1 + rand() % 6;

                                    ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                    if(ataque >= 0.5)
                                    {
                                        vida_rn -= 10;
                                        printf("\nVoce atacou o Rei da Noite! <--");
                                    }
                                    else
                                    {
                                        printf("\nSeu ataque falhou <--");
                                    }

                                    printf("\nVida John Snow: %i", vida_j);
                                    printf("\nVida Rei da Noite: %i", vida_rn);

                                    printf("\nDigite 's' para passar o turno\n> ");
                                    scanf("%c", &ganha_tempo);
                                    getchar();
                                    turnos = 0;
                                }
                                else    // Rei da Noite
                                {
                                    printf("\n\n***REI DA NOITE***");
                                    printf("\njoguem os dados...");
                                    

                                    dado_ataque1 = 1 + rand() % 6;
                                    dado_ataque2 = 1 + rand() % 6;

                                    ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                    if(ataque >= 0.5)
                                    {
                                        vida_j -= 5;
                                        if(vida_rn <= 195)
                                        {
                                            vida_rn += 5;
                                        }
                                        else
                                        {
                                            vida_rn = 200;
                                        }
                                        
                                        printf("\nO Rei da Noite lhe atacou! <--");
                                    }
                                    else
                                    {
                                        printf("\nO ataque do Rei da Noite falhou <--");
                                    }


                                    printf("\nVida John Snow: %i", vida_j);
                                    printf("\nVida Rei da Noite: %i", vida_rn);

                                    printf("\nDigite 's' para passar o turno\n> ");
                                    scanf("%c", &ganha_tempo);
                                    getchar();
                                    turnos = 1;
                                }

                                if(vida_j <= 0)
                                {
                                    system("cls");
                                    printf("\nO Rei da Noite matou voce...");
                                    printf("\nFIM DE JOGO");
                                    morreu = 1;
                                    printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                    scanf("%i", &jogar_novamente);
                                    break;
                                }
                                else if(vida_rn <= 0)
                                {
                                    system("cls");
                                    printf("\nVoce matou o Rei da Noite!"); // Jogo acaba pois Rei da noite morreu
                                    printf("\nParabens, voce ganhou o jogo!!");
                                    printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                    scanf("%i", &jogar_novamente);
                                    westeros[9][9] = '_';
                                    morreu = 1;
                                }
                            }while(1);
                        }
                    }
                break;
                case 'd':
                    if(c_j + 1 < 10 && westeros[l_j][c_j + 1] != 'x')
                    {
                        if(westeros[l_j][c_j + 1] == 'i')
                        {
                            vida_j--;
                        }
                        if(westeros[l_j][c_j + 1] == 'o')
                        {
                            if(vida_j <= 95)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 95 && vida_j <= 100)
                            {
                                vida_j = 100;
                            }
                            else if(vida_j <= 195 && vida_j > 100)
                            {
                                vida_j += 5;
                            }
                            else if(vida_j > 195)
                            {
                                vida_j = 200;
                            }
                        }
                        westeros[l_j][c_j] = '_';
                        westeros[l_j][c_j + 1] = 'J';
                        c_j++;// POSICAO ATUALIZADA

                        if(westeros[l_j - 1][c_j] == 'C' || westeros[l_j][c_j - 1] == 'C' || westeros[l_j + 1][c_j] == 'C' || westeros[l_j][c_j + 1] == 'C') // NEGOCIACAO COM CERESEI
                        {
                            system("cls");

                            for(int i = 0; i < 10; i++)
                            {
                                for(int j = 0; j < 10; j++)
                                {
                                    printf("%c  ", westeros[i][j]);
                                }
                                printf("\n");
                            }
                        
                            char ganha_tempo;
                            printf("\nVoce se encontrou com Cersei, negocie com ele\npara convence-lo a participar da batalha contra o\nRei da Noite.");
                            printf("Digite 's' para iniciar\n> ");
                            scanf("%c", &ganha_tempo);
                            getchar();
                            int dado1, dado2, cont_n = 0, tentativas = 0;
                            do
                            {
                                printf("\nNegociacao - Caso voce tire mais de 60/100 3 vezes, sua negociacao tera sucesso,\ncaso contrario, vera as consequencias...");
                                printf("\nJoguemos os dados...");

                                dado1 = 1 + rand() % 6;
                                dado2 = 1 + rand() % 6;

                                float p_de_negociacao = (float)(dado1+dado2) / 12; 
                                if(p_de_negociacao > 0.6)
                                {
                                    cont_n++;
                                }
                                tentativas++;
                                printf("\nNegociacao: %i/3\nTenteativas: %i\nResultado:\nDado 1: %i\nDado 2: %i\nPoder de negociacao: %.1f",cont_n, tentativas, dado1, dado2, p_de_negociacao * 100);
                                printf("\nDigite 's' para ir para a proxima rodada\n> ");
                                scanf("%c", &ganha_tempo);
                                getchar();
                            }while(tentativas <= 4);


                            if(cont_n >= 3)//Negociacao sucesso
                            {
                                system("cls");
                                printf("\nSua negociacao foi um sucesso!\nVoce ganhou mais 100 pontos de vida!");
                                vida_j += 100;
                                westeros[4][4] = '_';
                                printf("\nDigite 's' para voltar ao tabuleiro\n> ");
                                scanf("%c", &ganha_tempo);
                                
                            }
                            else    //Negociacao fracasso
                            {
                                system("cls");
                                int turnos = 1;
                                int dado_ataque1, dado_ataque2;
                                float ataque;
                                int vida_c = 100;
                                printf("\nSua negociacao falhou...\nVoce entrou em guerra com Cersei");
                                printf("\nAlcance mais de 50/100 no dado para atacar Ceresei,\nporem o mesmo vale para Cersei lhe atacar!");
                                printf("Sua vida: %i\nVida inicial de Cersei: 100", vida_j);

                                do
                                {
                                    if(turnos == 1)// John Snow
                                    {   
                                        printf("\n\n***JOHN SNOW***");
                                        printf("\njoguem os dados...");
                                        
                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_c -= 10;
                                            printf("\nVoce atacou Cersei! <--");
                                        }
                                        else
                                        {
                                            printf("\nSeu ataque falhou <--");
                                        }

                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 0;
                                    }
                                    else    // Ceresei
                                    {
                                        printf("\n\n***CERSEI***");
                                        printf("\njoguem os dados...");
                                        

                                        dado_ataque1 = 1 + rand() % 6;
                                        dado_ataque2 = 1 + rand() % 6;

                                        ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                        if(ataque >= 0.5)
                                        {
                                            vida_j -= 10;
                                            printf("\nCersei lhe atacou! <--");
                                        }
                                        else
                                        {
                                            printf("\nO ataque de Cersei falhou <--");
                                        }


                                        printf("\nVida John Snow: %i", vida_j);
                                        printf("\nVida Cersei: %i", vida_c);

                                        printf("\nDigite 's' para passar o turno\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        turnos = 1;
                                    }

                                    if(vida_j <= 0)
                                    {
                                        system("cls");
                                        printf("\nCersei matou voce...");
                                        printf("\nFIM DE JOGO");
                                        morreu = 1;
                                        printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                        scanf("%i", &jogar_novamente);
                                        
                                    }
                                    else if(vida_c <= 0)
                                    {
                                        system("cls");
                                        printf("\nVoce matou Cersei!");
                                        westeros[4][4] = '_';
                                        printf("\nDigite 's' para voltar a westeros\n> ");
                                        scanf("%c", &ganha_tempo);
                                        getchar();
                                        break;
                                    }
                                }while(vida_j > 0);
                            }
                        }

                        if(westeros[l_j - 1][c_j] == 'N' || westeros[l_j][c_j - 1] == 'N' || westeros[l_j + 1][c_j] == 'N' || westeros[l_j][c_j + 1] == 'N')
                        {
                            system("cls");

                            int turnos;
                            int dado_ataque1, dado_ataque2;
                            float ataque;
                            int vida_rn = 200;
                            int tem_c;
                            int decisao;
                            
                            for(int i = 0; i < 10; i++)
                            {
                                for(int j = 0; j < 10; j++)
                                {
                                    printf("%c  ", westeros[i][j]);
                                    tem_c = 1;
                                }
                                printf("\n");
                            }

                            if(tem_c == 1)
                            {
                                printf("\nVoce tem certeza que quer enfrentar o Rei da Noite sem falar com Cersei?\n1 - Sim\n2 - Nao\n> ");
                                scanf("%i", &decisao);
                                if(decisao == 2)
                                {
                                    break;
                                }
                            }

                            printf("Voce encontrou o Rei da Noite...\nSe prepare pelo que ha por vir...");
                            
                            printf("\nCaso voce acerte seu ataque voce causa 10 de dano no Rei da Noite\nCaso o Rei da noite lhe acerte,\n ele dara 5 de dano, porem recuperara 5 de vida.");
                            printf("\nVida inicial de John Snow: %i\nVida inicial Rei da Noite: 200", vida_j);
                            do
                            {
                                if(turnos == 1)// John Snow
                                {   
                                    printf("\n\n***JOHN SNOW***");
                                    printf("\njoguem os dados...");
                                    
                                    dado_ataque1 = 1 + rand() % 6;
                                    dado_ataque2 = 1 + rand() % 6;

                                    ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                    if(ataque >= 0.5)
                                    {
                                        vida_rn -= 10;
                                        printf("\nVoce atacou o Rei da Noite! <--");
                                    }
                                    else
                                    {
                                        printf("\nSeu ataque falhou <--");
                                    }

                                    printf("\nVida John Snow: %i", vida_j);
                                    printf("\nVida Rei da Noite: %i", vida_rn);

                                    printf("\nDigite 's' para passar o turno\n> ");
                                    scanf("%c", &ganha_tempo);
                                    getchar();
                                    turnos = 0;
                                }
                                else    // Rei da Noite
                                {
                                    printf("\n\n***REI DA NOITE***");
                                    printf("\njoguem os dados...");
                                    

                                    dado_ataque1 = 1 + rand() % 6;
                                    dado_ataque2 = 1 + rand() % 6;

                                    ataque = (float)(dado_ataque1 + dado_ataque2) / 12;
                                    if(ataque >= 0.5)
                                    {
                                        vida_j -= 5;
                                        if(vida_rn <= 195)
                                        {
                                            vida_rn += 5;
                                        }
                                        else
                                        {
                                            vida_rn = 200;
                                        }
                                        
                                        printf("\nO Rei da Noite lhe atacou! <--");
                                    }
                                    else
                                    {
                                        printf("\nO ataque do Rei da Noite falhou <--");
                                    }


                                    printf("\nVida John Snow: %i", vida_j);
                                    printf("\nVida Rei da Noite: %i", vida_rn);

                                    printf("\nDigite 's' para passar o turno\n> ");
                                    scanf("%c", &ganha_tempo);
                                    getchar();
                                    turnos = 1;
                                }

                                if(vida_j <= 0)
                                {
                                    system("cls");
                                    printf("\nO Rei da Noite matou voce...");
                                    printf("\nFIM DE JOGO");
                                    morreu = 1;
                                    printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                    scanf("%i", &jogar_novamente);
                                    break;
                                }
                                else if(vida_rn <= 0)
                                {
                                    system("cls");
                                    printf("\nVoce matou o Rei da Noite!"); // Jogo acaba pois Rei da noite morreu
                                    printf("\nParabens, voce ganhou o jogo!!");
                                    printf("\nVoce deseja jogar novamente?\n1 - Sim\n2 - Nao\n> ");
                                    scanf("%i", &jogar_novamente);
                                    westeros[9][9] = '_';
                                    break;
                                    
                                }
                            }while(vida_j > 0);
                        }
                    }
                break;
                default:;
            }
        
            system("cls");
        }while(morreu != 1);
    }while(jogar_novamente == 1);
}
