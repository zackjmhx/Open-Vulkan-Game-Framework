#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_STRUCTS_VERSION_QUERY_HPP
#define OVGF_STRUCTS_VERSION_QUERY_HPP
#include "structs\ovgfStructsVersion.hpp"


namespace ovgf {
	namespace structs {
		namespace queries {
			uint32_t queryVersionNumber(::ovgf::structs::Version ver);
		}
	};
}
#endif // !OVGF_STRUCT_APP_INFO_H