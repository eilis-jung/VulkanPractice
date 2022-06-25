#include <base/vulkan_utils.h>

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

VkPractice::VkInstanceWrapper::VkInstanceWrapper() {

}

void VkPractice::VkInstanceWrapper::init()
{
    m_createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    m_createInfo.pApplicationInfo = initAppInfo();

    initExtensions();
    initValidationLayers();

    if (vkCreateInstance(&m_createInfo, nullptr, &m_instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}

VkApplicationInfo* VkPractice::VkInstanceWrapper::initAppInfo()
{
    VkApplicationInfo * appInfo = new VkApplicationInfo{};
    appInfo->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo->pApplicationName = "Hello Triangle";
    appInfo->applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo->pEngineName = "No Engine";
    appInfo->engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo->apiVersion = VK_API_VERSION_1_0;
    return appInfo;
}

void VkPractice::VkInstanceWrapper::initExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);


    if (!checkExtensions()) {
        throw std::runtime_error("Extensions requested, but not available!");
    }

    m_createInfo.enabledExtensionCount = glfwExtensionCount;
    m_createInfo.ppEnabledExtensionNames = glfwExtensions;

}

bool VkPractice::VkInstanceWrapper::checkExtensions()
{
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    std::cout << "available extensions:\n";

    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }
    return true;
}

void VkPractice::VkInstanceWrapper::initValidationLayers()
{
#ifdef NDEBUG
    bool enableValidationLayers = false;
#else
    bool enableValidationLayers = true;
#endif
    
    const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
    };

    if (enableValidationLayers && !checkValidationLayers()) {
        std::cout << "validation layers requested, but not available!" << std::endl;
        enableValidationLayers = false;
    }

    if (enableValidationLayers) {
        m_createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        m_createInfo.ppEnabledLayerNames = validationLayers.data();
    }
    else {
        m_createInfo.enabledLayerCount = 0;
    }

}

bool VkPractice::VkInstanceWrapper::checkValidationLayers()
{
    const std::vector<std::string> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };
    uint32_t layerCount = 0;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const std::string & layerName : validationLayers) {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers) {
            if (layerName == layerProperties.layerName) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            return false;
        }
    }

    return true;
}

VkPractice::VkInstanceWrapper::~VkInstanceWrapper()
{
    vkDestroyInstance(m_instance, nullptr);
    delete m_createInfo.pApplicationInfo;
}
