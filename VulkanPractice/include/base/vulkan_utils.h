#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <base/const.h>
#include <memory>
#include <vector>
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
		~Window();
	private:
		GLFWwindow* m_window;
		uint32_t m_width;
		uint32_t m_height;
	};

	class VkInstanceWrapper {
	private:
		VkInstance m_instance;
		VkInstanceCreateInfo m_createInfo{};

	public:
		VkInstanceWrapper();
		void init();
		VkApplicationInfo * initAppInfo();
		void initExtensions();
		bool checkExtensions();
		void initValidationLayers();
		bool checkValidationLayers();
		~VkInstanceWrapper();
	};
}