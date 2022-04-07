#include "matriz.h"

void IniciaM(Matriz *m){
    srand((unsigned)time(NULL));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m->M[i][j] = rand() % 99;
        }
    }
}

void PercorrerM(Matriz *m){
    int i=0, j=0, x=0;
    m->soma = m->M[0][0];
    m->vetor[x] = m->M[i][j];
    x++;
    m->M[0][0] = -1;

    while (i < N && j < N)
    {
        if(j == 0 && i < (N-1)){ //primeira coluna
            if((m->M[i][j+1] >= m->M[i+1][j]) && (m->M[i][j+1] != -1)){ //direita maior igual embaixo ou diferente -1
                j++;
                m->soma += m->M[i][j];
                m->vetor[x] = m->M[i][j];
                m->M[i][j] = -1;
                x++;
            }else{
                i++;
                m->soma += m->M[i][j];
                m->vetor[x] = m->M[i][j];
                m->M[i][j] = -1;
                x++;
            }
        }else if(i == (N-1)){ //ultima linha
            j++;
            m->soma += m->M[i][j];
            m->vetor[x] = m->M[i][j];
            m->M[i][j] = -1;
            x++;
        }else if(j == N-1){ //ultima coluna
            if((m->M[i][j-1] >= m->M[i+1][j]) && (m->M[i][j-1] != -1)){ //esquerda maior igual embaixo ou diferente -1
                j--;
                m->soma += m->M[i][j];
                m->vetor[x] = m->M[i][j];
                m->M[i][j] = -1;
                x++;
            }else{
                i++;
                m->soma += m->M[i][j];
                m->vetor[x] = m->M[i][j];
                m->M[i][j] = -1;
                x++;
            }
        }else{ //demais posicoes
            if(m->M[i][j+1] == -1){ //direita diferente -1
                if(m->M[i+1][j] >= m->M[i][j-1]){ // embaixo maior igual esquerda
                    i++;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }else{
                    j--;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }
            }else if(m->M[i][j-1] == -1){ //esquerda diferente -1
                if(m->M[i+1][j] >= m->M[i][j+1]){ //embaixo maior igual direita
                    i++;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }else{
                    j++;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }
            }else{
                if((m->M[i+1][j] >=  m->M[i][j+1]) && (m->M[i+1][j] >= m->M[i][j-1])){ //embaixo >= direita && embaixo >= esquerda
                    i++;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }else if((m->M[i][j+1] >= m->M[i+1][j]) && (m->M[i][j+1] >= m->M[i][j-1])){ //direita >= embaixo && direita >= esquerda
                    j++;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }else if((m->M[i][j-1] >= m->M[i+1][j]) && (m->M[i][j-1] >= m->M[i][j+1])){ //esquerda >= embaixo && esquerda >= direita
                    j--;
                    m->soma += m->M[i][j];
                    m->vetor[x] = m->M[i][j];
                    m->M[i][j] = -1;
                    x++;
                }
            }
        }
    }
}

void PrintaM(Matriz *m){
    printf("MATRIZ:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            printf("%5d", m->M[i][j]);
        }
        printf("\n");
    }

}
    
void Caminho(Matriz *m){
    char str[80][N][N];

    printf("CAMINHO:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(m->M[i][j] == -1){
                sprintf(str[i][j], "%c", 'X'); 
            }else
            sprintf(str[i][j], "%d", m->M[i][j]);
        }
    }

    
    for(int i=0;i<N;i++){ 
        for(int j=0;j<N;j++){
            printf("%5s", str[i][j]);
        }
        printf("\n");
    }
    
}

void ValoresCaminho(Matriz *m){
    int vetinv[N*N];
    int sc;
    int s=0;
    while(s != -1){
        printf("------CAMINHO------\n");
        printf("1. Valores do caminho\n");
        printf("2. Valores do caminho inverso\n");
        printf("3. Sair\n");
        printf("R: ");
        scanf("%d", &sc);
        switch (sc){
            case 1:
                printf("VALORES DO CAMINHO:\n");
                for(int i=0;i<N*N;i++){
                    if(m->vetor[i] != 0)
                        printf(" %d ", m->vetor[i]);
                }
                printf("\n\n");
                break;
            case 2:
                printf("VALORES REVERSOS:\n");
                for(int i = 0; i < N*N; i++) {
                    vetinv[i] = m->vetor[N*N-i-1];
                    if(vetinv[i] != 0)
                        printf(" %d ", vetinv[i]);
                }
                printf("\n\n");
                break;
            case 3:
                printf("Saindo...\n\n");
                s = -1;
                break;
            default:
                printf("OPCAO INCORRETA\n\n");
                break;
            }
    }
}