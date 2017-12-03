
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

#endif