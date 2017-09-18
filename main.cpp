#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <queue>
#include "FileHandler.h"
#include "ConfigFile.h"
#include "MetaDataFile.h"


int main(int argc, char* argv[])
{


    // The program will be given a specific amount of configure files
    // Parameters for config files
    ConfigFile* ConfigFile_p;
    ConfigFile_p = new ConfigFile[argc-1];
    MetaDataFile* MetaDataFile_p;
    MetaDataFile_p = new MetaDataFile[argc-1];

    for(int index = 1; index < argc; index++)
    {

        ConfigFile_p[index-1].loadConfigFile(argv[index]);

    }

    std::cout << std::endl << std::endl << std::endl;

    // config file has been read and logged

    for(int index = 0; index < argc - 1; index++)
    {

        if(MetaDataFile_p[index].loadMetaData(ConfigFile_p[index].getTestPath()) == 0)
        {

            // good
            std::cout << "GOOD" << std::endl;

        }else
        {

            // TODO BROKEN

        }

    }

    // Data from meta file has now been queued up and is ready to receive.

    std::queue<metaTask> *metaData;

    metaData = MetaDataFile_p[0].getQueue();

    std::cout << metaData->front().metaDataCode << std::endl;



    delete[] ConfigFile_p;
}

/*

    RUN THE PROGRAM WITH
    ./sim01 config_1.conf config_2.conf config_3.conf

    SELF NOTES:

    CONFIG FILE / META DATA HANDLING
    Read in the data from the config file. Once we've had that
    written we can then extract the data that will run based on the config file.

    Config files can have the same test file? Either way I can just take the
    data for each file and use it with the config file.

    Both the config file parameter and meta data parameter arrays should have
    the same position. This position can be easily used to keep track of
    which config file belongs to each meta data file.

    The MetaDataFile class will probably just return a set of data in queue
    form so that it can be manipulated.

    //////////////////////////////////////////



*/
