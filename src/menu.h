
#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

int shape = 0; // denote 0 for sine wave, 1 for star
float axis_color [ 3 ] = { 1.0, 1.0, 1.0 }; // check axisMenu
float bg_color [ 4 ] = { .5f, .0f, .0f, .8f }; // check backgruondMenu
int object = 1;

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

void objectShape ( int value ) {

    switch ( value ) {

        case 1: {

            object = 1;
            glutPostRedisplay ();

            break;

        }

        case 2: {

            object = 2;
            glutPostRedisplay ();

            break;

        }

    }

}

void axisMenu ( int value ) {

    switch ( value ) {

        case 1: {

            axis_color [ 0 ] = 1.0;
            axis_color [ 1 ] = 1.0;
            axis_color [ 2 ] = 1.0;

            glutPostRedisplay ();
            glFlush ();

            break;

        }

        case 2: {

            axis_color [ 0 ] = .0;
            axis_color [ 1 ] = .0;
            axis_color [ 2 ] = .0;

            glutPostRedisplay ();
            glFlush ();

            break;

        }

        default: break;

    }

}

void backgroundMenu ( int value ) {

    switch ( value ) {

        case 1: {

            bg_color [ 0 ] = .5f;
            bg_color [ 1 ] = .0f;
            bg_color [ 2 ] = .0f;
            bg_color [ 3 ] = .8f;

            glutPostRedisplay ();

            break;

        }

        case 2: {

            bg_color [ 0 ] = .0;
            bg_color [ 1 ] = .0;
            bg_color [ 2 ] = .0;
            bg_color [ 3 ] = 1.0;

            glutPostRedisplay ();

            break;

        }

        default: break;

    }

}

void geometricMenu ( int value ) {

    switch ( value ) {

        case 1: {

            shape = 0;
            glutPostRedisplay ();

            break;

        }

        case 2: {

            shape = 1;
            glutPostRedisplay ();
            
            break;

        }

        case 3: {

            shape = 2;
            glutPostRedisplay ();

            break;

        }

        default: break;

    }

}

void mainMenu ( int value ) {

    axisMenu ( value );

    backgroundMenu ( value );

}

void displayMenu () {

    // create menus
    int axis_menu = glutCreateMenu ( axisMenu );

    glutAddMenuEntry ( "White Axis", 1 );
    glutAddMenuEntry ( "Black Axis", 2 );

    int background_color_menu = glutCreateMenu ( backgroundMenu );

    glutAddMenuEntry ( "Default Color", 1 );
    glutAddMenuEntry ( "Black", 2 );

    int geometric_type = glutCreateMenu ( geometricMenu );

    glutAddMenuEntry ( "Point", 1 );
    glutAddMenuEntry ( "Line Strip", 2 );
    glutAddMenuEntry ( "Line Loop", 3 );

    int object_shape = glutCreateMenu ( objectShape );

    glutAddMenuEntry ( "Sine Wave", 1 );
    glutAddMenuEntry ( "6 Corners Star", 2 );

    int main_menu = glutCreateMenu ( mainMenu );

    glutAddSubMenu ( "Axis Color", axis_menu );
    glutAddSubMenu ( "Background Color", background_color_menu );
    glutAddSubMenu ( "Geometric Type", geometric_type );
    glutAddSubMenu ( "Object Shape", object_shape );

    glutAttachMenu ( GLUT_RIGHT_BUTTON );

}

#endif