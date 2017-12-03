
#include <iostream>
#include <string>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "basic_draw.h"
#include "math_shape.h"
#include "menu.h"

int shape = 0; // denote 0 for sine wave, 1 for star

void drawLinei (

    const int p1,
    const int p2,
    const int p3,
    const int p4

) {

    glBegin ( GL_LINES );

        glVertex2i ( p1, p2 );
        glVertex2i ( p3, p4 );

    glEnd ();

    glFlush ();

}

void axisMenu ( int value ) {

    switch ( value ) {

        case 1: {

            drawGrid ( 800, 800, 10 );
            break;

        }

        case 2: {

            drawGrid ( 800, 800, 10, .0, .0, .0 );
            break;

        }

        default: break;

    }

}

void backgroundMenu ( int value ) {

    switch ( value ) {

        case 3: {

            glClearColor ( .5f, .0f, .0f, .8f );
            glClear ( GL_COLOR_BUFFER_BIT );
            glFlush ();

            drawGrid ( 800, 800, 10 );
            drawSineWave ();

            break;

        }

        case 4: {

            glClearColor ( .0, .0, .0, 1 );
            glClear ( GL_COLOR_BUFFER_BIT );
            glFlush ();

            drawGrid ( 800, 800, 10 );
            drawSineWave ();

            break;

        }

        default: break;

    }

}

void geometricMenu ( int value ) {

    switch ( value ) {

        case 5: {

            if ( shape == 0 ) {

                drawSineWave ( GL_POINTS );

            }

            break;

        }

        case 6: {

            if ( shape == 0 ) {

                drawSineWave ( GL_LINE_STRIP );

            }

            break;

        }

        case 7: {

            if ( shape == 0 ) {

                drawSineWave ( GL_LINE_LOOP );

            }

            break;

        }

        default: break;

    }

}

void mainMenu ( int value ) {

    axisMenu ( value );

    backgroundMenu ( value );

}

void render () {

    drawGrid ( 800, 800, 10 );

    drawSineWave ();

    glFlush ();

}

int main ( int arg_length, char ** args_context ) {
    
    glutInit ( &arg_length, args_context );

    // window context
    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( 800, 800 );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Simple GL Application" );

    // get basic window ready
    glClearColor ( .5f, .0f, .0f, .8f );
    glClear ( GL_COLOR_BUFFER_BIT );
    glLoadIdentity (); // reset draw location

    gluOrtho2D ( -800, 800, -800, 800 ); // move camera back - can varies by input
    glFlush (); // flush all buffer to gpu

    // create menus
    int axis_menu = glutCreateMenu ( axisMenu );

    glutAddMenuEntry ( "White Axis", 1 );
    glutAddMenuEntry ( "Black Axis", 2 );

    int background_color_menu = glutCreateMenu ( backgroundMenu );

    glutAddMenuEntry ( "Default Color", 3 );
    glutAddMenuEntry ( "Black", 4 );

    int geometric_type = glutCreateMenu ( geometricMenu );

    glutAddMenuEntry ( "Point", 5 );
    glutAddMenuEntry ( "Line Strip", 6 );
    glutAddMenuEntry ( "Line Loop", 7 );

    int main_menu = glutCreateMenu ( mainMenu );

    glutAddSubMenu ( "Axis Color", axis_menu );
    glutAddSubMenu ( "Background Color", background_color_menu );
    glutAddSubMenu ( "Geometric Type", geometric_type );

    glutAttachMenu ( GLUT_RIGHT_BUTTON );

    // rendering
    glutDisplayFunc ( render );

    // looping
    glutMainLoop ();

    return 0;

};