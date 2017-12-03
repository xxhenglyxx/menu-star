
#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

struct Menu {

    std::string title;
    int entry;
    void ( * funct ) ( int value );
    bool main;

};

void createMenus ( const Menu menus [], const int size ) {

    int menuIds [ size ];

    for ( int index = 0; index < size; index++ ) {

        if ( !menus [ index ].main ) {



        }

    }

}

#endif