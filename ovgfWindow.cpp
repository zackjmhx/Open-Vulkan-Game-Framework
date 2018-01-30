/* Function definitions for current GLFW options*/
#include "ovgfWindow.h"
#include <stdexcept>


GLFWwindow* OvgfWindow::getOvgfWindow(int width, int height) {
	if (OvgfWindow::window != nullptr) return window; //if we have a window, do not try and reinitialize - game window should be singleton

	OvgfWindow(width, height);

	return window;
}

GLFWwindow* OvgfWindow::getOvgfWindow() {
	//use this overload primarily to get an already created window - will use default initalizers otherwise
	if (window != nullptr) return window; //if we have a window, do not try and reinitialize - game window should be singleton

	OvgfWindow(); //just use defaults 

	return window;
}



OvgfWindow::OvgfWindow(int width, int height) {
	initWindow(width, height);
}

OvgfWindow::OvgfWindow() {
	initWindow(800, 600);
}

void OvgfWindow::initWindow(int width, int height) {

	if (!glfwInit())
		throw std::runtime_error("Failed to init GLFW");


	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //turn off resizeability for now

	window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);

	//glfwSetWindowUserPointer(window, this);
	glfwSetWindowSizeCallback(window, onWindowResize);

}

void OvgfWindow::onWindowResize(GLFWwindow *window, int width, int height) {
	if (width == 0 || height == 0) return;

	/*
	TriangleBasicsApp *app = reinterpret_cast<TriangleBasicsApp *>(glfwGetWindowUserPointer(window));
	app->recreateSwapchain();
	Need to determine who should properly own the swap chain before implmenting this. Eventually the main purpose of this function will be overloading for custom resize code.

	It might just be easiest to disallow window resizing. Most games do.
	*/

}

void OvgfWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
