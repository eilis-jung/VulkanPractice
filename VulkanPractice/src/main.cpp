#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

#include <base/const.h>
#include <base/vulkan_utils.h>

class HelloTriangleApplication {
public:
    void run() {
        m_window.init();
        initVulkan();
        mainLoop();
    }

private:
    VkPractice::Window m_window;
    VkPractice::VkInstanceWrapper m_vkInstance;

    VkInstance instance;

    void initVulkan() {
        m_vkInstance.init();
    }

    void mainLoop() {
        m_window.loop();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}