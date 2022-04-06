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
    int i=0, j=0;
    m->soma = m->M[0][0];
    m->M[0][0] = -1;

    while (i < N && j < N)
    {
        if(j == 0 && i < (N-1)){
            if((m->M[i][j+1] >= m->M[i+1][j]) && (m->M[i][j+1] != -1)){
                j++;
                m->soma += m->M[i][j];
                m->M[i][j] = -1;
            }else{
                i++;
                m->soma += m->M[i][j];
                m->M[i][j] = -1;
            }
        }else if(i == (N-1)){
            j++;
            m->soma += m->M[i][j];
            m->M[i][j] = -1;
        }else if(j == N-1){
            if((m->M[i][j-1] >= m->M[i+1][j]) && (m->M[i][j-1] != -1)){
                j--;
                m->soma += m->M[i][j];
                m->M[i][j] = -1;
            }else{
                i++;
                m->soma += m->M[i][j];
                m->M[i][j] = -1;
            }
        }else{
            if(m->M[i][j+1] == -1){
                if(m->M[i+1][j] >= m->M[i][j-1]){
                    i++;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
                }else{
                    j--;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
                }
            }else if(m->M[i][j-1] == -1){
                if(m->M[i+1][j] >= m->M[i][j+1]){
                    i++;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
                }else{
                    j++;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
                }
            }else{
                if((m->M[i+1][j] >=  m->M[i][j+1]) && (m->M[i+1][j] >= m->M[i][j-1])){
                    i++;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
                }else if((m->M[i][j+1] >= m->M[i+1][j]) && (m->M[i][j+1] >= m->M[i][j-1])){
                    j++;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
                }else if((m->M[i][j-1] >= m->M[i+1][j]) && (m->M[i][j-1] >= m->M[i][j+1])){
                    j--;
                    m->soma += m->M[i][j];
                    m->M[i][j] = -1;
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