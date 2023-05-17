#include "Application.h"

#include <iostream>

int main(int _argc, char* _argv[])
{
    std::cout << _argc << std::endl;

    for (int i = 0; i < _argc; i++)
    {
        std::cout << _argv[i] << std::endl;
    }

    Application app = Application();
    app.Run(_argv);

    return 0;
}