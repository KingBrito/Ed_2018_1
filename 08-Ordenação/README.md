## O que voc� fez ?
Fiz os algoritmos de ordena��o insertion_sort,merge_sort e quick_sort

## Com quem e como voc� fez ?
Fiz sozinho.
O quick_sort se baseia na frase conquistar para dividir, sabendo disso vamos para o codigo :

Na fun��o quick_sort(), foi passado o vetor, a primeira posi��o representada pelo inteiro ponto e a ultima posi��o pelo inteiro final

    void quick_sort(vector<int> &bruto, int inicio,int fim){

Por ser metodo que use recurs�o precisa de um ponto de parada, existe essa condi��o de parada, pois n�o seria necessario fazer a ordena��o de um vetor com uma unica posi��o:
 
        if(inicio >= fim) // 
            return;
    int pivo,i,j;
    pivo = bruto[inicio];
    i = inicio;
    j = fim;

Ser� feito varias compara��es, de acordo com a posi��o dos indices.

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
