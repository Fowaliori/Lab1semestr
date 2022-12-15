#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <glut.h>
GLint Width = 1000, Height = 500;
int delay = 50;
long time0 = 0;
double X, Y, X2, Y2, X3, Y3, X4, Y4, X5, Y5, X6, Y6, X7, Y7, X8, Y8, X9, Y9, Vx, Vy, Vx2, Vy2, Ax, Ay = -0.1, Ax2, Ay2;
int Xold, Yold, Xold2, Yold2, Xold3, Yold3, Xold4, Yold4, Xold5, Yold5, Xold6, Yold6, Xold7, Yold7, Xold8, Yold8, Xold9, Yold9, R = 20;
int Xshow, Yshow, Xshow2, Yshow2, Xshow3, Yshow3, Xshow4, Yshow4, Xshow5, Yshow5, Xshow6, Yshow6, Xshow7, Yshow7, Xshow8, Yshow8, Xshow9, Yshow9;
double K1 = 0.01, K2 = 0.01;	// Коэффициент упругости и затухания
int Y0 = 250;					// Точка НЕРАСТЯНУТОЙ пружины
int XG;							// Текущая точка графика (ось времени)
int k = 0;
int o = 1;
int f = 0;
int i = 0;


void drawCircle(int x, int y, int r, int amountSegments) {
	glBegin(GL_POLYGON);				// Окружность - полигон ВРУЧНУЮ
	for (int i = 0; i < amountSegments; i++) {
		float angle = 2.0 * 3.141592653598979323846 * (float)i / (float)amountSegments;
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}



void Display(void) {
	glVertex2f(XG, Yshow);				// 
	glVertex2f(XG - 1, Yold);				// Ось X - ось времени
	glEnd();
	XG++;
	if (XG == Width) XG = Width / 10;	// Дошли до конца - в начало
		if (R < 45 && o == 1) {
			glClear(GL_COLOR_BUFFER_BIT);
			i = 0;
			glColor3ub(0, 0, 0);
			drawCircle(Xshow, k, R, 50);
			drawCircle(Xshow2, k, R, 50);
			k += 10;
			drawCircle(Xshow3, Yshow3, R, 50);
			drawCircle(Xshow4, Yshow4, R, 50);
			drawCircle(Xshow5, Yshow5, R, 50);
			drawCircle(Xshow6, Yshow6, R, 50);
			drawCircle(Xshow7, Yshow7, R, 50);
			glColor3ub(255, 0, 0);
			drawCircle(Xold, 0+k, R, 50);
			drawCircle(Xold2, 0+k, R, 50);
			Xshow = Xold; Yshow = Yold;
			Xshow2 = Xold2; Yshow2 = Yold2;
			if (R<45)
			R++;
			f = k;
			//printf("%d\n", f);
		}
		else {
			o = 0;
			printf("%d\n", f);
			if (i == 35) {
				o = 1;
			}
			glColor3ub(0, 0, 0);
			drawCircle(Xshow, k, R, 50);
			drawCircle(Xshow2, k, R, 50);
			glColor3ub(0, 0, 0);
			R = 10;
			drawCircle(Xshow8, Yshow8, R, 50);
			drawCircle(Xshow9, Yshow9, R, 50);
			drawCircle(Xshow3, Yshow3, R, 50);
			drawCircle(Xshow4, Yshow4, R, 50);
			drawCircle(Xshow5, Yshow5, R, 50);
			drawCircle(Xshow6, Yshow6, R, 50);
			drawCircle(Xshow7, Yshow7, R, 50);
			glColor3ub(rand()%255, rand() % 255, rand() % 255);
			drawCircle(Xold8 + (rand() % 150 - 0 + 1 + 0), f + (rand() % 130 - 0 + 1 + 0), R, 50);
			drawCircle(Xold9 + (rand() % 150 - 0 + 1 + 0), f + (rand() % 130 - 0 + 1 + 0), R, 50);
			drawCircle(Xold3 + (rand() % 150 - 0 + 1 + 0), f + (rand() % 130 - 0 + 1 + 0), R, 50);
			drawCircle(Xold4 + (rand() % 150 - 0 + 1 + 0), f + (rand() % 130 - 0 + 1 + 0), R, 50);
			//drawCircle(Xold5, f + (rand() % 100 - 0 + 1 + 0), R, 50);
			//drawCircle(Xold6, f + (rand() % 100 - 0 + 1 + 0), R, 50);
			//drawCircle(Xold7, f + (rand() % 100 - 0 + 1 + 0), R, 50);
			Xshow8 = Xold8; Yshow8 = Yold8;
			Xshow9 = Xold9; Yshow9 = Yold9;
			Xshow3 = Xold3; Yshow3 = Yold3;
			Xshow4 = Xold4; Yshow4 = Yold4;
			//Xshow5 = Xold5; Yshow5 = Yold5;
			//Xshow6 = Xold6; Yshow6 = Yold6;
			//Xshow7 = Xold7; Yshow7 = Yold7;
			i++;
			k = 0;
		}
	glFlush();
	glFinish();
}

void Reshape(GLint w, GLint h) {
	Width = w;
	Height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'
	if (key == ESCAPE)
		exit(0);
}

void Idle() {	// Задержка и ДИНАМИКА
	int k, k2;
	if (clock() - time0 < delay)
		return;
	time0 = clock();				// Ускорение пропорционально растяжению пружины
	Ay = -K1 * (Y - Y0) - K2 * Vy;	// и скорости движения (оба со знаком - )
	X += Vx;					// Интегрирование координат
	Y += Vy;
	X2 += Vx;					// Интегрирование координат
	Y2 += Vy;
	X3 += Vx;					// Интегрирование координат
	Y3 += Vy;
	X4 += Vx;					// Интегрирование координат
	Y4 += Vy;
	X5 += Vx;					// Интегрирование координат
	Y5 += Vy;
	X6 += Vx;					// Интегрирование координат
	Y6 += Vy;
	X7 += Vx;					// Интегрирование координат
	Y7 += Vy;
	X8 += Vx;					// Интегрирование координат
	Y8 += Vy;
	X9 += Vx;					// Интегрирование координат
	Y9 += Vy;
	Vx += Ax;					// Интегрирование скорости
	Vy += Ay;
	if (Vx < 0 && X <= R) Vx = -Vx;	// Отскок от краев
	if (Vx > 0 && X > Width / 2.6 - R) Vx = -Vx;
	if (Vy < 0 && Y <= R) Vy = -Vy * 0.9;
	if (Vy > 0 && Y > Height - R) Vy = -Vy;
	if ((int)X != Xold || (int)Y != Yold) {
		Xold = X+200;					// Перемещение более чем на пиксель
		Yold = Y;
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X2 != Xold2 || (int)Y2 != Yold2) {
		Xold2 = X2+600;					// Перемещение более чем на пиксель
		Yold2 = Y2;
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X3 != Xold3 || (int)Y3 != Yold3) {
		Xold3 = X3 + (rand() % 700 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold3 = Y3 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X4 != Xold4 || (int)Y4 != Yold4) {
		Xold4 = X4 + (rand() % 800 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold4 = Y4 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X5 != Xold5 || (int)Y5 != Yold5) {
		Xold5 = X5 + (rand() % 800 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold5 = Y5 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X6 != Xold6 || (int)Y6 != Yold6) {
		Xold6 = X6 + (rand() % 800 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold6 = Y6 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X7 != Xold7 || (int)Y7 != Yold7) {
		Xold7 = X7 + (rand() % 800 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold7 = Y7 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X8 != Xold8 || (int)Y8 != Yold8) {
		Xold8 = X8 + (rand() % 800 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold8 = Y8 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
	if ((int)X9 != Xold9 || (int)Y9 != Yold9) {
		Xold9 = X9 + (rand() % 800 - 0 + 1 + 0);					// Перемещение более чем на пиксель
		Yold9 = Y9 + (rand() % 440 - 150 + 1 - 50);
		glutPostRedisplay();		// Инициализировать перерисовку
	}
}



int main(int argc, char* argv[]) {
	Y0 = Height / 2;
	Vx = 0;
	int k, k2;
	Vy = 0;
	Ax = 0;
	Ay = 0;
	Ax2 = 1;
	Vy2 = 0;
	X = Xshow = Xold = Width / 20;
	Y = Yshow = Yold = Y0+ 200;
	X2 = Xshow2 = Xold2 = Width / 20;
	Y2 = Yshow2 = Yold2 = Y0 + 200;
	X3 = Xshow3 = Xold3 = Width / 20;
	Y3 = Yshow3 = Yold3 = Y0+200;
	X4 = Xshow4 = Xold4 = Width / 20;
	Y4 = Yshow4 = Yold4 = Y0+200;
	X5 = Xshow5 = Xold5 = Width / 20;
	Y5 = Yshow5 = Yold5 = Y0+200;
	X6 = Xshow6 = Xold6 = Width / 20;
	Y6= Yshow6 = Yold6 = Y0+200 ;
	X7 = Xshow7 = Xold7 = Width / 20;
	Y7 = Yshow7 = Yold7 = Y0+200;
	X8 = Xshow8 = Xold8 = Width / 20;
	Y8 = Yshow8 = Yold8 = Y0 + 200;
	X9 = Xshow9 = Xold9 = Width / 20;
	Y9 = Yshow9 = Yold9 = Y0 + 200;
	XG = Width / 10;
	time0 = clock();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Салют");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(Idle);
	glutMainLoop();

}