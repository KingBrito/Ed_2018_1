#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "libs/sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }
    //construtor de cÃ³pia
    Ambiente(const Ambiente& other):
        texto(other.texto)
    {
        this->cursor = this->texto.begin();
        for(auto it = other.texto.begin(); it != other.cursor; it++)
            this->cursor++;
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "#";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;
    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');

    lista<Ambiente> ctrl;
    lista<Ambiente>::iterator atual;
    ctrl.push_back(amb);
    atual = ctrl.begin();

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;

        while(janela.pollEvent(event)){
        	ctrlz.texto.push_back(event.key.code);

            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                		cout << "control z" << endl;
                        if(atual == ctrl.end())
                            atual--;

                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                        cout << "control r" << endl;
                        if (atual != --ctrl.end())
                        atual++;
                        
                }
                 else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    cout << tecla << endl;// 'r' e 'z' não esta funcionando
                    
                    auto aux = atual;
                    ctrl.erase( aux + 1, ctrl.end());
                    ctrl.push_back(*atual);
                    atual = ctrl.end();
                    atual->texto.insert(atual->cursor,tecla);
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    atual->texto.insert(atual->cursor,' ');
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    if(atual->cursor != atual->texto.begin()){
                    atual->texto.erase(atual->cursor++ ,atual->cursor--);
                    cout << "backspace" << endl;
                    }
                }
                else if(event.key.code == sf::Keyboard::Delete){
                    if(atual->cursor != atual->texto.begin()){
                    atual->texto.erase(atual->cursor--,atual->cursor++);
                    cout << "delete" << endl;
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    if(atual->cursor != atual->texto.begin()){
                        atual->cursor--;

                    }

                }
                else if(event.key.code == sf::Keyboard::Right){
                    if(atual->cursor != atual->texto.end()){
                        atual->cursor++;

                    }
                }

            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, atual->toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}

