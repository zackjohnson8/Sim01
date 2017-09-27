#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <queue>
#include "ConfigFile.h"
#include "MetaDataFile.h"
#include "MemoryFunction.h"
#include "PCBObj.h"

void handleMetaData(int numOfFiles, ConfigFile* ConfigFile_p, MetaDataFile* MetaDataFile_p);


int main(int argc, char* argv[])
{

    // The program will be given a specific amount of configure files
    // Parameters for config files
    ConfigFile* ConfigFile_p;
    ConfigFile_p = new ConfigFile[argc-1];
    MetaDataFile* MetaDataFile_p;
    MetaDataFile_p = new MetaDataFile[argc-1];
    PCBObj* PCBObj_p = new PCBObj();

    for(int index = 1; index < argc; index++)
    {

        ConfigFile_p[index-1].loadConfigFile(argv[index]);

    }



    // config file has been read and logged

    for(int index = 0; index < argc - 1; index++)
    {

        if(MetaDataFile_p[index].loadMetaData(ConfigFile_p[index].getTestPath()) == 0)
        {

            // good

        }else
        {

            // ERROR
            std::cout << "ERROR: MetaDataFile returned an error, fix and re-run the program." << std::endl;
            return 0;
        }

    }

    // Data from meta file has now been queued up and is ready to receive.
    handleMetaData(argc, ConfigFile_p, MetaDataFile_p);



    delete[] ConfigFile_p;
}

void handleMetaData(int numOfFiles, ConfigFile* ConfigFile_p, MetaDataFile* MetaDataFile_p)
{




/*

    std::queue<metaTask> *metaData;

    for(int index = 0; index < numOfFiles - 1; index++)
    {

        metaData = MetaDataFile_p[index].getQueue();
        ConfigFile_p[index].outputLog();

        while(!metaData->empty())
        {


            switch(metaData->front().metaDataCode)
            {

                case 'S':
                    // Also just start and end
                    break;

                case 'A':
                    // Just starts and ends with no need to process yet
                    break;

                case 'P':
                    std::cout << metaData->front().metaDataCode << '(' << metaData->front().description << ')' <<
                    metaData->front().numberCycles << " = ";

                    std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeProcessor() << std::endl;
                    break;

                case 'I':
                    std::cout << metaData->front().metaDataCode << '(' << metaData->front().description << ')' <<
                    metaData->front().numberCycles << " = ";

                    if( (metaData->front().description == "hard drive") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeHardDrive() << std::endl;

                    }else
                    if( (metaData->front().description == "keyboard") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeKeyboard() << std::endl;


                    }else
                    if( (metaData->front().description == "mouse") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeMouse() << std::endl;

                    }else
                    {

                        // ERROR

                    }

                    break;

                case 'O':
                    std::cout << metaData->front().metaDataCode << '(' << metaData->front().description << ')' <<
                    metaData->front().numberCycles << " = ";

                    if( (metaData->front().description == "hard drive") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeHardDrive() << std::endl;

                    }else
                    if( (metaData->front().description == "monitor") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeMonitor() << std::endl;

                    }else
                    if( (metaData->front().description == "speaker") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeSpeaker() << std::endl;

                    }else
                    if( (metaData->front().description == "printer"))
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimePrinter() << std::endl;

                    }else
                    {

                        // ERROR


                    }

                    break;

                case 'M':
                    std::cout << metaData->front().metaDataCode << '(' << metaData->front().description << ')' <<
                    metaData->front().numberCycles << " = ";

                    if( (metaData->front().description == "block") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeMemory() << std::endl;

                    }else
                    if( (metaData->front().description == "allocate") )
                    {

                        std::cout << metaData->front().numberCycles * ConfigFile_p[index].getTimeMemory() << std::endl;

                    }else
                    {

                        // ERROR

                    }

                    break;

                default:
                    std::cout << "ERROR: metaDataCode isn't matching up correctly and can't run the task" << std::endl;

            }

            metaData->pop();

        }

        std::cout << std::endl << std::endl;


    }

*/
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

/*

    Project 2 Notes:

    The project needs a pcb that handles the key components
    NEW, WAITING, READY, RUNNING, TERMINATE.

    Allocate memory with the function provided in MemoryFunction.c.
    You'll call the function with the correct about of kbytes but may need
    to convert the data before sending. This may mean converting gb and mb to kb

    Fix ConfigFile to take in the memory line which has been added.

    Use the threads for I/O inputs and the wait for everything else.
*/
