
#ifndef MATH_SHAPE_H
#define MATH_SHAPE_H

#include <OpenGl/gl.h>
#include <math.h>

#define PI 3.14

void drawSineWave (
    
    const GLenum geometric_type = GL_POINTS,
    const double amplitude = 200,
    const double phase = 0,
    const double frequency = 10,
    const double duration_from = -1000,
    const double duration_to = 1000

) {

    const double angular_frequency = 2 * PI * frequency;

    glBegin ( geometric_type );

        glColor3d ( 1.0, 1.0, .0 );
    
        for ( int duration = duration_from; duration < duration_to; duration ++ ) {

            glVertex2f ( duration, amplitude * sin ( ( angular_frequency * duration ) + phase ) );

        }

    glEnd ();

    glFlush ();

}

template < class T >
void drawStellarShape (

    const T radius,
    const T a,
    const T b,
    const T c,
    const int corners,
    const GLenum geometric_type = GL_POINTS

) {

    double x, y, r, sineq, logeq;

    const double x_max = sqrt ( - log ( 2 * exp ( - pow ( a, 2 ) ) - 1 ) ) / pow ( b, 2 );

    for ( int angle = 0; angle < 360; angle ++ ) {

        // r = radius * x_max + sqrt ( - log ( 2 * exp ( - pow ( a, 2 ) ) - exp ( - pow ( b, 2 ) * pow ( x_max, 2 ) * pow ( sin ( ( angle * PI / 180 ) - PI / 2 ) * ( corners / 2 ), 2 ) ) ) ) / c;

        sineq = pow ( sin ( ( angle * PI / 180 ) - ( PI / 2 ) ) * corners / 2, 2 );

        logeq = 2 * exp ( - pow ( a, 2 ) ) - exp ( - pow ( b, 2 ) * pow ( x_max, 2 ) * sineq );

        r = radius * x_max + sqrt ( - log ( logeq ) ) / c;

        glBegin ( geometric_type );

            glVertex2f ( r * cos ( angle ), r * sin ( angle ) );

        glEnd ();

    }

    glFlush ();

}

#endif