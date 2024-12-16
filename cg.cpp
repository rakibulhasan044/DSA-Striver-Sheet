#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

using namespace std;

void renderBitmapString(float x, float y, float z, void *font, char *string) {
   char *c;
   glRasterPos3f(x, y,z);
   for (c=string; *c != '\0'; c++)
   {
       glutBitmapCharacter(font, *c);
   }
}

void display() {
   // Set the background color to dark gray and opaque
   glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
   // Draw the horizontal line
   glBegin(GL_LINES);
   glColor3f(1.0f, 0.0f, 0.0f); // Red color
   glVertex2f(-1.0f, 0.0f);
   glVertex2f(1.0f, 0.0f);
   glVertex2f(0.0f, -1.0f);
   glVertex2f(0.0f, 1.0f);
   glEnd();

   // sudan flag
   glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f);
   glVertex2f(-0.1f, 0.3f);
   glVertex2f(-0.9f, 0.3f);
   glVertex2f(-0.9f, 0.7f);
   glVertex2f(-0.1f, 0.7f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(-0.1f, 0.7f);
   glVertex2f(-0.9f, 0.7f);
   glVertex2f(-0.9f, 0.55f);
   glVertex2f(-0.1f, 0.55f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f(-0.1f, 0.3f);
   glVertex2f(-0.9f, 0.3f);
   glVertex2f(-0.9f, 0.45f);
   glVertex2f(-0.1f, 0.45f);
   glEnd();
   
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(-0.6f, 0.5f);
   glVertex2f(-0.9f, 0.3f);
   glVertex2f(-0.9f, 0.7f);
   glEnd();
   
   //denmark flag
   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.1f, 0.7f);
   glVertex2f(0.9f, 0.7f);
   glVertex2f(0.9f, 0.3f);
   glVertex2f(0.1f, 0.3f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f);
   glVertex2f(0.3f, 0.7f);
   glVertex2f(0.4f, 0.7f);
   glVertex2f(0.4f, 0.3f);
   glVertex2f(0.3f, 0.3f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f);
   glVertex2f(0.1f, 0.55f);
   glVertex2f(0.9f, 0.55f);
   glVertex2f(0.9f, 0.45f);
   glVertex2f(0.1f, 0.45f);
   glEnd();
   
   //tonga
   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.9f, -0.8f);
   glVertex2f(0.1f, -0.8f);
   glVertex2f(0.1f, -0.1f);
   glVertex2f(0.9f, -0.1f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f);
   glVertex2f(0.1f, -0.1f);
   glVertex2f(0.6f, -0.1f);
   glVertex2f(0.6f, -0.5f);
   glVertex2f(0.1f, -0.5f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.3f, -0.15f);
   glVertex2f(0.4f, -0.15f);
   glVertex2f(0.4f, -0.45f);
   glVertex2f(0.3f, -0.45f);
   glEnd();
   
   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.15f, -0.25f);
   glVertex2f(0.55f, -0.25f); 
   glVertex2f(0.55f, -0.35f);
   glVertex2f(0.15f, -0.35f);
   glEnd();
   
   //somali
   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.0f, 0.8f);
   glVertex2f(-0.9f, -0.8f);
   glVertex2f(-0.1f, -0.8f);
   glVertex2f(-0.1f, -0.1f);
   glVertex2f(-0.9f, -0.1f);
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glColor3f(1.0f, 1.0f, 1.0f);

   glVertex2f(-0.5f, -0.45f);
   glVertex2f(-0.5f, -0.3f);
   glVertex2f(-0.47f, -0.4f);
   glVertex2f(-0.4f, -0.4f);
   glVertex2f(-0.45f, -0.5f);
   glVertex2f(-0.42f, -0.6f);
   glVertex2f(-0.5f, -0.55f);
   glVertex2f(-0.58f, -0.6f);
   glVertex2f(-0.55f, -0.5f);
   glVertex2f(-0.6f, -0.4f);
   glVertex2f(-0.53f, -0.4f);
   glVertex2f(-0.5f, -0.3f);
   glEnd();

   glFlush();
}

// Main function: GLUT runs as a console application starting at main() 
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(640, 480); // Set the window's initial width & height
   glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop(); // Enter the event-processing loop
   return 0;
}

int main(int argc, const char * argv[]) {
   // insert code here...
   std::cout << "Hello, World!\n";
   return 0;
}

