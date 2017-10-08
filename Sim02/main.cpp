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
        PCBObj_p->setProcessNum(index+1);
        PCBObj_p->setLogTo(ConfigFile_p[index].getLogTo(), ConfigFile_p[index].getLogToString());

        if(ConfigFile_p->getMemoryAlloType() == KILO)
        {

            // already kilo
            PCBObj_p->setMemoryAlloSize(ConfigFile_p[index].getMemoryAlloSize());

        }else
        if(ConfigFile_p->getMemoryAlloType() == MEGA)
        {

            // convert to kilo
            PCBObj_p->setMemoryAlloSize(ConfigFile_p[index].getMemoryAlloSize()*1000);

        }else
        if(ConfigFile_p->getMemoryAlloType() == GIGA)
        {

            // convert to kilo
            PCBObj_p->setMemoryAlloSize(ConfigFile_p[index].getMemoryAlloSize()*1000*1000);


        }else
        {

            // ERROR
            std::cout << "ERROR: ConfigFiles parameter Memory type isn't returning correctly" << std::endl;

        }


        // Begin to handle all the tasks and place them into the PCB
        while(!metaData->empty())
        {


            switch(metaData->front().metaDataCode)
            {

                case 'S':
                    // Also just start and end

                    newTask = new PCBTask();
                    newTask->taskState_p = NEW;
                    newTask->metaDataCode = metaData->front().metaDataCode;
                    newTask->description = metaData->front().description;
                    newTask->numberCycles = metaData->front().numberCycles;
                    newTask->timeTask = 0;

                    PCBObj_p->addTask(newTask);

                    break;

                case 'A':
                    // Using process now.
                    newTask = new PCBTask();
                    newTask->taskState_p = NEW;
                    newTask->metaDataCode = metaData->front().metaDataCode;
                    newTask->description = metaData->front().description;
                    newTask->numberCycles = metaData->front().numberCycles;
                    newTask->timeTask = 0;

                    PCBObj_p->addTask(newTask);

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

        // Now that the pcb has taken in the tasks you'll need to run it before the next config file
        // tasks
        PCBObj_p->runPCB();

        std::cout << std::endl << std::endl;


    }

    //newTask = new PCBTask();


}
