include<stdio.h>

#include<windows.h>

#include <GL/glut.h>

#define KEY_ESC 27 /* GLUT doesn't supply this */

int fullscreen = 0;

int mouseDown = 0;

float xrot = 100.0f;

float yrot = -100.0f;

float xdiff = 100.0f;

float ydiff = 100.0f;

float tra_x = 0.0f;

float tra_y = 0.0f;

float tra_z = 0.0f;


float grow_shrink = 70.0f;

float resize_f = 1.0f;

void drawBox()
{

   
    glTranslatef(tra_x, tra_y, tra_z);

    glBegin(GL_QUADS);
   
   

    glColor3f(1.0f, 0.0f, 0.0f);
    // FRONT

    glVertex3f(-0.5f, -0.5f, 0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex3f( 0.5f, -0.5f, 0.5f);

    glVertex3f( 0.5f, 0.5f, 0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex3f(-0.5f, 0.5f, 0.5f); // BACK

    glVertex3f(-0.5f, -0.5f, -0.5f);

    glVertex3f(-0.5f, 0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex3f( 0.5f, 0.5f, -0.5f);

    glVertex3f( 0.5f, -0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f); // LEFT

    glVertex3f(-0.5f, -0.5f, 0.5f);

    glVertex3f(-0.5f, 0.5f, 0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-0.5f, 0.5f, -0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex3f(-0.5f, -0.5f, -0.5f);  // RIGHT

    glVertex3f( 0.5f, -0.5f, -0.5f);

    glVertex3f( 0.5f, 0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex3f( 0.5f, 0.5f, 0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex3f( 0.5f, -0.5f, 0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);  // TOP

    glVertex3f(-0.5f, 0.5f, 0.5f);

    glVertex3f( 0.5f, 0.5f, 0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex3f( 0.5f, 0.5f, -0.5f);

    glVertex3f(-0.5f, 0.5f, -0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);// BOTTOM

    glVertex3f(-0.5f, -0.5f, 0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-0.5f, -0.5f, -0.5f);

    glVertex3f( 0.5f, -0.5f, -0.5f);

    glVertex3f( 0.5f, -0.5f, 0.5f);

    glEnd();
}

int init(void)
{
    glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LEQUAL);

    glClearDepth(1.0f);

    return 1;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
    0.0f, 0.0f, 3.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);

    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    drawBox();

    glFlush();

    glutSwapBuffers();
}

void resize(int w, int h)
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(grow_shrink, resize_f * w / h, resize_f, 100 * resize_f);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}

void idle(void)
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}


void mySpecialFunction(int key, int x, int y)
{
    //if (key == GLUT_KEY_F1)
    //{
        printf("U -----------> rotate clockwise\n");

        printf("Y -----------> rotate counter clockwise\n");

        printf("W or w ------> Up\n");

        printf("S or s -----> Down\n");

        printf("D or d ------> Right\n");

        printf("A or a ------> Left\n");

        printf("Z or z ------> Shrink\n");

        printf("X or x ------> Grow\n");

        printf("Escape Key ---> exit the program\n\n");
    //}
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27 :
            exit(1);
            break;
        case ‘w’:
        case 'W':
            tra_x += 0.1f;
            break;
        case 's':
        case 'S':
            tra_x -= 0.1f;
            break;

        case 'a':
        case 'A':
            tra_z -= 0.1f;
            break;

        case 'd':
        case 'D':
            tra_z += 0.1f;
            break;

        case 'u':
        case 'U':
            xrot += 1.0f;
            yrot += 1.0f;
            xdiff += 1.0f;
            ydiff += 1.0f;
            break;

        case 'y':
        case 'Y':
            xrot -= 1.0f;
            yrot -= 1.0f;
            xdiff += 1.0f;
            ydiff += 1.0f;
            break;

        case 'h':
        case 'H':
            mySpecialFunction(key, x, y);
            break;
        case 'Z':
        case 'z':
            grow_shrink--;
            resize(500, 500);
           
            break;
        case 'X':
        case 'x':
            grow_shrink++;
            resize(500, 500);
           
            break;

    }

   
    glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_F1)
    {
        fullscreen = !fullscreen;

        if (fullscreen)

            glutFullScreen();

        else

        {
            glutReshapeWindow(500, 500);

            glutPositionWindow(50, 50);
        }
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = 1;

        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = 0;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowPosition(50, 50);

    glutInitWindowSize(500, 500);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("13 - Solid Shapes");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutSpecialFunc(specialKeyboard);

    glutMouseFunc(mouse);

    glutMotionFunc(mouseMotion);

    glutReshapeFunc(resize);

    //glutIdleFunc(idle);

    if (!init())
        return 1;

    glutMainLoop();

    return 0;
}




