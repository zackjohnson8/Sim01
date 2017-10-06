#ifndef PCBOBJ_CPP
#define PCBOBJ_CPP

#include "PCBObj.h"
#include "MemoryFunction.h"
#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>

// constructor/destructor -------------------------------------------------
PCBObj::PCBObj()
{

    _pcbNewTasks = new std::queue<PCBTask>();
    _procNum = 0;
    _memoryAlloSize = 0;

}

PCBObj::~PCBObj()
{

    delete _pcbNewTasks;

}

void PCBObj::setProcessNum(int T)
{

    _procNum = T;

}

void PCBObj::setMemoryAlloSize(int T)
{

    _memoryAlloSize = T; // should be coming in as kilobyte already so no need to mod that

}

void PCBObj::addTask(PCBTask* T)
{

    T->taskState_p = READY;
    _pcbNewTasks->push(*T);



}

void PCBObj::runPCB()
{

    struct timeval tvEnd;
    struct timeval tvStart;
    gettimeofday(&tvStart,NULL);

    // Pull each queued PCBTask and handle each task accordingly
    while(!_pcbNewTasks->empty())
    {

        switch(_pcbNewTasks->front().metaDataCode)
        {
            //std::cout << "isthisworking" << std::endl;

                case 'S':
                    // Also just start and end
                    if( _pcbNewTasks->front().description == "start")
                    {
                        //t = time(NULL);
                        gettimeofday(&tvEnd, NULL);
                        std::cout << (((tvEnd.tv_sec - tvStart.tv_sec) * 1000000) + (tvEnd.tv_usec - tvStart.tv_usec))/1000 << " - Simulator program starting" << std::endl;
                    }else
                    if(_pcbNewTasks->front().description == "end")
                    {

                        //seconds = difftime(t,mktime(&secondTime));


                    }

                    break;

                case 'A':
                    // Using process now.


                    break;

                case 'P':


                    break;

                case 'I':


                    if( (_pcbNewTasks->front().description == "hard drive") )
                    {

                    }else
                    if( (_pcbNewTasks->front().description == "keyboard") )
                    {

                    }else
                    if( (_pcbNewTasks->front().description == "mouse") )
                    {


                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;


                    }

                    break;

                case 'O':


                    if( (_pcbNewTasks->front().description == "hard drive") )
                    {



                    }else
                    if( (_pcbNewTasks->front().description == "monitor") )
                    {



                    }else
                    if( (_pcbNewTasks->front().description == "speaker") )
                    {

                    }else
                    if( (_pcbNewTasks->front().description == "printer"))
                    {

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;
                    }

                    break;

                case 'M':


                    if( (_pcbNewTasks->front().description == "block") )
                    {

                    }else
                    if( (_pcbNewTasks->front().description == "allocate") )
                    {

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;

                    }

                    break;

                default:
                    std::cout << "ERROR: metaDataCode isn't matching up correctly and can't run the task" << std::endl;

        }

        _pcbNewTasks->pop();

    }

}

#endif


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
