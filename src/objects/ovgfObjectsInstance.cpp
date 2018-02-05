#include "objects\ovgfObjectsInstance.hpp"
#include "structs\ovgfStructsQueues.hpp"
#include "structs\ovgfStructsInstanceUtils.hpp"





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


namespace osIU = ::ovgf::structs;

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
			structs::InstanceUtilities iu;

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

		};

		void Instance::launch() {
			pInstanceImpl->launch();
		}

		void Instance::InstanceImpl::launch() {
			

			while (!glfwWindowShouldClose(window)) {

				glfwPollEvents();

				iu.frameCount();
				
			}
		}



		Instance::Instance(std::string name, int wWidth, int wHeight) : pInstanceImpl(spimpl::make_unique_impl<InstanceImpl>(name, wWidth, wHeight)) {

		}

		Instance::InstanceImpl::InstanceImpl(std::string name, int wWidth, int wHeight) {

			iu.getWindow(&window, name, wWidth, wHeight, onWindowResize, key_callback);


			VkApplicationInfo appInfo = iu.createStructAppInfo(name, { 1, 0, 0 }, "Null", { 1, 0, 0 }, { 1, 0, 0 }); // eventually fill this in from ini files

			auto extention = iu.getRequiredExtentions(enableValidationLayers);

			iu.createVkInstance(appInfo, nullptr, &instance, extention, enableValidationLayers, validationLayers);

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
			//Default key event handling function - closes when esc is pressed
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		}


		

	}
}