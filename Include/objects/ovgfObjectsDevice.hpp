#if _pragma_once_support
#pragma once
#endif
/* For now we're relying on GLFW for window abstraction.*/

#ifndef OVGF_OBJECT_DEVICE_HPP
#define OVGF_OBJECT_DEVICE_HPP
#include <spimpl.h>

typedef struct VkInstance_t *VkInstance;

namespace ovgf {

	namespace objects {

		class Device {
		public:
			Device(VkInstance instance);

		private:
			struct DeviceImpl;
			spimpl::unique_impl_ptr<DeviceImpl> pDeviceImpl;
		};

	}
}
#endif