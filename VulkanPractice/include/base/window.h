#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <base/const.h>
#include <memory>

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
}