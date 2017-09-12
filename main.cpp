#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "FileHandler.h"
#include "ConfigFile.h"


struct metaTask
{



};

int main(int argc, char* argv[])
{


    // The program will be given a specific amount of configure files
    // Parameters for config files
    ConfigFile* ConfigFile_p;
    ConfigFile_p = new ConfigFile[argc-1];

    for(int index = 1; index < argc; index++)
    {

        ConfigFile_p[index-1].readConfigFile(argv[index]);

    }

    std::cout << std::endl << std::endl << std::endl;


    // config file has been read and logged
    // <Meta-Data code>(Description)<number of cycles>
    std::ifstream stream;
    std::string hold;

    for(int index = 0; index < argc - 1; index++)
    {

        hold = ConfigFile_p[index].getTestPath();

        //open file
        stream.open(hold.c_str());

        if(stream.good())
        {

            // read in the data


        }else
        {

            std::cout << "Test meta data file could not be reached" << std::endl;

        }

    }


    // Take _pathFile from configFile and log the data into a queue


    delete[] ConfigFile_p;
}
