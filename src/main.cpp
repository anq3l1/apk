#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <cstdio>
#include "install.h"
#include "configure.h"

int main(int argc, char* argv[])
{
    if (argc > 1 && std::string(argv[1]) == "install")
    {
        install(argv[2]);
        configure_and_make(argv[2]);

        if(configure_and_make)
            std::cout << "Install: " << argv[2] << " succefully!\n";
    }

    return 0;
}