#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_STRUCTS_VERSION_H
#define OVGF_STRUCTS_VERSION_H
#include <stdint.h>

namespace ovgf {
	namespace structs {
		struct Version {
			uint32_t versionMajor;
			uint32_t versionMinor;
			uint32_t versionPatch;
		};
	};
}
#endif // !OVGF_STRUCT_APP_INFO_H
