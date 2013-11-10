#include <GL/glut.h>

GLfloat win;
GLfloat win2;

void DesenhaQuadro(void){
	
	glColor3f(0.0,0.0,0.0);
     glBegin(GL_QUADS);
         glVertex2f(-1.0,1.0);
         glVertex2f(1.0,1.0);
         glVertex2f(1.0,-1.0);
         glVertex2f(-1.0,-1.0);
     glEnd();


     glColor3f(1.0,1.0,1.0);
     glBegin(GL_QUADS);
         glVertex2f(-0.6,0.2);
         glVertex2f(-0.6,-0.6);
         glVertex2f(0.6,-0.6);
         glVertex2f(0.6,0.2);
     glEnd();
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_TRIANGLES);
         glVertex2f(-0.7,0.2);
         glVertex2f(0.7,0.2);
         glVertex2f(0,0.7);
     glEnd();
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_QUADS);
         glVertex2f(-0.1,-0.6);
         glVertex2f(-0.1,-0.2);
         glVertex2f(0.1,-0.2);
         glVertex2f(0.1,-0.6);
     glEnd();
     glFlush();
}

void Desenha (void){

 //LIMPA A JANELA APENAS UMA VEZ 
     glClear(GL_COLOR_BUFFER_BIT);
     //SELECIONA DETALHE CENTRAL
     gluOrtho2D(-0.6,0.6,-0.6,0.6);
     //APRESENTA EM TAMANHO ATUAL ALINHADO NO CATO INF ESQ
     glViewport(0,0,400,400);
     //DESENHA
     DesenhaQuadro();
     //MUDA A SELEÇÃO - TODO DESENHO (25%) E ENTORNO
     gluOrtho2D(-4.0,4.0,-4.0,4.0);
     //APRESENTA A 120 DO CANTO INF ESQ E NO TAMANHO ATUAL
     glViewport(120,120,400,400);
      //DESENHA NOVAMENTE O QUADRO SELECIONADO PELA ORTHO2D
     DesenhaQuadro();
     glFlush();
} 


void Inicializa (void)
{
       glClearColor(0.0,0.0,0.0,0.0);       
}



int main(void)
{
	glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teste");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutMainLoop();

}

