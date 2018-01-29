#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

float red,green,blue,light;
float sizeTeapot;
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
    red=w/1000.0f;
    green=h/1000.0f;
    blue=w/500.0f-h/500.0f;
    sizeTeapot=w/2000.0f+h/2000.0f;
   //glScalef(w/500.0, h/500.0, 1.0f);
}

void funDisplay() {
    
    
 // Borramos el buffer de color
    glClearColor( 
  1.0,1.0,1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
   
     //SE APLICA COLOR A LO QUE SE VAYA A DIBUJAR
    glColor3f(red,green,blue); 
    
 // Dibujamos una tetera con modelo de alambre
    glutWireTeapot(sizeTeapot);

 // Intercambiamos los buffers
    glutSwapBuffers();
    
}