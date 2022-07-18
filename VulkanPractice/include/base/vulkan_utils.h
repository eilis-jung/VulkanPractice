#pragma once
#define NOMINMAX // For using max() in numeric_limits
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <optional>
#include <set>
#include <iostream>
#include <limits>
#include <algorithm>

#include <base/const.h>
#include <base/window.h>

// Shaders
#include <shaders/shader_vert.h>
#include <shaders/shader_frag.h>


namespace VkPractice {
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class VkUtils {
	public:
		static VkShaderModule createShaderModule(VkDevice & device, const std::vector<unsigned char>& shader_code);
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

		VkSwapchainKHR m_swapChain;
		std::vector<VkImage> m_swapChainImages;
		std::vector<VkImageView> m_swapChainImageViews;
		VkFormat m_swapChainImageFormat;
		VkExtent2D m_swapChainExtent;

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

		// Swapchain setup
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice & device);
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, Window& window);
		void setupSwapChain(Window& window);

		// ImageView setup
		void setupImageViews();

		// Pipeline setup
		void createShaders();
		void setupFixedFunctions();

	public:
		VkInstanceWrapper();
		void init(Window& window);
		~VkInstanceWrapper();
	};
}