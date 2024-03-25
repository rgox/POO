// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 07/04/2022

#include "sfml_renderer.hpp"
#include "text_renderer.hpp"

#include "dessin.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include <iostream>



// creerDessin : Crée un exemple de dessin.
// Crée toutes les formes *sur le tas* et les mets dans un Dessin
// Les formes devront être delete par la suite !
Dessin* creerDessin() {

    Dessin* dessin = new Dessin();
    
    // R
    dessin->addForme(std::make_shared<Rectangle>(50, 50, 60, 350));
    dessin->addForme(std::make_shared<Rectangle>(50, 50, 230, 60));
    dessin->addForme(std::make_shared<Rectangle>(220, 50, 230, 170));
    dessin->addForme(std::make_shared<Rectangle>(50, 160, 230, 170));
    dessin->addForme(std::make_shared<Rectangle>(180, 160, 190, 350));

    // O
    dessin->addForme(std::make_shared<Circle>(400, 200, 150));
    
    // B
    // Create vertexes (on stack)
    Point p1(600, 50);
    Point p2(600, 350);
    Point p3(700, 50);
    Point p4(750, 125);
    Point p5(700, 200);
    Point p6(600, 200);
    Point p7(750, 275);
    Point p8(700, 350);

    // Create lines
    dessin->addForme(std::make_shared<Line>(p1, p2));
    dessin->addForme(std::make_shared<Line>(p1, p3));
    dessin->addForme(std::make_shared<Line>(p3, p4));
    dessin->addForme(std::make_shared<Line>(p4, p5));
    dessin->addForme(std::make_shared<Line>(p5, p6));
    dessin->addForme(std::make_shared<Line>(p5, p7));
    dessin->addForme(std::make_shared<Line>(p7, p8));
    dessin->addForme(std::make_shared<Line>(p8, p2));
    
    return dessin;
}


void intersects()
{
    Rectangle r1(10,10,100,100);
    Rectangle r2(15,15,200,200);
    Rectangle r3(10,110,50,200);
    Rectangle r4(15,15,30,30);
    
    std::cout << "Should be true : " << r1.intersects(r2) << std::endl;
    std::cout << "Should be false : " << r1.intersects(r3) << std::endl;
    std::cout << "Should be true : " << r1.intersects(r4) << std::endl;
    

}



int main(int argc, char* argv[])
{

    intersects();
    // Créer un dessin
    Dessin* dessin = creerDessin();


    // Rendu graphique SFML
    SFMLRenderer render;
    dessin->display(render);
    
    // Rendu texte (console)
    TextRenderer trender;
    dessin->display(trender);

    // == Nettoyage  ==
    // PLUS BESOIN de delete() les formes : elles seront automatiquement détruites quand le vector de shared_ptr sera détruit !
//    for(int i = 0 ; i < dessin->nFormes() ; i++) // Itérer sur les numéros de forme
//        delete dessin->getForme(i); // Désalloue la forme

    delete dessin; // Supprime le dessin et son std::vector "formes", ce qui entraîne la destruction des objets formes eux-mêmes !
    
    return 0;
}


