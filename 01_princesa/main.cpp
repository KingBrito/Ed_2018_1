#include <iostream>
#include <list>

using namespace std;

void mostrar(list<int> lista){
    for(auto num : lista)
        cout << num <<", ";
    cout << "\n";
}

int main()
{   //tam = tamanho do vetor
    //esc = onde começa a matar
    //n = o tamanho de saltos

    int tam,esc,n;
    cin >> tam >> esc >> n;

    list <int> lista;

    //preenche a lista
    for(int i = 0;i < tam;i++){
        lista.push_back(i + 1);
    }

    //gira a lista
    //exemplo : temos a lista =   12345 ,e o escolhido foi o 3
    //quando girar ficará assim : 34512
    while (lista.front() != esc){
        lista.push_back(lista.front());
        lista.pop_front();
    }


    while(lista.size() != 1) {
        //Aqui determina a quantidade de saltos
        for(int i = 0; i < n; i++){
        //copia o primeiro para o ultimo lugar
        lista.push_back(lista.front());
        //e mata o original
        lista.pop_front();
        }
        //mata o pretendente
        lista.pop_front();
        mostrar(lista);
    }
    mostrar(lista);

}
