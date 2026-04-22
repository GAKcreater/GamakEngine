#include <iostream>
#include <exception>

#include "core/core.hpp"
#include "domain/path.hpp"

int main()
{
    try
    {
        std::cout << "Starting application..." << std::endl;
        std::cout << "Resource Path being used: " << Path::path() << std::endl;
        Core app;
        app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown Fatal Error occurred!" << std::endl;
    }

    std::cout << "Press ENTER to exit..." << std::endl;
    std::cin.get();
    return 0;
}