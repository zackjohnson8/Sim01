#ifndef PCBOBJ_CPP
#define PCBOBJ_CPP

#include "PCBObj.h"
#include "MemoryFunction.h"
#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
#include <bitset>
#include <pthread.h>

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

    int microToMilli = 1000;

    // pthread... we need a way to identify the pthread and also a variable to tell the pthread how to handle the thread
    pthread_t threadId;
    pthread_attr_t threadAttr;
    int* passVal;

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
                        // grab current time then print the difference from when this began
                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                        << " - Simulator program starting" << std::endl;

                    }else
                    if(_pcbNewTasks->front().description == "end")
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                        << " - Simulator program ending" << std::endl;

                    }

                    break;

                case 'A':
                    // Using process now.
                    if( _pcbNewTasks->front().description == "start")
                    {
                        // grab current time then print the difference from when this began
                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                        << " - OS: preparing process " << this->_procNum << std::endl;


                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                        << " - OS: starting process " << this->_procNum << std::endl;

                    }else
                    if(_pcbNewTasks->front().description == "end")
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                        << " - OS: removing process " << this->_procNum << std::endl;

                    }

                    break;

                case 'P':

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start processing action" << std::endl;

                        usleep(_pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end processing action" << std::endl;


                    break;

                case 'I':

                    // TODO THREADING~!!!

                    // Initialize the threadAttribute
                    pthread_attr_init(&threadAttr);

                    // Integer value to pass to thread
                    passVal = (int*)malloc(sizeof(*passVal));
                    *passVal = _pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask;


                    if( (_pcbNewTasks->front().description == "hard drive") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start hard drive input" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end hard drive input" << std::endl;

                    }else
                    if( (_pcbNewTasks->front().description == "keyboard") )
                    {
                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start keyboard input" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end keyboard input" << std::endl;

                    }else
                    if( (_pcbNewTasks->front().description == "mouse") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start mouse input" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start mouse input" << std::endl;

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;


                    }

                    break;

                case 'O':


                    // TODO THREADING!!!
                    // Initialize the threadAttribute
                    pthread_attr_init(&threadAttr);

                    // Integer value to pass to thread
                    passVal = (int*)malloc(sizeof(*passVal));
                    *passVal = _pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask;

                    if( (_pcbNewTasks->front().description == "hard drive") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start hard drive output" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end hard drive output" << std::endl;

                    }else
                    if( (_pcbNewTasks->front().description == "monitor") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start monitor output" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end monitor output" << std::endl;

                    }else
                    if( (_pcbNewTasks->front().description == "speaker") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start speaker output" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end speaker output" << std::endl;

                    }else
                    if( (_pcbNewTasks->front().description == "printer"))
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start printer output" << std::endl;

                        pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                        pthread_join(threadId, NULL);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end printer output" << std::endl;

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;
                    }

                    break;

                case 'M':


                    if( (_pcbNewTasks->front().description == "block") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": start memory blocking" << std::endl;

                        usleep(_pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": end memory blocking" << std::endl;

                    }else
                    if( (_pcbNewTasks->front().description == "allocate") )
                    {

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": allocating memory" << std::endl;

                        _memoryLocation = allocateMemory(_memoryAlloSize);

                        gettimeofday(&tvEnd, NULL);
                        std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                        << ": memory allocated at 0x" << std::bitset<8>(_memoryLocation) << std::endl;



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

void* PCBObj::runPCBThreadFunction(void* arg)
{

    int i = *((int*)arg);

    usleep(i * 1000);

    pthread_exit(0);

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
