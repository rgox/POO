// Miranda Coninx
// ISIR - Sorbonne Universite / CNRS
// 08/04/2022

#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
#include "catch.hpp"

#include "rectangle.hpp"

TEST_CASE("Rectangle operations", "[rectangle]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md#type-parametrised-test-cases
    Rectangle r1(10,10,100,100);
    Rectangle r2(15,15,200,200);
    Rectangle r3(10,110,50,200);
    Rectangle r4(15,15,30,30);
    
    




    SECTION( " 4x float constructor " ) {
        // Tests constructeur, sur r3 de centre (30,155) et de largeur 40 hauteur 90
        REQUIRE(r3.getX() == Approx(30));
        REQUIRE(r3.getY() == Approx(155));
        REQUIRE(r3.getWidth() == Approx(40));
        REQUIRE(r3.getHeight() == Approx(90));    
    }

    SECTION( " center, width, height constructor " ) {
        // Tests de l'autre consstructeur
        Rectangle r_center(Point(12,42),23,17); // Construceur alternatif
        
        REQUIRE(r_center.getX() == Approx(12));
        REQUIRE(r_center.getY() == Approx(42));
        REQUIRE(r_center.getWidth() == Approx(23));
        REQUIRE(r_center.getHeight() == Approx(17));
    }

    
    SECTION( "area and perimeter" ) {
        REQUIRE( r3.area() == Approx(3600));
        REQUIRE( r3.perimeter() == Approx(260));
    }
    
    
    SECTION( "intersection" ) {
        REQUIRE( r1.intersects(r2)); // Regular intersection
        REQUIRE_FALSE( r1.intersects(r3)); // No intersection
        REQUIRE( r1.intersects(r4)); // r4 included in r1
        
        // This should be commutative
        REQUIRE( r2.intersects(r1)); 
        REQUIRE_FALSE( r3.intersects(r1));
        REQUIRE( r4.intersects(r1));
    }
    
}
