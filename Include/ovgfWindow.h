#if _pragma_once_support
	#pragma once
#endif
/* For now we're relying on GLFW for window abstraction.*/
#define GLFW_INCLUDE_VULKAN //Turn on glfw vulkan support
#include <GLFW\glfw3.h>

class OvgfWindow {
public:
	GLFWwindow* getOvgfWindow(int width, int height);
	GLFWwindow* OvgfWindow::getOvgfWindow();
#ifndef OVGF_WINDOW_H
#define OVGF_WINDOW_H

	OvgfWindow();

private:
	OvgfWindow(int width, int height);

	void initWindow(int width, int height);

	static void onWindowResize(GLFWwindow *window, int width, int height);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	GLFWwindow *window;

	int width;
	int height;
};
#endif