#if _pragma_once_support
	#pragma once
#endif
/* For now we're relying on GLFW for window abstraction.*/

#ifndef OVGF_WINDOW_H
#define OVGF_WINDOW_H

struct GLFWwindow;

namespace ovgf {
	

	class Window {
	public:
		GLFWwindow* getWindow(int width, int height);
		GLFWwindow* getWindow();

		Window();

	private:
		Window(int width, int height);

		void initWindow(int width, int height);

		static void onWindowResize(GLFWwindow *window, int width, int height);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		GLFWwindow *window;

		int width;
		int height;
	};
}
#endif