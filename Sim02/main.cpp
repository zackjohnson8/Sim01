#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <queue>
#include "ConfigFile.h"
#include "MetaDataFile.h"
#include "MemoryFunction.h"
#include "PCBObj.h"

void handleMetaData(int, ConfigFile*, MetaDataFile*, PCBObj*);


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

        ConfigFile_p[index - 1].loadConfigFile(argv[index]);

        // config file has been read and logged
        if(MetaDataFile_p[index - 1].loadMetaData(ConfigFile_p[index - 1].getTestPath()) == 0)
        {

            // good

        }else
        {

            // ERROR
            std::cout << "ERROR: MetaDataFile returned an error, fix and re-run the program." << std::endl;
            return 0;
        }

        // take data from meta class and add to PCBObj so that it can handle all the work

    }


    // Data from meta file has now been queued up and is ready to receive.
    handleMetaData(argc, ConfigFile_p, MetaDataFile_p, PCBObj_p);

    // All the data has been loaded into the pcb above and the tasks now need to run.


}

void handleMetaData(int numOfFiles, ConfigFile* ConfigFile_p, MetaDataFile* MetaDataFile_p, PCBObj* PCBObj_p)
{


    // Basically, do the same thing as before by poping out all the data.

    std::queue<metaTask> *metaData;
    PCBTask* newTask;

    for(int index = 0; index < numOfFiles - 1; index++)
    {

        // get the meta data for tasks/processes. Continue to log to the file and monitor if asked.
        // the difference is that we won't be multiplying the data but using the new example output
        metaData = MetaDataFile_p[index].getQueue();
        ConfigFile_p[index].outputLog();

        // TODO so remove all the multiplication in this form

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

                    newTask = new PCBTask();
                    newTask->taskState_p = NEW;
                    newTask->metaDataCode = metaData->front().metaDataCode;
                    newTask->description = metaData->front().description;
                    newTask->numberCycles = metaData->front().numberCycles;
                    newTask->timeTask = ConfigFile_p[index].getTimeProcessor();

                    PCBObj_p->addTask(newTask);

                    break;

                case 'I':

                    newTask = new PCBTask();
                    newTask->taskState_p = NEW;
                    newTask->metaDataCode = metaData->front().metaDataCode;
                    newTask->description = metaData->front().description;
                    newTask->numberCycles = metaData->front().numberCycles;


                    if( (metaData->front().description == "hard drive") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeHardDrive();
                        PCBObj_p->addTask(newTask);

                    }else
                    if( (metaData->front().description == "keyboard") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeKeyboard();
                        PCBObj_p->addTask(newTask);


                    }else
                    if( (metaData->front().description == "mouse") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeMouse();
                        PCBObj_p->addTask(newTask);


                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;
                        delete newTask;


                    }

                    break;

                case 'O':
                    newTask = new PCBTask();
                    newTask->taskState_p = NEW;
                    newTask->metaDataCode = metaData->front().metaDataCode;
                    newTask->description = metaData->front().description;
                    newTask->numberCycles = metaData->front().numberCycles;

                    if( (metaData->front().description == "hard drive") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeHardDrive();
                        PCBObj_p->addTask(newTask);

                    }else
                    if( (metaData->front().description == "monitor") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeMonitor();
                        PCBObj_p->addTask(newTask);

                    }else
                    if( (metaData->front().description == "speaker") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeSpeaker();
                        PCBObj_p->addTask(newTask);

                    }else
                    if( (metaData->front().description == "printer"))
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimePrinter();
                        PCBObj_p->addTask(newTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;
                        delete newTask;



                    }

                    break;

                case 'M':
                    newTask = new PCBTask();
                    newTask->taskState_p = NEW;
                    newTask->metaDataCode = metaData->front().metaDataCode;
                    newTask->description = metaData->front().description;
                    newTask->numberCycles = metaData->front().numberCycles;

                    if( (metaData->front().description == "block") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeMemory();
                        PCBObj_p->addTask(newTask);

                    }else
                    if( (metaData->front().description == "allocate") )
                    {

                        newTask->timeTask = ConfigFile_p[index].getTimeMemory();
                        PCBObj_p->addTask(newTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;
                        delete newTask;

                    }

                    break;

                default:
                    std::cout << "ERROR: metaDataCode isn't matching up correctly and can't run the task" << std::endl;

            }

            metaData->pop();

        }

        // TODO
        // Now that the pcb has taken in the tasks you'll need to run it before the next config file
        // tasks

        std::cout << std::endl << std::endl;


    }

    //newTask = new PCBTask();


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

    The project needs a pcb that handles the key components                         DONE
    NEW, WAITING, READY, RUNNING, TERMINATE.

    Allocate memory with the function provided in MemoryFunction.c.
    You'll call the function with the correct about of kbytes but may need
    to convert the data before sending. This may mean converting gb and mb to kb

    Fix ConfigFile to take in the memory line which has been added.

    Use the threads for I/O inputs and the wait for everything else.
*/
