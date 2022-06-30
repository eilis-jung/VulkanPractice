#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <optional>
#include <set>
#include <iostream>

#include <base/const.h>
#include <base/window.h>

namespace VkPractice {
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	class VkInstanceWrapper {
	private:
		VkInstance m_instance;
		VkInstanceCreateInfo m_createInfo{};
		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
		VkDevice m_logicalDevice;
		VkQueue m_graphicsQueue;
		VkQueue m_presentQueue;
		VkSurfaceKHR m_surface;

		// AppInfo setup
		VkApplicationInfo* initAppInfo();

		// Extensions setup
		void initExtensions();
		bool checkExtensions();

		// Validation layers setup
		void initValidationLayers();
		bool checkValidationLayers();

		// Queues
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice& device);

		// Devices setup
		void setupPhysicalDevice();
		bool checkPhysicalDevice(VkPhysicalDevice & device);
		void setupLogicalDevice();

		// Window surface setup
		void setupWindowSurface(Window & window);


	public:
		VkInstanceWrapper();
		void init(Window& window);
		~VkInstanceWrapper();
	};
}