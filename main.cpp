#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

void initFunc();
void funReshape(int w, int h);
void funDisplay();

using namespace std;

int main(int argc, char** argv) {

 // Inicializamos GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Sesion 1");
    
 // Inicializamos GLEW
    GLenum err = glewInit();
    if(GLEW_OK != err) printf("Error: %s\n", glewGetErrorString(err));
    printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    const GLubyte *oglVersion = glGetString(GL_VERSION);
    printf("This system supports OpenGL Version: %s\n", oglVersion);
    
 // Inicializaciones específicas
    initFunc();
    
 // Configuración CallBacks
    glutReshapeFunc(funReshape);
    glutDisplayFunc(funDisplay);
    
    
    
    //Define la vista: DEFAULT
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
    
 // Bucle principal
    glutMainLoop();
    
    return 0;
}

void initFunc() {
    
}

void funReshape(int w, int h) {
    
    printf("Dimensiones %dx%d pixeles\n", w, h);
   //glScalef(w/500.0, h/500.0, 1.0f);
}

void funDisplay() {
    
 // Borramos el buffer de color
    glClearColor( 
  1.0,1.0,1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //SE APLICA COLOR A LO QUE SE VAYA A DIBUJAR
    glColor3f(0.25 ,0.88, 0.82); 
    
 // Dibujamos una tetera con modelo de alambre
    glutSolidTeapot(0.5f);
     //SE APLICA COLOR A LO QUE SE VAYA A DIBUJAR
    glColor3f(0.55 ,0 ,0); 
    
 // Dibujamos una tetera con modelo de alambre
    glutSolidTeapot(0.3f);
     //SE APLICA COLOR A LO QUE SE VAYA A DIBUJAR
    glColor3f(0.5 ,1 ,0); 
    
 // Dibujamos una tetera con modelo de alambre
    glutSolidTeapot(0.1f);
 // Intercambiamos los buffers
    glutSwapBuffers();
    
}