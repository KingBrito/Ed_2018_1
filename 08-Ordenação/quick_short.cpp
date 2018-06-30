#include <iostream>
#include <vector>
#include <stdio.h>


using namespace std;

void insertion_sort(vector<int> v){
	int tam = v.size();
	int i,j,aux;

	for (i = 1; i < tam; i++)
	{
		aux = v[i];
		j = i - 1;

		while((j >= 0) && (aux < v[j])){
			v[j+1] = v[j];
			j--;
		}

		v[j+1] = aux;
	}

}

void merge(vector<int> &vet,int inicio,int meio, int fim){

	int init = inicio;
	int initmeio = meio + 1;
	int aux = 0;
	int size = (fim - inicio) + 1;
	vector<int> vetaux;
    vetaux.reserve(fim -inicio);
	while((init <= meio) && (initmeio <= fim)){

		if (vet[init] < vet[initmeio]){
			vetaux[aux++] = vet[init++];
		}else{
			vetaux[aux++] = vet[initmeio++];
		}
	}

	while(init <= initmeio){
		vetaux[aux++] = vet[init++];

	}

	while(initmeio <= fim){
		vetaux[aux++] = vet[initmeio++];

	}

	for (aux = inicio; aux <= fim; aux++){
		vet[aux] = vetaux[aux - inicio];
	}

}

void mergesort(vector<int> v,int inicio, int fim){

	if (fim == inicio + 1)
        return;

		int meio = (inicio + fim)/2;
		mergesort(v,inicio,meio);
		mergesort(v,meio + 1,fim);
		merge(v,inicio,meio,fim);


}

void quick_sort(vector<int> &v,int bg, int end){

	if (bg >= end)
	   return;
	int pivo = v[bg];
	int i = bg;
	int j = end;

	while(i <= j){
		while(v[i] < pivo)
			i++;
		while(v[j] > pivo)
			j--;
		if (i <= j)
		{
			std::swap(v[i++], v[j--]);

		}
	}
	quick_sort(v,bg,j);
	quick_sort(v,i,end);

}

void test_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++)
        if(vet[i] <= vet[i + 1])
        	cout << vet[i] << ' ';
}

int main(int argc, char const *argv[])
{
	vector<int> v = {1,7,6,8,9,5,4,3,2,10};

	insertion_sort(v,);
	quick_sort(v, 0, vet.size() - 1);
	test_sort(v);
	return 0;
}
