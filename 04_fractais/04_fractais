#include <lib/pen.h>
void flo_gelo(Pen& p,int aux, int lado){
    float angulo = 72;
    if( aux == 0||lado < 3)
        return;

    p.walk(lado);
    flo_gelo(p,5,lado *0.36);
    p.walk(-lado);
    p.right(angulo); // 360*0.2
    p.setColor(rand() % 255,rand() % 255,rand() % 255);
    aux--;
    flo_gelo(p,aux,lado);
}

void circulos(Pen& p, double lado){
    if(lado < 1)
        return;
    p.circle(lado);
    for(int i = 0; i < 6; i++){
        p.left(60);
        p.up();
        p.walk(lado);
        p.down();
        circulos(p,lado*2/6);
        p.up();
        p.walk(-lado);
        p.down();
    }
}
void arvore(Pen& p, int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= (p.rand() % 7 - 3);
    if(lado < 10)
        return;
    if(lado > 10 && lado < 15){
        p.setColor(255,0,0);
        for(int i = 0;i<4 ;i++){
        p.circle(i);
        }
    }
    p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(lado);
    p.right(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.right(ang);
    //p.setColor(sf::Color::Red);
    p.walk(-lado);
}
void triangulo(Pen &p,int lado){
    if(lado <=15)
        return;
    for (int i = 0; i<2;i++){
        p.setColor(rand() % 255,rand() % 255,rand() % 255);
        p.walk(lado);
        p.left(120);
        triangulo(p,lado*0.7);
    }
}

void trigo(Pen &p,int lado){
    int ang = 45;

    if(lado <= 5)
        return;
    p.setColor(sf::Color::Green);
    for (int i = 0; i<4; i++){
    p.walk(lado);
    p.right(ang);
    trigo(p,lado/2);
    p.left(2*ang);
    trigo(p,lado/2);
    p.right(ang);
    }

    p.setColor(sf::Color::Yellow);
    for(int i = 0,z=5; i<4 ;i++,z--){
    p.setThickness(z);
    p.walk(-lado);
    }

}
void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(5);
    //trigo(p, 50);
    //triangulo(p, 60);
    //arvore(p,100); pé de acerola
    //circulos(p,150);
    //flo_gelo(p,5,100);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
