#include <iostream>
#include <filesystem>
#include "json.h"

namespace fs = std::filesystem;

int configure_and_make(const std::string package)
{
    std::string file = package + ".tar.gz";

    if(fs::exists(file))
    {
        std::cout << "Configurate...\n";

        std::string command_tar = "tar -xvf " + file + " > /dev/null 2>&1"; 

        system(command_tar.c_str());

        fs::path dir = parsingJsonNameAndVersion(package);

        std::string command_conf = "cd \"" + dir.string() + "\" && ./configure > /dev/null 2>&1";

        system(command_conf.c_str());

        std::cout << "Run: Make...\n";

        std::string command_make = "cd \"" + dir.string() + "\" && make > /dev/null 2>&1";
        
        system(command_make.c_str());
    }
    else
    {
        std::cout << "File doesn't exist\n";
    }

    return 0;
}
