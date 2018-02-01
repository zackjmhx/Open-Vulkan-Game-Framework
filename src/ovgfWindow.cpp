#include "ovgfWindow.h"
#include <stdexcept>
#define GLFW_INCLUDE_VULKAN //Turn on glfw vulkan support
#include <GLFW\glfw3.h>


/* Function definitions for current GLFW options*/
namespace ovgf {




	GLFWwindow* Window::getWindow(int width, int height) {
		if (Window::window != nullptr) return window; //if we have a window, do not try and reinitialize - game window should be singleton

		Window(width, height);

		return window;
	}

	GLFWwindow* Window::getWindow() {
		//use this overload primarily to get an already created window - will use default initalizers otherwise
		if (window != nullptr) return window; //if we have a window, do not try and reinitialize - game window should be singleton

		Window(); //just use defaults 

		return window;
	}



	Window::Window(int width, int height) {
		initWindow(width, height);
	}

	Window::Window() {
		initWindow(800, 600);
	}

	void Window::initWindow(int width, int height) {

		if (!glfwInit())
			throw std::runtime_error("Failed to init GLFW");


		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //turn off resizeability for now

		window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);

		//glfwSetWindowUserPointer(window, this);
		glfwSetWindowSizeCallback(window, onWindowResize);

		glfwSetKeyCallback(window, key_callback);

	}

	void Window::onWindowResize(GLFWwindow *window, int width, int height) {
		if (width == 0 || height == 0) return;

		/*
		TriangleBasicsApp *app = reinterpret_cast<TriangleBasicsApp *>(glfwGetWindowUserPointer(window));
		app->recreateSwapchain();
		Need to determine who should properly own the swap chain before implmenting this. Eventually the main purpose of this function will be overloading for custom resize code.

		It might just be easiest to disallow window resizing. Most games do.
		*/

	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}