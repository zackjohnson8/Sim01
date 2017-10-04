#ifndef PCBOBJ_CPP
#define PCBOBJ_CPP

#include "PCBObj.h"
#include <string>
#include <iostream>
#include <cstdlib>

// constructor/destructor -------------------------------------------------
PCBObj::PCBObj()
{

    _pcbNewTasks = new std::queue<PCBTask>();

}

PCBObj::~PCBObj()
{

    delete _pcbNewTasks;

}

void PCBObj::addTask(PCBTask* T)
{

    T->taskState_p = READY;
    _pcbNewTasks->push(*T);

/* holding code just incase

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

            */

}

#endif































