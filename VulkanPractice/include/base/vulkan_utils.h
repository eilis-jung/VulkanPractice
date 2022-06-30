#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <base/const.h>
#include <memory>
#include <vector>
#include <optional>
#include <iostream>

namespace VkPractice {

	class Window {
	public:
		Window() :
			m_width(VkPractice::WIN_INITIAL_WIDTH),
			m_height(VkPractice::WIN_INITIAL_HEIGHT),
			m_window(nullptr) {
		}
		bool init();
		void loop();
		GLFWwindow* getPointer() {
			return m_window;
		}
		~Window();
	private:
		GLFWwindow* m_window;
		uint32_t m_width;
		uint32_t m_height;
	};

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;

		bool isComplete() {
			return graphicsFamily.has_value();
		}
	};

	class VkInstanceWrapper {
	private:
		VkInstance m_instance;
		VkInstanceCreateInfo m_createInfo{};
		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
		VkDevice m_logicalDevice;
		VkQueue m_graphicsQueue;
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