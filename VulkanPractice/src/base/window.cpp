#include <base/window.h>

bool VkPractice::Window::init() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(m_width, m_height, "VulkanPractice", nullptr, nullptr);

	if (m_window != nullptr) return true;
	return false;
}

void VkPractice::Window::loop() {
	while (!glfwWindowShouldClose(m_window)) {
		glfwPollEvents();
	}
}

VkPractice::Window::~Window() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
