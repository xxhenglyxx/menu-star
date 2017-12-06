
#include <iostream>
#include <string>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "basic_draw.h"
#include "math_shape.h"
#include "menu.h"

void render () {

    glClearColor ( bg_color[ 0 ], bg_color[ 1 ], bg_color[ 2 ], bg_color[ 3 ] );
    glClear ( GL_COLOR_BUFFER_BIT );

    drawGrid ( 800, 800, 10, axis_color[ 0 ], axis_color[ 1 ], axis_color[ 2 ] );

    if ( object == 1 ) {

        if ( shape == 0 )

            drawSineWave ( GL_POINTS );

        if ( shape == 1 )

            drawSineWave ( GL_LINE_STRIP );

        if ( shape == 2 )

            drawSineWave ( GL_LINE_LOOP );

    } else {

        drawStar ();

    }

    // drawStar ();

    // drawStellarShape ( .1, 0.81, 0.14, 1.0, 5 );

}

int main ( int arg_length, char ** args_context ) {
    
    glutInit ( &arg_length, args_context );

    // window context
    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( 800, 800 );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Simple GL Application" );

    // get basic window ready
    glLoadIdentity (); // reset draw location
    gluOrtho2D ( -800, 800, -800, 800 ); // move camera back - can varies by input
    glFlush (); // flush all buffer to gpu

    displayMenu ();

    // rendering
    glutDisplayFunc ( render );

    // looping
    glutMainLoop ();

    return 0;

};