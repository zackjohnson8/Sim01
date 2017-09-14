#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <queue>
#include "FileHandler.h"
#include "ConfigFile.h"


int main(int argc, char* argv[])
{


    // The program will be given a specific amount of configure files
    // Parameters for config files
    ConfigFile* ConfigFile_p;
    ConfigFile_p = new ConfigFile[argc-1];

    for(int index = 1; index < argc; index++)
    {

        ConfigFile_p[index-1].loadConfigFile(argv[index]);

    }

    std::cout << std::endl << std::endl << std::endl;


    // config file has been read and logged
    // <Meta-Data code>(Description)<number of cycles>

    for(int index = 0; index < argc - 1; index++)
    {



    }


    // Take _pathFile from configFile and log the data into a queue


    delete[] ConfigFile_p;
}
