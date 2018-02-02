#if _pragma_once_support
	#pragma once
#endif
/* For now we're relying on GLFW for window abstraction.*/

#ifndef OVGF_OBJECT_WINDOW_H
#define OVGF_OBJECT_WINDOW_H
#include <string>

struct GLFWwindow;

namespace ovgf {
	namespace objects {

		class Window {
		public:
			GLFWwindow* getWindow(int width, int height);
			GLFWwindow* getWindow();

			Window();

		private:

			void initWindow(std::string name, int width, int height);

			static void onWindowResize(GLFWwindow *window, int width, int height);

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

			GLFWwindow *window = nullptr;

			int width;
			int height;
		};
	}
}
#endif