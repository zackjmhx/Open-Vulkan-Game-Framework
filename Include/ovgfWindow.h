/* For now we're relying on GLFW for window abstraction.*/
#ifndef OVGF_WINDOW
#define OVGF_WINDOW
#define GLFW_INCLUDE_VULKAN //Turn on glfw vulkan support
#include <GLFW\glfw3.h>
#include <stdexcept>

class OvgfWindow {
public:
	GLFWwindow getOvgfWindow(int width, int height);
};#endif