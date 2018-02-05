#include "objects\ovgfObjectsInstance.hpp"
#include "structs\ovgfStructsQueues.hpp"
#include "structs\ovgfStructsInstanceInfo.hpp"

#include <iostream>
#include <chrono>

#include <vulkan\vulkan.hpp>
#include <GLFW\glfw3.h>


//Shove this up here for now, need to move sooner than later
const std::vector<const char*> validationLayers = {

	"VK_LAYER_LUNARG_standard_validation" //use the standard lunarG validation layers

};

const std::vector<const char *> deviceExtentions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME //enable SwapChain extentions
};

#ifndef NDEBUG
const bool enableValidationLayers = true; //enable validation layers iff we're in debug mode
#else
const bool enableValidationLayers = false;
#endif // !NDEBUG

//end dump

namespace sc = ::std::chrono;
using sc::seconds;

namespace ovgf {
	namespace objects {

		class Swapchain;

		class Device;

		class Pipeline;

		class Buffer;

		class Image;

		class Pool;

		struct Instance::InstanceImpl {
		public:
			void launch();
			InstanceImpl(std::string name, int wWidth, int wHeight);

		private:
			VkInstance instance;
			GLFWwindow *window;
			Device *device; //only track a single device for now TODO: Add multi-device support
			Swapchain *swapchain;
			structs::Queues *queues;
			Pipeline *pipeline; //only use one pipeline per program for now TODO: Add support for multiple pipelines

			//TODO: uncomment as definitions are added

			//std::vector<Buffer> buffers;
			//std::vector<Image> images;
			//std::vector<Pool> pools; //Since eventually way more command pools will be needed than other pools, a vector may not be the way to go

			//TODO: Move these somewhere a user can access them for custom functionality
			static void onWindowResize(GLFWwindow *window, int width, int height);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

			std::vector<const char*> getRequiredExtentions();
		};



		void Instance::launch() {
			pInstanceImpl->launch();
		}

		void Instance::InstanceImpl::launch() {
			auto times = sc::high_resolution_clock::now();
			uint32_t frames = 0;

			while (!glfwWindowShouldClose(window)) {

				glfwPollEvents();

				frames++;

				if ((sc::high_resolution_clock::now() - times) >= seconds{ 1 }) {
					::std::cout << "Current FPS: " << frames << ::std::endl;
					frames = 0;
					times = ::std::chrono::high_resolution_clock::now();
				}
			}
		}



		Instance::Instance(std::string name, int wWidth, int wHeight) : pInstanceImpl(spimpl::make_unique_impl<InstanceImpl>(name, wWidth, wHeight)) {

		}

		Instance::InstanceImpl::InstanceImpl(std::string name, int wWidth, int wHeight) {

			if (!glfwInit())
				throw std::runtime_error("Failed to init GLFW");


			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //turn off resizeability for now

			window = glfwCreateWindow(wWidth, wHeight, name.c_str(), nullptr, nullptr);


			//glfwSetWindowUserPointer(window, this);
			glfwSetWindowSizeCallback(window, onWindowResize);

			glfwSetKeyCallback(window, key_callback);


			VkApplicationInfo appInfo = structs::createStructAppInfo(name, { 1, 0, 0 }, "Null", { 1, 0, 0 }, { 1, 0, 0 });


			VkInstanceCreateInfo createInfo = {};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			createInfo.pApplicationInfo = &appInfo;

			auto extention = getRequiredExtentions();

			createInfo.enabledExtensionCount = static_cast<uint32_t>(extention.size());
			createInfo.ppEnabledExtensionNames = extention.data();

			if (enableValidationLayers) {
				createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
				createInfo.ppEnabledLayerNames = validationLayers.data();
			} else {
				createInfo.enabledLayerCount = 0;
				createInfo.ppEnabledLayerNames = nullptr;
			}

			if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
				throw std::runtime_error("Failed to create instance!");

		}

		std::vector<const char*> Instance::InstanceImpl::getRequiredExtentions() {
			uint32_t glfwExtentionCount = 0;
			const char **glfwExtentions;

			glfwExtentions = glfwGetRequiredInstanceExtensions(&glfwExtentionCount);

			std::vector<const char*> extentions(glfwExtentions, glfwExtentions + glfwExtentionCount);

			if (enableValidationLayers)
				extentions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);


			return extentions;
		}



		void Instance::InstanceImpl::onWindowResize(GLFWwindow *window, int width, int height) {
			if (width == 0 || height == 0) return;

			/*
			TriangleBasicsApp *app = reinterpret_cast<TriangleBasicsApp *>(glfwGetWindowUserPointer(window));
			app->recreateSwapchain();
			Need to determine who should properly own the swap chain before implmenting this. Eventually the main purpose of this function will be overloading for custom resize code.

			It might just be easiest to disallow window resizing. Most games do.
			*/

		}

		void Instance::InstanceImpl::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		}


	}
}