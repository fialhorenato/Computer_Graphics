#include <GL/glut.h>

GLfloat left;
GLfloat right;
GLfloat bottom;
GLfloat up;
GLfloat rotate;
GLfloat rotate2;

void DesenhaQuadro(void)
{

     glColor3f(1.0,1.0,1.0);
     glBegin(GL_QUADS);
         glVertex2f(-0.8,0.8);
         glVertex2f(0.8,0.8);
         glVertex2f(0.8,-0.8);
         glVertex2f(-0.8,-0.8);
     glEnd();
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_TRIANGLES);
         glVertex2f(-0.6,-0.6);
         glVertex2f(0.0,0.6);
         glVertex2f(0.6,-0.6);
     glEnd();
     
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POLYGON);
         glVertex2f(-0.6,-0.4);
         glVertex2f(0.0,-0.3);
         glVertex2f(0.6,-0.4);
         glVertex2f(0.6,-0.6);
         glVertex2f(-0.6,-0.6);
     glEnd();
     
     glColor3f(0.0,0.0,1.0);
     glLineWidth(2.0);  
     glBegin(GL_LINES);
         glVertex2f(-1.0,1.0);
         glVertex2f(1.0,-1.0);
     glEnd();
     glFlush();
}

void Desenha (void)

{

      glClear(GL_COLOR_BUFFER_BIT);
     glViewport(0,0,400,400);        //MUDOU A VIEW PORT (ORIGINAL)
     DesenhaQuadro();                //APENAS UM DESENHO
     glFlush();
} 



void TeclasEspeciais(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)//VERIFICA A TECLA
        {
                
                        left -= 0.2f;
                        right += 0.2f;
                
                
        }
    if (key == GLUT_KEY_RIGHT) //VERIFICA A TECLA
        {
                right -= 0.2f;
                left += 0.2f;
                
        }
         if (key == GLUT_KEY_UP) //VERIFICA A TECLA
        {
                up -= 0.2f;
                bottom += 0.2f;
        }
         if (key == GLUT_KEY_DOWN) //VERIFICA A TECLA
        {
                bottom -= 0.2f;
                up += 0.2f;
        }
        
         if (key == GLUT_KEY_PAGE_UP) //VERIFICA A TECLA
        {
                left -= 0.2f; 
                right -= 0.2f; 
                bottom -= 0.2f; 
                up -= 0.2f;
        }
        
         if (key == GLUT_KEY_PAGE_DOWN) //VERIFICA A TECLA
        {
                left += 0.2f; 
                right += 0.2f; 
                bottom += 0.2f; 
                up += 0.2f;
        }
        
         if (key == GLUT_KEY_HOME) //VERIFICA A TECLA
        {
               rotate += 1.0f;
        }
        
         if (key == GLUT_KEY_END) //VERIFICA A TECLA
        {
               rotate -= 1.0f;
        }
        
         if (key == GLUT_KEY_F1) //VERIFICA A TECLA
        {
               rotate2 += 1.0f;
        }
        
         if (key == GLUT_KEY_F2) //VERIFICA A TECLA
        {
               rotate2 -= 1.0f;
        }
        
      glMatrixMode(GL_PROJECTION); //DEFINE A MATRIZ
      glLoadIdentity();            //GRAVA A MATRIZ PADRAO
      gluOrtho2D (-left, right, -bottom, up);   //AJUSTA A MATRIZ 
      glMatrixMode(GL_MODELVIEW);         //AJUSTADA
      glLoadIdentity();                //GRAVA A MATRIZ PADRAO
      glPushMatrix();
      glTranslatef(0,-5,0);
      glRotatef(rotate,0.0,rotate2,1.0);
      glScalef(1.4,1.4,1.0);     
      glutPostRedisplay();   //REDESENHA
}




void Inicializa (void)
{
      left = 5.0; right = 5.0; bottom = 5.0; up = 5.0; rotate = 45.0; rotate2 = 0.0;      //ATRIBUI O VALOR 10 PARA A VARIAVEL WIN
       glClearColor(0.0,0.0,0.0,1.0);
       glMatrixMode(GL_PROJECTION);        //DEFINE A MATRIZ A SER   
       glMatrixMode(GL_MODELVIEW);         //AJUSTADA
       glLoadIdentity();                //GRAVA A MATRIZ PADRAO
       glPushMatrix();
       //glTranslatef(0,-5,0);
       //glRotatef(45.0,0.0,0.0,1.0);
       //glScalef(1.4,1.4,1.0);
       gluOrtho2D (-left, right, -bottom, up);        //AJUSTA A MATRIZ       
}

int main(void)
{
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teste");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutSpecialFunc(TeclasEspeciais); // REGISTRA A FUNCAO
    //CALLBACK PARA TRATAMENTO DAS TECLAS ESPECIAIS
    glutMainLoop();
}
