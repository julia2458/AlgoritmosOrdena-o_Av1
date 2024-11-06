#include <stdio.h>

//função para algoritmo de ordenação bublle sort
void bubble_sort (int* vetor, int tam){
    
    //declaração de variáveis
    int i, aux; /*i e j são os indices utilizados no for - aux é a variável que vai auxiliar na troca de posições*/
    int troca = 1; //servirá para informar se houve trocas de posições 

    while(troca == 1){ /*enquanto o valor de troca for maior que zero significa que o vetor está desordenado*/
        troca = 0; //altera o valor de troca, pois se não houver alteração de posição significa que o vetor está ordenado
        
        for (i = 0; i < tam - 1; i++){ /*for para a compararação entra a posição i com a posição j percorrer todo o vetor*/
        
            if(vetor[i] > vetor[i + 1]){ /*Verifica se o valor da posição i é maior que o valor da posição i + 1*/
                aux = vetor[i]; //aux recebe i
                vetor[i] = vetor[i + 1]; /*posição i recebe valor da posição i + 1*/
                vetor[i + 1] = aux; /*posição i +1 recebe valor da posição i*/
                troca = 1; //modifica o troca pois houve alteração de posição
            }
            
        }
        
        tam--; //desincrementa n para que ele verifique sempre uma antes da ultima modificação
    
    }
}

//função para algoritmo de ordenação selection sort
void selection_sort(int *vetor, int tam){
    
    //declaração de variaáveis
    int i, j, aux, menor; //i e j será utilizado no for - aux será utilizado para armazenar os valores no momento de troca - menor guardará o menor valor do vetor
    
    for(i = 0; i < tam; i++){ //repetição que percorrerá o vetor do inicio ao fim, ela mostrará onde fica o inicio do vetor
        
        menor = i; //menor recebe o indice do elemento analisado
        
        for(j = i + 1; j < tam; j++){//busca um elemento menor do que o elemento atual 
        
            if(vetor[j] < vetor[menor]){ //verifica se o elemento na posiçao j é menor que o elemento da posição menor
                menor = j; //menor recebe o indice de do menor elemento
            }
            
        } 
        
        //trocas de posição
        aux = vetor[i]; //aux recebe elemento armazenado na posição i
        vetor[i] = vetor[menor]; //salva o primeiro elemento na posição analisada
        vetor[menor] = aux; //recebe o elemento que pertencia a i
     
    }
}

//função para algoritmo de ordenação insertion sort 
void insertion_sort(int *vetor, int tam){ 
    
    //declaração de variável
    int i, j, aux; //i e j são os indices utilizados no for - aux é a variável que vai auxiliar na troca de posições
    
    for(i = 1; i < tam; i++){ //percorre o vetor a partit da posição 1 até o final para selecionar os elementos de "principais" de troca
        
        aux = vetor[i]; //auxiliar armazena o número que está sendo comparado
        j = i - 1; //j será sempre percorrerá as posições antecendentes de 1
        
        while( (j >= 0) && (aux < vetor[j])){//while para realizar as trocas enquanto o número do aux for menor que o da posição j
            vetor[j + 1] = vetor[j]; // j+1 recebe o vetor que está na posição j 
            j--;
        }
        
        vetor[j + 1] = aux;
    }
}

//função para algoritmo de ordenação merge sort 
void merge_sort(int *vetor, int tam){
    
}

//função para imprimir vetor ordenado
void imprimir(int* vetor, int tam){
    
    //declaração de variável
    int i; //indice utilizado no for
    
    for(i = 0; i < tam; i++){
        printf(" - %d", vetor[i]);
    }
    
}

int main()
{
    
    //declaração de variáveis e vetores
    int vetor[] = {5, 64, 34, 7, 25, 12, 22, 11, 90, 21}; //vetor que será ordenado
    int tam = 10;
    
    //imprimindo vetor desordenado
    printf("\nVETOR DESORDENADO:\n");
    imprimir(vetor, tam);
    
    //ordenando vetor
    insertion_sort(vetor, tam);
    
    //imprimindo vetor ordenado
    printf("\nVETOR ORDENADO:\n");
    imprimir(vetor, tam);
    

    return 0;
}