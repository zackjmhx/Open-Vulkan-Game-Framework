/* Function definitions for current GLFW options*/
#include "ovgfWindow.h"


class OvgfWindow {

public:



private:

	OvgfWindow(int width, int height) {
		initWindow(width, height);
	}

	GLFWwindow *window = nullptr;
	int width;
	int height;

	void initWindow(int width, int height) {

		if (!glfwInit())
			throw std::runtime_error("Failed to init GLFW");


		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //turn off resizeability for now

		window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);

		//glfwSetWindowUserPointer(window, this);
		glfwSetWindowSizeCallback(window, onWindowResize);

	}

	static void onWindowResize(GLFWwindow *window, int width, int height) {
		if (width == 0 || height == 0) return;

		/*
		TriangleBasicsApp *app = reinterpret_cast<TriangleBasicsApp *>(glfwGetWindowUserPointer(window));
		app->recreateSwapchain();

		Need to determine who should properly own the swap chain before implmenting this. Eventually the main purpose of this function will be overloading for custom resize code.

		It might just be easiest to disallow window resizing. Most games do.
		*/

	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
};