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
    Ambiente ctrlz;
    Ambiente ctrlr;

    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');
    
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
                		
						if ( ctrlz->texto->head == nullptr){
							continue;
						}
						else{
						amb.texto.insert(amb.cursor , ctrlz->texto->value);
						ctrlr.push_back(ctrlz.end());
						ctrlz.pop_back();

						}
    			    
                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                        cout << "control r" << endl;
                        if ( ctrlz->texto->head == nullptr){
							continue;
						}
						else{
						amb.texto.insert(amb.cursor , ctrlr->texto->value);
						ctrlz.push_back(ctrlr.end());
						ctrlr.pop_back();

						}
                }
                 else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    cout << tecla << endl;// 'r' e 'z' não esta funcionando
                    amb.texto.insert(amb.cursor,tecla);
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    char espaco = ' ';
                    atual.push_back(espaco);
                    amb.texto.insert(amb.cursor,' ');
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    if(amb.cursor != amb.texto.begin()){
                    amb.texto.erase(amb.cursor++ ,amb.cursor--);
                    cout << "backspace" << endl;
                    }
                }
                else if(event.key.code == sf::Keyboard::Delete){
                    if(amb.cursor != amb.texto.begin()){
                    amb.texto.erase(amb.cursor--,amb.cursor++);
                    cout << "delete" << endl;
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    if(amb.cursor != amb.texto.begin()){
                        amb.cursor--;

                    }

                }
                else if(event.key.code == sf::Keyboard::Right){
                    if(amb.cursor != amb.texto.end()){
                        amb.cursor++;

                    }
                }

            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}

