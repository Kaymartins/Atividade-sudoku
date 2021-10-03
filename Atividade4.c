/* UNIVERSIDADE FEDERAL DE ALFENAS 
    BACHARELADO EM CIENCIA DA COMPUTAÇÃO
TRABALHO : ATIVIDADE 4; 
DISCIPLINA: PROGRAMACAO; 
PROFESSOR: LUIZ EDUARDO DA SILVA; 
ALUNO: KAYAN MARTINS DE FREITAS; 
DATA: 26/08/2021
*/


#include <stdio.h>

void leSudoku(int n, int sudoku[16][16]){
    char s[2];
    int i, j, dim = n * n;
    for (i=0; i<dim; i++)
        for( j = 0; j<dim; j++){
            scanf("%s",s);
            if (s[0] >= '1' && s[0] <= '9') 
                sudoku[i][j] = s[0] - '0';
            if (s[0] >= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;
        }   
}

void imprimeLinha(int n){
    int i,j;
    for(i=0; i<n; i++){
        printf("+");
        for(j=0; j<n; j++)
            printf("---");
    }
    printf("+\n");
}

void imprimeSudoku(int n, int sudoku[16][16]){
    int i,j,dim=n*n;
    imprimeLinha(n);
    for (i=0; i<dim; i++){
        printf("|");
        for(j=0; j<dim; j++){
            int num = sudoku[i][j];
            if (num <=9)
                printf("%2d",num);
            else
                printf("%2c", num - 10 + 'A');
            if ((j+1) % n == 0)
                printf("|");
        }
        printf("\n");
        if((i+1) % n == 0)
            imprimeLinha(n);
    }
}
/*Função que armazena cada bloco do Sudoku em uma matriz [BLOCO][VALORES] */
void armazenaBloco(int n, int sudoku[16][16], int auxiliar[16][16]){
    int x, y, z=0, dim=n*n, bloco=0, a=0, b=0, c=0;

   /*PRIMEIRA LINHA DE BLOCOS*/
   for (x=0; x<n; x++){
       //primeiro bloco
       for (y=0; y<n; y++) {
           bloco = 0;
           auxiliar[bloco][z] = sudoku[x][y];
           z++;
       }
       //segundo bloco
       for(y=n; y<2*n; y++){
           bloco = 1;
           auxiliar[bloco][a] = sudoku[x][y];
           a++;
       }
       //terceiro bloco
       if(n>2){
           for(y=2*n; y<3*n; y++){
                bloco = 2;
                auxiliar[bloco][b] = sudoku[x][y];
                b++;
           }
        }
        //quarto bloco
        if (n>3){
            for (y=3*n; y<dim; y++){
               bloco = 3;
               auxiliar[bloco][c] = sudoku[x][y];
               c++;
           }
        }
    }
    a=0;
    b=0;
    c=0;
    z=0;
    /*SEGUNDA LINHA DE BLOCOS*/
    for (x=n; x<2*n; x++){
        //primeiro bloco
       for (y=0; y<n; y++) {
           bloco = 4;
           auxiliar[bloco][z] = sudoku[x][y];
           z++;
       }
       //segundo bloco
       for(y=n; y<2*n; y++){
           bloco = 5;
           auxiliar[bloco][a] = sudoku[x][y];
           a++;
       }
       //terceiro bloco
       if(n>2){
           for(y=2*n; y<3*n; y++){
                bloco = 6;
                auxiliar[bloco][b] = sudoku[x][y];
                b++;
           }
        }
        //quarto bloco
        if (n>3){
            for (y=3*n; y<dim; y++){
               bloco = 7;
               auxiliar[bloco][c] = sudoku[x][y];
               c++;
           }
        }
    }
    a=0;
    b=0;
    c=0;
    z=0;
    /*TERCEIRA LINHA DE BLOCOS*/
    if(n>2){
        for(x=2*n; x<3*n; x++){
            //primeiro bloco
            for (y=0; y<n; y++) {
                bloco = 8;
                auxiliar[bloco][z] = sudoku[x][y];
                z++;
            }
            //segundo bloco
            for(y=n; y<2*n; y++){
                bloco = 9;
                auxiliar[bloco][a] = sudoku[x][y];
                a++;
            }
            //terceiro bloco
            if(n>2){
                for(y=2*n; y<3*n; y++){
                    bloco = 10;
                    auxiliar[bloco][b] = sudoku[x][y];
                    b++;
                }
            }
            //quarto bloco
            if (n>3){
                for (y=3*n; y<dim; y++){
                bloco = 11;
                auxiliar[bloco][c] = sudoku[x][y];
                c++;
                }
            }
        }
    }
    a=0;
    b=0;
    c=0;
    z=0;
    /*QUARTA LINHA DE BLOCOS*/
    if(n>3){
        for(x=3*n; x<dim; x++){
            //primeiro bloco
            for (y=0; y<n; y++) {
                bloco = 12;
                auxiliar[bloco][z] = sudoku[x][y];
                z++;
            }
            //segundo bloco
            for(y=n; y<2*n; y++){
                bloco = 13;
                auxiliar[bloco][a] = sudoku[x][y];
                a++;
            }
            //terceiro bloco
            if(n>2){
                for(y=2*n; y<3*n; y++){
                    bloco = 14;
                    auxiliar[bloco][b] = sudoku[x][y];
                    b++;
                }
            }
            //quarto bloco
            if (n>3){
                for (y=3*n; y<dim; y++){
                bloco = 15;
                auxiliar[bloco][c] = sudoku[x][y];
                c++;
                }
            }
        }
    }
}
/*----------------------------------------------------------------
*Funcao que testa uma solucao da Sudoku
*Parametros:
*   n = dimensao das regioes
*   sudoku - jogo preenchido 
*   lin- linha do erro(se houver)
*   col - coluna do erro (se houver)
*Retorna: 
*   1 se a matriz é uma solução do sudoku 
*   0 caso contrario, modificando os parametros
*     lin e col para indicar a linha e coluna onde foi detectado o problema
*--------------------------------------------------------------------*/

int sudokuOk(int n, int sudoku[16][16], int *lin, int *col){
    int i,j,k,ehBloco, dim = n * n,erro=0,auxiliar[16][16],cont;
    *lin = 1;
    *col = 1;

    /*verificação das linhas e colunas*/
    for (i=0; i<dim && erro==0; i++){
        for (j=0; j<dim && erro==0; j++){
            for (k=j+1; k<dim && erro==0; k++){ // VERIFICA TODOS NUMEROS DA LINHA
                if (sudoku[i][j] == sudoku[i][k]){
                    erro = 1;
                    *col = k+1;
                    *lin = i+1;
                }
            }
            for (k=i+1; k<dim && erro ==0 ; k++){  //VERIFICA TODOS OS NUMEROS DA COLUNA 
                if (sudoku[i][j] == sudoku[k][j]){
                    erro = 1;
                    *col = j+1;
                    *lin = k+1; 
                }
            }
        }  
    }
    
   /*Função armazenaBloco */ 
   armazenaBloco(n, sudoku, auxiliar);
   ehBloco = 0;
   if (erro == 0){
       cont=0;
        if(n>3){ 
            for (i=0; i<dim && erro==0; i++){
                for (j=0; j<dim && erro==0; j++){
                    for (k=j+1; k<dim && erro==0; k++){                   
                        if (auxiliar[i][j] == auxiliar[i][k]){
                            ehBloco = 1;
                            erro = 1;
                            *col = i+1; /*na verdade este valor está informando em qual bloco é o erro, ficou muito complicado
                                        apontar a linha e a coluna com esta lógica que implementei e não daria tempo de enviar 
                                        a atividade, aí para nao ficar sem nada resolvi apontar o bloco e a posição do bloco,
                                        que sao os parametros do vetor auxiliar*/
                            *lin = k+1;
                        }
                    }
                }
            }
        }else if (n>2){
            for (i=0; i<3 && erro==0; i++){
                for (j=0; j<dim && erro == 0; j++){
                    for (k=j+1; k<dim && erro == 0; k++){
                        if (auxiliar[i][j] == auxiliar[i][k]){
                            ehBloco = 1;
                            erro = 1; 
                            *col = i+1;
                            *lin = k+1;
                        }
                    }
                }
            }
            for (i=4; i<7 && erro==0; i++){
                for(j=0; j<dim && erro==0; j++){
                    for(k=j+1; k<dim && erro ==0; k++){
                        if (auxiliar[i][j] == auxiliar[i][k]){
                            ehBloco = 1;
                            erro = 1;
                            *lin = k+1;                         
                            *col = i;
                            
                        }
                    }
                }
            }
            for (i=8; i<11 && erro ==0; i++){
                for (j=0; j<dim && erro==0; j++){
                    for(k=j+1; k<dim && erro ==0; k++){
                        if (auxiliar[i][j] == auxiliar[i][k]){
                            ehBloco = 1;
                            erro = 1;
                            *col = i-1;
                            *lin = k+1;
                        }
                    }
                }

            }
        }else{
            for (i=0; i<2 && erro==0; i++){
                for (j=0; j<dim && erro == 0; j++){
                    for (k=j+1; k<dim && erro == 0; k++){
                        if (auxiliar[i][j] == auxiliar[i][k]){
                            ehBloco = 1;
                            erro = 1; 
                            *col = i+1;
                            *lin = k+1;
                        }
                    }
                }
            }
            for (i=4; i<6 && erro==0; i++){
                for (j=0; j<dim && erro == 0; j++){
                    for (k=j+1; k<dim && erro == 0; k++){
                        if (auxiliar[i][j] == auxiliar[i][k]){
                            ehBloco = 1;
                            erro = 1;
                            if (i==4){ 
                                *col = 3;
                            }else{
                                *col = 4;
                            }
                            *lin = k+1;
                        }
                    }
                }
            }

        }
    }
    if (erro==0){
        return 1;
    }else{
        if(ehBloco == 1){
            printf("Erro em Bloco / ");
        }
        return 0;
    }
    
}

int main(void){
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d",&n);
    leSudoku(n, sudoku);
    imprimeSudoku(n, sudoku);
    ok = sudokuOk(n, sudoku, &nlin, &ncol);
    if (ok) 
        puts("Sudoku Ok !");
    else
        printf("Erro na posição (%d,%d)\n", nlin, ncol);
    return 0;

}
