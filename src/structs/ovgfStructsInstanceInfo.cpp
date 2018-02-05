#include "structs\ovgfStructsInstanceInfo.hpp"
#include "structs\queries\ovgfStructsQueriesVersion.hpp"
#include <vulkan\vulkan.h>

namespace ovgf{
	namespace structs {

		VkApplicationInfo createStructAppInfo(std::string name, Version appVer, std::string engineName, Version engineVer, Version apiVer) {
			VkApplicationInfo appInfo = {};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pApplicationName = name.c_str();
			appInfo.applicationVersion = VK_MAKE_VERSION(appVer.versionMajor, appVer.versionMinor, appVer.versionPatch);
			appInfo.pEngineName = engineName.c_str();
			appInfo.engineVersion = VK_MAKE_VERSION(engineVer.versionMajor, engineVer.versionMinor, engineVer.versionPatch);
			appInfo.apiVersion = queries::queryVersionNumber(apiVer);

			return appInfo;
		}
	}
}