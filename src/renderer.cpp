/*#include <GL/glut.h>

// TODO: variable window size? fullscreen?
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();

	glutSwapBuffers();
}

void initialize(int argc, char *argv[]) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Tritris");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();

}
*/
