#if _pragma_once_support
#pragma once
#endif
/* For now we're relying on GLFW for window abstraction.*/

#ifndef OVGF_OBJECT_INSTANCE_HPP
#define OVGF_OBJECT_INSTANCE_HPP
#include <string>
#include <spimpl.h>

namespace ovgf {

	namespace objects {

		class Instance {
		public:
			Instance(std::string name, int wWidth, int wHeight);

			void launch();

		private:
			struct InstanceImpl;
			spimpl::unique_impl_ptr<InstanceImpl> pInstanceImpl;
		};
		
	}
}
#endif