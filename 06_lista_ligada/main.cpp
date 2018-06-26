#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    Node * deletarTudo(Node * node){
        if (node == nullptr)
        return nullptr;
        deletarTudo(node->next);
        delete node;
        return nullptr;

    }

    Node * _cortarRabo(Node * node, int value){

    }
    void cortarRabo(int value){

    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        auto node = head;
        auto nodebfr = node;

        if(head == nullptr){
            head = new Node(value);
            return;
        }

        while(node->next != nullptr){
            nodebfr = node;
            node = node->next;
        }
        nodebfr->next = new Node(value,nullptr);
    }

    Node * _push_back(Node * node, int value){
        if (node->next == nullptr)          // vai ate o ultimo nó
            node->next = new Node(value,nullptr); // cria um nó com value e aponta para o nulo

        node->next = _push_back(node->next,value); // se não vai para a proxima posição

        return node;
    }

    void rpush_back(int value){
        this->head = _push_back(head,value);
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
    }

public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

    void iremove(int value){
        auto node = head;
        auto ndebfr = node;
        if (node == nullptr){       // quando não tem nenhum valor
           return;
       }else if(node->value == value){ // quando o primeiro é
                                       // o valor a ser retirado
           auto aux2 = head;
           head = head->next;
           delete aux2;
           return;
       }

        while ((node->value != value)){ // quando esta no meio da lista
            ndebfr = node;
            node = node->next;
        }

        ndebfr->next = node->next;
        delete node;
    }


    void inserir_ordenado(int value){
        auto node = head;
        if (head->next->value > value){
            this->head = new Node(value,head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value,node->next);
    }

    Node * _rinserir_ordenado(Node * node, int value,int cont){
       if(node == nullptr || (node->value > value && cont <= 1)){
           node = new Node(value, node);
           cont++;
           return node;
       }
      node->next = _rinserir_ordenado(node->next,value,cont);
    }

    void rinserir_ordenado(int value){
        int cont = 0;
        this->head = _rinserir_ordenado(head,value,cont);

    }

    //read
    int size(Node *node){
        int cont;
        if(node->next == nullptr){
            return 1;

        }else if(node->next != nullptr){
        while(node != nullptr)
            cont++;
        return cont;
        }

        return 0;
    }
    // read
    int rsomar(Node * node){

        if(node->next == nullptr)
            return node->value;
        return node->value + rsomar(node->next);
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};

int main(){
    SList lista;

    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);

    lista.ishow();
    lista.deletarTudo(lista.head);
    lista.ishow();
//    lista.pop_back();
//    lista.ishow();
//    lista.pop_front();
//    lista.ishow();
    return 0;
}






