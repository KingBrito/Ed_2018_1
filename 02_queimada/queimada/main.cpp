#include <iostream>
#include <list>
#include <vector>
#include <locale>
using namespace std;

const int nl = 10;
const int nc = 20;

void mostrar(char mat[nl][nc]) {
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++){
            cout << mat[i][j];
        }
       cout << endl;
    }
}

void limpar() {
    for (int i = 0; i < 12; i++)
        cout << endl;
}

void esperar() {
    char c;
    cin >> std::noskipws >> c;
}

struct Par {
    int l, c;
};

vector<Par> adjacentes(int l, int c) {
    vector<Par> adj;

    adj.push_back(Par{l, c + 1});
    adj.push_back(Par{l, c - 1});
    adj.push_back(Par{l + 1, c});
    adj.push_back(Par{l - 1, c});
    return adj;
}

void queimar(int l, int c, char mat[nl][nc],int &cont) {
    // Verifica se esta dentro da matriz
    if (l < 0 or l >= nl)
        return;
    if (c < 0 or c >= nc)
        return;

    limpar();
    mostrar(mat);
    esperar();

    if (mat[l][c] == '#') {
        mat[l][c] = '_';
        cont++;
        for (auto par : adjacentes(l, c))
            queimar( par.l, par.c, mat,cont);
    }
    cout << cont;
}

int main() {
    locale::global(locale("en_US.utf8"));
    wcout.imbue(locale());

    char mat[nl][nc];
    int qtd = 200;
    int lin, col;
    int cont = 0;

    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            mat[i][j] = '.';
        }
    }

    for (int i = 0; i < qtd; i++) {
        mat[rand() % nl][rand() % nc] = '#';
        limpar();
        mostrar(mat);
        // esperar();
    }

    cout << "Digite o x e o y para começar a queimada" << endl;
    cin >> lin >> col;

    queimar(lin, col, mat,cont);

    wcout << L"Árvores queimadas:" << cont << "\n";

    return 0;
}
