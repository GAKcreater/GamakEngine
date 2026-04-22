#include "path.hpp"

#include <filesystem>

std::string
Path::path() noexcept
{
    // Getting the current working directory
    std::filesystem::path current = std::filesystem::current_path();
    
    // Search upwards until we find the "resources" directory
    while (!std::filesystem::exists(current / "resources") && current.has_parent_path())
    {
        current = current.parent_path();
    }
    
    try
    {
        return current.string() + "/";
    }
    catch (...)
    {
        return "./";
    }
}