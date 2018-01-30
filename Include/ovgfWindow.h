/* For now we're relying on GLFW for window abstraction.*/
#ifndef OVGF_WINDOW
#define OVGF_WINDOW
#define GLFW_INCLUDE_VULKAN //Turn on glfw vulkan support
#include <GLFW\glfw3.h>

class OvgfWindow {
public:
	GLFWwindow* getOvgfWindow(int width, int height);
	GLFWwindow* OvgfWindow::getOvgfWindow();

private:
	OvgfWindow(int width, int height);

	OvgfWindow();

	

	void initWindow(int width, int height);

	static void onWindowResize(GLFWwindow *window, int width, int height);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	GLFWwindow *window = nullptr;
	int width;
	int height;
};
#endif