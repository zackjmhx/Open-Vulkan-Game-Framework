#include "structs\queries\ovgfStructsQueriesVersion.h"
#include <vulkan\vulkan.hpp>

namespace os = ovgf::structs;

uint32_t os::queries::queryVersionNumber(Version ver) {

	if (ver.versionMajor == '1' && ver.versionMinor == '0') {
		return VK_API_VERSION_1_0;
	} else {
		return -1; //Invalid version is just a validation problem
	}
}