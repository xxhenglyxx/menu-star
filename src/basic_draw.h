
#include <OpenGL/gl.h>
#include <iostream>

#ifndef GRID_H
#define GRID_H

void drawText (
    
    const char text [],
    const int size,
    const GLint pos_x = 0,
    const GLint pos_y = 0

) {

    glRasterPos2i ( pos_x, pos_y );

    for ( int index = 0; index < size; index ++ ) {

        glutBitmapCharacter ( GLUT_BITMAP_HELVETICA_12, text[ index ] );

    }

    glFlush ();

}

void drawStar (

    const int corners = 6,
    const int radius = 200

) {

    glBegin ( GL_LINE_LOOP );

        glVertex2i ( 0, 200 );
        glVertex2i ( -200, -200 );
        glVertex2i ( 200, -200 );

    glEnd ();

    glBegin ( GL_LINE_LOOP );

        glVertex2i ( 0, -300 );
        glVertex2i ( -200, 100 );
        glVertex2i ( 200, 100 );

    glEnd ();

    glFlush ();

}

template < class T >
void drawGrid (

    const T WIDTH,
    const T HEIGHT,
    const T UNIT,
    const double r = 1.0,
    const double g = 1.0,
    const double b = 1.0

) {

    int unit_distance = 0;

    glColor3d ( r, g, b );

    glBegin ( GL_LINES );

        glVertex2f ( - WIDTH, 0 );
        glVertex2f ( WIDTH, 0 );

    glEnd ();

    while ( unit_distance < WIDTH ) {

        const char * text = std::to_string ( unit_distance ).c_str ();
        const char * text2 = std::to_string ( - unit_distance ).c_str ();

        glBegin ( GL_LINES );

            glVertex2f ( unit_distance, 16 );
            glVertex2f ( unit_distance, -16 );

        glEnd ();

        drawText ( text, 3, unit_distance - 30, - 70 );

        glBegin ( GL_LINES );

            glVertex2f ( 16, unit_distance );
            glVertex2f ( -16, unit_distance );
        
        glEnd ();

        drawText ( text, 3, 50, unit_distance - 10 );

        glBegin ( GL_LINES );

            glVertex2f ( - unit_distance, 16 );
            glVertex2f ( - unit_distance, -16 );

        glEnd ();

        drawText ( text2, 4, - unit_distance - 30, - 70 );

        glBegin ( GL_LINES );

            glVertex2f ( 16, - unit_distance );
            glVertex2f ( -16, - unit_distance );
        
        glEnd ();

        drawText ( text2, 4, 50, - unit_distance - 10 );

        unit_distance += 100;

    }

    glBegin ( GL_LINES );
        
        glVertex2f ( 0, HEIGHT );
        glVertex2f ( 0, -HEIGHT );

    glEnd ();

    drawText ( "X", 1, 30, 760 );
    drawText ( "Y", 1, 760, 30 ); 

    glFlush ();

}

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

#endif