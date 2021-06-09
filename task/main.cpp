#ifdef _WIN32
#include <windows.h> // SetConsoleOutputCP(CP_UTF8)
#endif

#include "task.h"

int main()
{
    #ifdef _WIN32
    // отображение кириллицы в консоли windows
    SetConsoleOutputCP(CP_UTF8);
    #endif

    try {
        // Тут можно задать константное зерно вместо time(0)
        Task task(time(0));
        task.demonstration();
    }
    catch (std::exception e) {
        std::cout << "Непредвиденная ошибка. " << e.what() << std::endl;
    }


    return 0;
}
