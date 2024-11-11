/*TIME 4:
ISABELLY LETÍCIA HORSCHUTZ
JÚLIA DAMÁRIA LUPI - 24002058
MAYSA GABRIELLE RODRIGUES DE MELO - 24009119
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
        
        while((j >= 0) && (aux < vetor[j])){//while para realizar as trocas enquanto o número do aux for menor que o da posição j
            vetor[j + 1] = vetor[j]; // j+1 recebe o vetor que está na posição j 
            j--;
        }
        
        vetor[j + 1] = aux;
    }
}

// Função que combina duas partes ordenadas do vetor em uma única parte ordenada
void merge(int *vetor, int inicio, int meio, int fim){
    int *temp, a1, a2, tam, i, j, k; 
    int fim1 = 0, fim2 = 0; // variaveis para controlar o fim de cada subvetor
    
    tam = fim - inicio + 1; // Calcula o tamanho do vetor temporário
    a1 = inicio; // Índice inicial da primeira metade
    a2 = meio + 1; // Índice inicial da segunda metade
    
    // Aloca memória para o vetor temporário
    temp = (int *) malloc(tam * sizeof(int));
    
    if(temp != NULL){ // Verifica a alocação 
        for(i = 0; i < tam; i++){
            // Verifica se já chegou ao fim da primeira metade
            if(a1 > meio)
                fim1 = 1;
            // Verifica se já chegou ao fim da segunda metade
            if(a2 > fim)
                fim2 = 1;
                
            if(!fim1 && !fim2){ // Se ainda existe elementos nas metades
                if(vetor[a1] < vetor[a2]) // Compara os elementos das duas metades
                    temp[i] = vetor[a1++]; // Copia o menor elemento
                else
                    temp[i] = vetor[a2++];
            }else{ // Se uma das metades já acabou
                if(!fim1) // Se ainda existe elementos na primeira metade
                    temp[i] = vetor[a1++];
                else // Se ainda existe elementos na segunda metade
                    temp[i] = vetor[a2++];
            }
        }
        
        // Copia os elementos ordenados do vetor temporário para o vetor original
        for(j = 0, k = inicio; j < tam; j++, k++){
            vetor[k] = temp[j];
        }
        
        free(temp); // Libera a memória alocada para o vetor temporário
    }
}

// Função que implementa o merge sort
void merge_sort(int *vetor, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2; // Calcula o ponto médio do vetor
        merge_sort(vetor, inicio, meio); // Ordena a primeira metade do vetor
        merge_sort(vetor, meio + 1, fim); // Ordena a segunda metade do vetor
        merge(vetor, inicio, meio, fim); // Combina as duas metades ordenadas
    }
}

// Função que particiona o vetor e retorna a posição do pivô
int particiona(int *vetor, int inicio, int fim) {
    // Calcula o pivô como média dos três elementos (início, meio e fim)
    int pivo = (vetor[inicio] + vetor[fim] + vetor[(inicio + fim)/2]) / 3;
    
    while (inicio < fim) {
        // Encontra elemento maior que o pivô à esquerda
        while (inicio < fim && vetor[inicio] <= pivo)
            inicio++; // Corrigido: era inicio += inicio
            
        // Encontra elemento menor que o pivô à direita
        while (inicio < fim && vetor[fim] > pivo)
            fim--;   // Corrigido: era fim = fim - 1
            
        // Troca os elementos encontrados
        if (inicio < fim) {
            int aux = vetor[inicio];
            vetor[inicio] = vetor[fim];
            vetor[fim] = aux;
        }
    }
    return inicio;
}

// Função principal do QuickSort
void quick_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        // Obtém a posição do pivô após particionar
        int posi = particiona(vetor, inicio, fim);
        
        // Ordena recursivamente as duas partições
        quick_sort(vetor, inicio, posi - 1); // Subvetor à esquerda
        quick_sort(vetor, posi + 1, fim);    // Corrigido: era posi, agora é posi + 1
    }
}

// Função para gerar vetor de números aleatórios
void gerar_conjuntos(int* vetor, int tam) {
    int i = 0;
    while (i < tam) {
        int num = 1 + rand() % 100001; // Gera um número aleatório entre 1 e 100.000
        int repetido = 0; // Variável para verificar se o número já existe no vetor

        // Verifica se o número já está no vetor
        for (int j = 0; j < i; j++) {
            if (vetor[j] == num) {
                repetido = 1;
                break;
            }
        }

        // Adiciona o elemento caso ele não esteja repetido
        if (repetido == 0) {
            vetor[i] = num;
            i++;
        }
    }
}

void imprimir(int* vetor, int tam) {
    int limite = 10;  // Limite de números a serem exibidos
    int i;

    // Imprime até o limite definido
    for(i = 0; i < tam && i < limite; i++) {
        printf(" - %d", vetor[i]);
    }

    // Caso o vetor tenha mais que o limite, informa quantos números foram exibidos
    if (tam > limite) {
        printf("\n... e %d elementos restantes.\n", tam - limite);
    }

    printf("\n");
}

// Função para manter a propriedade do heap (Heapify)
void heapify(int* vetor, int tam, int i) {
    int maior = i; // `maior` armazena o índice do maior elemento entre `i`, `esquerda` e `direita`
    int esquerda = 2 * i + 1; // Calcula o índice do filho à esquerda de `i`
    int direita = 2 * i + 2; // Calcula o índice do filho à direita de `i`

    // Verifica se o filho à esquerda é maior que o nó atual
    if (esquerda < tam && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    // Verifica se o filho à direita é maior que o maior atual
    if (direita < tam && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    // Se o maior não é o nó atual, faz a troca e continua ajustando a heap recursivamente
    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        // Recursivamente chama `heapify` para garantir a propriedade da heap
        heapify(vetor, tam, maior);
    }
}

// Função para o algoritmo de ordenação Heap Sort
void heap_sort(int* vetor, int tam) {

    // Constrói a heap inicial, ajustando todos os nós começando do meio até o primeiro elemento
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(vetor, tam, i);
    }

    // Extrai o maior elemento e reorganiza a heap
    for (int i = tam - 1; i >= 0; i--) {

        // Troca o primeiro elemento (maior) com o último
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        // Chama `heapify` para restaurar a propriedade da heap para o restante do vetor
        heapify(vetor, i, 0);
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    //declaração de variáveis e vetores
    int tam = 1 + rand() % 100000; // gera um tamanho aleatório para o vetor entre 1 e 100.000
    int *vetor = (int *)malloc(tam * sizeof(int)); //vetor que será ordenado
    
    clock_t inicio, fim; //declaração das variáveis inicio e fim do tipo clock_t
    double tempo_execucao; //variável para armazenar o tempo de execução do algoritmo (fim - inicio)
    
    gerar_conjuntos(vetor, tam);
    
    //imprimindo vetor desordenado
    printf("\nVETOR DESORDENADO:\n");
    imprimir(vetor, tam);
    
    // Testando Bubble Sort
    inicio = clock();
    bubble_sort(vetor, tam);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\n\nVETOR ORDENADO COM BUBBLE SORT:\n");
    imprimir(vetor, tam);
    printf("\n\nTamanho do Vetor (Bubble Sort): %d elementos", tam);
    printf("\nTempo de execução (Bubble Sort): %f segundos\n", tempo_execucao);

    // Gerando novamente o vetor
    gerar_conjuntos(vetor, tam);

    // Testando Selection Sort
    inicio = clock();
    selection_sort(vetor, tam);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nVETOR ORDENADO COM SELECTION SORT:\n");
    imprimir(vetor, tam);
    printf("\n\nTamanho do Vetor (Selection Sort): %d elementos", tam);
    printf("\nTempo de execução (Selection Sort): %f segundos\n", tempo_execucao);

    // Gerando novamente o vetor
    gerar_conjuntos(vetor, tam);

    // Testando Insertion Sort
    inicio = clock();
    insertion_sort(vetor, tam);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nVETOR ORDENADO COM INSERTION SORT:\n");
    imprimir(vetor, tam);
    printf("\n\nTamanho do Vetor (Insertion Sort): %d elementos", tam);
    printf("\nTempo de execução (Insertion Sort): %f segundos\n", tempo_execucao);

    // Gerando novamente o vetor
    gerar_conjuntos(vetor, tam);

    // Testando Merge Sort
    inicio = clock();
    merge_sort(vetor, 0, tam - 1);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nVETOR ORDENADO COM MERGE SORT:\n");
    imprimir(vetor, tam);
    printf("\n\nTamanho do Vetor (Merge Sort): %d elementos", tam);
    printf("\nTempo de execução (Merge Sort): %f segundos\n", tempo_execucao);

    // Gerando novamente o vetor
    gerar_conjuntos(vetor, tam);

    // Testando Quick Sort
    inicio = clock();
    quick_sort(vetor, 0, tam - 1);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nVETOR ORDENADO COM QUICK SORT:\n");
    imprimir(vetor, tam);
    printf("\n\nTamanho do Vetor (Quick Sort): %d elementos", tam);
    printf("\nTempo de execução (Quick Sort): %f segundos\n", tempo_execucao);

    // Gerando novamente o vetor
    gerar_conjuntos(vetor, tam);

    // Testando Heap Sort
    inicio = clock();
    heap_sort(vetor, tam);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nVETOR ORDENADO COM HEAP SORT:\n");
    imprimir(vetor, tam);
    printf("\n\nTamanho do Vetor (Heap Sort): %d elementos", tam);
    printf("\nTempo de execução (Heap Sort): %f segundos\n", tempo_execucao);

    return 0;
}