#include <iostream>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
            //this->reserve(2 * _capacitade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return _size;
    }
    int capacity(){
        return _capacidade;
    }

    void reserve(int capacity){
		if(this->_capacidade >= capacity)
			return;

       int checkpoint [this->_capacidade];

       for(int i = 0; i < this->_size; i++)//salva o bloco antigo em algum lugar
            checkpoint[i] = this->_data[i];//pede uma novo bloco de dados

       if (capacity >= this->_size){
           this->_capacidade = capacity;
       }

       for(int i = 0; i < this->_size; i++)//salva o bloco antigo em algum lugar
            this->_data[i] = checkpoint[i];

    }


};

#include <vector>
int main()
{
    vector<int> v;

    v.push_back(1);//1 elemento, 1 de capacidade
    v.push_back(3);//2 elementos,2 de cap
    v.push_back(5);//3 elementos,4 cap
	
	v.reserve(10);
    v.reserve(4);

    
    cout << v.size() << endl;

    cout << v.capacity()<< endl;

}
