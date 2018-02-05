#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_STRUCTS_INSTANCE_UTILS_HPP
#define OVGF_STRUCTS_INSTANCE_UTILS_HPP
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>

#include <vulkan\vulkan.hpp>
#include <GLFW\glfw3.h>

#include "structs\queries\ovgfStructsQueriesVersion.hpp"

namespace sc = ::std::chrono;
using sc::seconds;

namespace ovgf {
	namespace structs {
		struct InstanceUtilities {
			//Organizational structure to hold static utility functions

			static void getWindow(GLFWwindow **window, std::string name, int wWidth, int wHeight, GLFWwindowsizefun resizeCB, GLFWkeyfun keyCB) {
				if (!glfwInit())
					throw std::runtime_error("Failed to init GLFW");


				glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
				glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //turn off resizeability for now

				*window = glfwCreateWindow(wWidth, wHeight, name.c_str(), nullptr, nullptr);


				//glfwSetWindowUserPointer(window, this);
				glfwSetWindowSizeCallback(*window, resizeCB);

				glfwSetKeyCallback(*window, keyCB);
			}

			static std::vector<const char*> getRequiredExtentions(bool validation) {
				//get the vulkan extensions and the debug callback if debug mode is active
				uint32_t glfwExtentionCount = 0;
				const char **glfwExtentions;

				glfwExtentions = glfwGetRequiredInstanceExtensions(&glfwExtentionCount);

				std::vector<const char*> extentions(glfwExtentions, glfwExtentions + glfwExtentionCount);

				if (validation)
					extentions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);


				return extentions;
			}

			static VkApplicationInfo createStructAppInfo(std::string name, structs::Version appVer, std::string engineName, structs::Version engineVer, structs::Version apiVer) {
				VkApplicationInfo appInfo = {};
				appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
				appInfo.pApplicationName = name.c_str();
				appInfo.applicationVersion = VK_MAKE_VERSION(appVer.versionMajor, appVer.versionMinor, appVer.versionPatch);
				appInfo.pEngineName = engineName.c_str();
				appInfo.engineVersion = VK_MAKE_VERSION(engineVer.versionMajor, engineVer.versionMinor, engineVer.versionPatch);
				appInfo.apiVersion = structs::queries::queryVersionNumber(apiVer);

				return appInfo;
			}

			static void createVkInstance(
				VkApplicationInfo appInfo, VkAllocationCallbacks *custAllocator, VkInstance *instance,
				std::vector<const char*> extentions,
				bool validation, std::vector<const char*> validationLayers) {

				VkInstanceCreateInfo createInfo = {};
				createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
				createInfo.pApplicationInfo = &appInfo;



				createInfo.enabledExtensionCount = static_cast<uint32_t>(extentions.size());
				createInfo.ppEnabledExtensionNames = extentions.data();

				if (validation) {
					createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
					createInfo.ppEnabledLayerNames = validationLayers.data();
				} else {
					createInfo.enabledLayerCount = 0;
					createInfo.ppEnabledLayerNames = nullptr;
				}

				if (vkCreateInstance(&createInfo, custAllocator, instance) != VK_SUCCESS)
					throw std::runtime_error("Failed to create instance!");
			}

			static void frameCount() {
				static auto times = sc::high_resolution_clock::now();
				static uint32_t frames = 0;
				
				frames++;

				if ((sc::high_resolution_clock::now() - times) >= seconds{ 1 }) {
					::std::cout << "Current FPS: " << frames << ::std::endl;
					frames = 0;
					times = ::std::chrono::high_resolution_clock::now();
				}
			}
		};

	};
}
#endif // !OVGF_STRUCT_APP_INFO_H
