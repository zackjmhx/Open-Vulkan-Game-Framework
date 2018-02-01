#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_STRUCT_APP_INFO_H
#define OVGF_STRUCT_APP_INFO_H
#include <stdint.h>
#include <string>
#include "structs\ovgfStructsVersion.h"
struct VkApplicationInfo;

namespace ovgf {
	namespace structs {

		static VkApplicationInfo createStructAppInfo(std::string name, Version appVer, std::string engineName, Version engineVer, Version apiVer);

	};
}
#endif // !OVGF_STRUCT_APP_INFO_H
