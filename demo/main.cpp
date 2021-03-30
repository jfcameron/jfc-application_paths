// © 2021 Joseph Cameron - All Rights Reserved

#define JFC_APPLICATION_PATHS_IMPLEMENTATION
#include<jfc/application_paths.h>

#include <cstdlib>
#include <iostream>

void remove_dir_if_empty(std::filesystem::path &aPath)
{
    std::size_t count(0);
    for (auto const & file : std::filesystem::directory_iterator(aPath))
        ++count;
   
    if (!count)
    {
        std::cout << aPath.string() << " is empty. Removing.\n";

        std::filesystem::remove(aPath);
    }
}

int main(int argc, char *argv[])
{
    jfc::application_paths paths("demo_application");

    auto configpath = paths.config_dir();
    std::cout << "config path created at: " << configpath.string() << "\n";

    auto datapath = paths.data_dir();
    std::cout << "data path created at: " << datapath.string() << "\n";

    auto cachepath = paths.cache_dir();
    std::cout << "cache path created at: " << cachepath.string() << "\n";

    remove_dir_if_empty(configpath);
    remove_dir_if_empty(datapath);
    remove_dir_if_empty(cachepath);

    return EXIT_SUCCESS;
}

