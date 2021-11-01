#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void) {

	GLFWwindow* window;
	//initialize the library

	if (!glfwInit())
	{
		return -1;
	}
	//create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(640, 480, "Happy Coders!", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	//Make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, 640, 480);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 0, 480, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat polygonVertices[] = {
	 80, 60, 0,
	 240, 60, 0,
	 150,  375, 0,
	 300,50,0,

	};



	//Loop until the user closes the window
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		//render openGL here
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, polygonVertices);
		glDrawArrays(GL_POLYGON, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
		//swap front and back buffers
		glfwSwapBuffers(window);
		//poll for and process events
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;

}
