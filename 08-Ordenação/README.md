## O que você fez ?
Fiz os algoritmos de ordenação insertion_sort,merge_sort e quick_sort

## Com quem e como você fez ?
Fiz sozinho.
O quick_sort se baseia na frase conquistar para dividir, sabendo disso vamos para o codigo :

Na função quick_sort(), foi passado o vetor, a primeira posição representada pelo inteiro ponto e a ultima posição pelo inteiro final

    void quick_sort(vector<int> &bruto, int inicio,int fim){

Por ser metodo que use recursão precisa de um ponto de parada, existe essa condição de parada, pois não seria necessario fazer a ordenação de um vetor com uma unica posição:
 
        if(inicio >= fim) // 
            return;
    int pivo,i,j;
    pivo = bruto[inicio];
    i = inicio;
    j = fim;

Será feito varias comparações, de acordo com a posição dos indices.

    while(i <= j){
            while(bruto[i] <= pivo){
                i--;
            }
            while(bruto[j] >= pivo){
                j++
            }
        if(i <= j ){
            std::swap(bruto[i++],bruto[j--])
        }
    }

    quick_sort(bruto,inicio,j);
    quick_sort(bruto,i,fim);
    
}
