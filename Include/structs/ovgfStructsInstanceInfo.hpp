#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_STRUCTS_INSTANCE_INFO_HPP
#define OVGF_STRUCTS_INSTANCE_INFO_HPP
#include <stdint.h>
#include <string>
#include "structs\ovgfStructsVersion.hpp"
struct VkApplicationInfo;

namespace ovgf {
	namespace structs {

		VkApplicationInfo createStructAppInfo(std::string name, Version appVer, std::string engineName, Version engineVer, Version apiVer);

	};
}
#endif // !OVGF_STRUCT_APP_INFO_H
