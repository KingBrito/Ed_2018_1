## O que você fez  
Implementei uma função "void create_lab_pilha(matriz<char>& mat)", o qual tem como função criar um labirinto usando os conceitos da pilha.

## Com quem e como você fez  

Fiz sozinho.
Para criar o labirinto eu criei uma pilha, o qual no codigo esta como "vector<Par> pilha".Para iniciar o codigo marquei um ponto como inicio, o qual foi determinado pelos comandos:

    Par inicio = (1,1);
    mat.get(inicio)=ABERTO; 

Uma pilha na programação, só pode retirar por onde colocou, então com esse conceito foi implementado essa parte do codigo:

while(pilha.size() != 0) {//faz o processo enquanto não estiver vazia
        vector<Par> canpierce;// cria uma pilha de lugares onde pode ser furado 
        Par topo = pilha.back(); // a variavel que ira procurar pelos 
				//  os lugares abertos
        for(auto vizinhos: getNeib(topo)){// inseri os lugares abertos 						  
					// na pilha canpierce
            if (countOpen(mat,vizinhos) <=1 && mat.equals(vizinhos,PAREDE))
                canpierce.push_back(vizinhos);
        }
					   
// Na pilha canpierce(do inglês "pode ser furado") alocado os locais a serem furados 
// como ABERTO
					   
    if (canpierce.size()!=0){
        int aux = rand() % canpierce.size();
        mat.get(canpierce[aux])=ABERTO;
        pilha.push_back(canpierce[aux]);
        mat_draw(mat);
        ed_show();
    }
    
    // se não poder ir por um caminho, volta alguns passos
    
    else{
      pilha.pop_back();
        }
    }
    
## O que aprendeu e sabe fazer  
Aprendi a criar pilha e usar vector.

## O que tem dificuldade ainda  
Entender os comandos que usar em c++  

## Quanto tempo levou pra fazer a atividade  
Consideremos que tive que ver os videos,estudar um pouco pela internet, por base devo ter levado ,mais ou menos, 7 horas. 
