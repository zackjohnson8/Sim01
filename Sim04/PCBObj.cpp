#ifndef PCBOBJ_CPP
#define PCBOBJ_CPP

#include "PCBObj.h"
#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
#include <bitset>
#include <pthread.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// constructor/destructor -------------------------------------------------
PCBObj::PCBObj()
{

    _pcbNewTasks = new std::queue<PCBTask>();
    _procNum = 0;
    _memoryMaxSize = 0;
    _memoryCurrentSize = 0;
    _blockSizes = 0;
    _logTo = BOTH;
    _pathLogFile = "defaultPCBLog";

    indexPrinters = -1;
    indexHDD = -1;

    _numOfHardDrives  = 0;
    _numOfPrinters = 0;

    _flagPrinters = NULL;
    _flagHardDrives = NULL;

    CPUScheduling = FIFO; // default

}

PCBObj::~PCBObj()
{

    delete _pcbNewTasks;

}

void PCBObj::setProcessNum(int T)
{

    _procNum = T;

}

void PCBObj::setLogTo(logTo p, const std::string &fileName)
{

    _logTo = p;
    _pathLogFile = fileName;

}

void PCBObj::setNumOfHardDrives(int pNum)
{

    if( _flagHardDrives != NULL)
    {

        delete _flagHardDrives;
        _flagHardDrives = NULL;

    }

    // Set the number integer then create the array
    _numOfHardDrives = pNum;
    _flagHardDrives = new int[pNum];

    // set all the flags to 0
    for(int x = 0; x < pNum; x++)
    {

        _flagHardDrives[x] = 0;

    }

}

void PCBObj::setNumOfPrinters(int pNum)
{

    int getMemoryBlockSize();
    int getMemoryAlloSize();    if( _flagPrinters != NULL)
    {
        int getMemoryBlockSize();
        int getMemoryAlloSize();
        delete _flagPrinters;
        _flagPrinters = NULL;

    }

    // Set the number integer then create the array
    _numOfPrinters = pNum;
    _flagPrinters = new int[pNum];

    // set all the flags to 0
    for(int x = 0; x < pNum; x++)
    {

        _flagPrinters[x] = 0;

    }

}

void PCBObj::setBlockSize(int pSize)
{

    _blockSizes = pSize;

}

void PCBObj::setMemorySize(int pSize)
{

    _memoryMaxSize = pSize;

}

void PCBObj::setCPUScheduling(algorithmChoices T)
{

    CPUScheduling = T;

}

void PCBObj::addTask(PCBTask* T)
{

    T->taskState_p = READY;
    _pcbNewTasks->push(*T);

    // for different CPU Scheduling I'll need to know how many of which task I've got
    



}

void PCBObj::runPCB()
{

    struct timeval tvEnd;
    struct timeval tvStart;
    gettimeofday(&tvStart,NULL);

    // For output to file
    std::ofstream ostream;
    ostream.open(_pathLogFile.c_str(), std::ios_base::app);

    // pthread... we need a way to identify the pthread and also a variable to tell the pthread how to handle the thread
    pthread_t threadId;
    pthread_attr_t threadAttr;
    int* passVal;

    int index;

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    // Prepare PCB tasks for FIFO, SJF, PS
    if(CPUScheduling == SJF)
    {

        // SJF: The SJF should count the total number of tasks in a process
        // and the process with least number of tasks will be completed first.
        

    }else
    if(CPUScheduling == PS)
    {



    }else 
    {

        // already in FIFO order

    }

    // Pull each queued PCBTask and handle each task accordingly
    while(!_pcbNewTasks->empty())
    {
            //std::cout << "isthisworking" << std::endl;

        if(_logTo == MONITOR)
        {
            switch(_pcbNewTasks->front().metaDataCode)
            {

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

                    _memoryCurrentSize = 0;
                    indexHDD = -1;
                    indexPrinters = -1;

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



                // Initialize the threadAttribute
                pthread_attr_init(&threadAttr);

                // Integer value to pass to thread
                passVal = (int*)malloc(sizeof(*passVal));
                *passVal = _pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask;

                if( (_pcbNewTasks->front().description == "hard drive") )
                {
                    pthread_mutex_lock(&mutex);

                    index = 0;

                    while( _flagHardDrives[index % _numOfHardDrives] == 1 )
                    {
                        index++;
                        
                    }

                    indexHDD++;

                    // set flag since I'm about to use it
                    _flagHardDrives[index] = 1;

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start hard drive output on HDD " << indexHDD % _numOfHardDrives << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive output" << std::endl;

                    // reset flag back to 0 now that its done
                    _flagHardDrives[index] = 0;

                    pthread_mutex_unlock(&mutex);

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

                    // MUTEX THE ENTIRE IF STATEMENT HERE

                    pthread_mutex_lock(&mutex);

                    index = 0;

                    while( _flagPrinters[index % _numOfPrinters] == 1 )
                    {
                        index++;
                    }

                    indexPrinters++;

                    // set flag since I'm about to use it
                    _flagPrinters[index] = 1;

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start printer output on PRNTR " << indexPrinters % _numOfPrinters << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end printer output" << std::endl;

                    // reset flag back to 0 now that its done
                    _flagPrinters[index] = 0;

                    // TO HERE
                    pthread_mutex_unlock(&mutex);

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

                    _memoryLocation = allocateMemory();

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": memory allocated at 0x" << std::setprecision(8) << std::hex << _memoryLocation << std::endl;



                }else
                {

                    // ERROR
                    std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;

                }

                break;

            default:
                std::cout << "ERROR: metaDataCode isn't matching up correctly and can't run the task" << std::endl;

            }

        }else
        if(_logTo == LOGFILE)
        {


            switch(_pcbNewTasks->front().metaDataCode)
            {

            case 'S':
                // Also just start and end
                if( _pcbNewTasks->front().description == "start")
                {
                    // grab current time then print the difference from when this began
                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - Simulator program starting" << std::endl;

                }else
                if(_pcbNewTasks->front().description == "end")
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - Simulator program ending" << std::endl;

                }

                break;

            case 'A':
                // Using process now.
                if( _pcbNewTasks->front().description == "start")
                {
                    // grab current time then print the difference from when this began
                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: preparing process " << this->_procNum << std::endl;


                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: starting process " << this->_procNum << std::endl;

                }else
                if(_pcbNewTasks->front().description == "end")
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: removing process " << this->_procNum << std::endl;

                }

                break;

            case 'P':

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start processing action" << std::endl;

                    usleep(_pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end processing action" << std::endl;


                break;

            case 'I':



                // Initialize the threadAttribute
                pthread_attr_init(&threadAttr);

                // Integer value to pass to thread
                passVal = (int*)malloc(sizeof(*passVal));
                *passVal = _pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask;


                if( (_pcbNewTasks->front().description == "hard drive") )
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start hard drive input" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive input" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "keyboard") )
                {
                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start keyboard input" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end keyboard input" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "mouse") )
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start mouse input" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start mouse input" << std::endl;

                }else
                {

                    // ERROR
                    ostream << "ERROR: deletion of task before sending to pcb" << std::endl;


                }

                break;

            case 'O':



                // Initialize the threadAttribute
                pthread_attr_init(&threadAttr);

                // Integer value to pass to thread
                passVal = (int*)malloc(sizeof(*passVal));
                *passVal = _pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask;

                if( (_pcbNewTasks->front().description == "hard drive") )
                {

                    pthread_mutex_lock(&mutex);

                    index = 0;

                    while( _flagHardDrives[index % _numOfHardDrives] == 1 )
                    {
                        index++;
                    }

                    indexHDD++;

                    // set flag since I'm about to use it
                    _flagHardDrives[index] = 1;

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start hard drive output on HDD " << indexHDD % _numOfHardDrives << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive output" << std::endl;

                    // reset flag back to 0 now that its done
                    _flagHardDrives[index] = 0;

                    pthread_mutex_unlock(&mutex);

                }else
                if( (_pcbNewTasks->front().description == "monitor") )
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start monitor output" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end monitor output" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "speaker") )
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start speaker output" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end speaker output" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "printer"))
                {

                    pthread_mutex_lock(&mutex);

                    index = 0;

                    while( _flagPrinters[index % _numOfPrinters] == 1 )
                    {
                        index++;
                    }

                    indexPrinters++;

                    // set flag since I'm about to use it
                    _flagPrinters[index] = 1;

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start printer output on PRNTR " << indexPrinters % _numOfPrinters<< std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end printer output" << std::endl;

                    // reset flag back to 0 now that its done
                    _flagPrinters[index] = 0;

                    pthread_mutex_unlock(&mutex);

                }else
                {

                    // ERROR
                    ostream << "ERROR: deletion of task before sending to pcb" << std::endl;
                }

                break;

            case 'M':


                if( (_pcbNewTasks->front().description == "block") )
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start memory blocking" << std::endl;

                    usleep(_pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask);

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end memory blocking" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "allocate") )
                {

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": allocating memory" << std::endl;

                    _memoryLocation = allocateMemory();

                    gettimeofday(&tvEnd, NULL);
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": memory allocated at 0x" << std::setprecision(8) << std::hex << _memoryLocation << std::endl;



                }else
                {

                    // ERROR
                    ostream << "ERROR: deletion of task before sending to pcb" << std::endl;

                }

                break;

            default:
                ostream << "ERROR: metaDataCode isn't matching up correctly and can't run the task" << std::endl;
        }

        }else
        if(_logTo == BOTH)
        {

            switch(_pcbNewTasks->front().metaDataCode)
            {

            case 'S':
                // Also just start and end
                if( _pcbNewTasks->front().description == "start")
                {
                    // grab current time then print the difference from when this began
                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - Simulator program starting" << std::endl;

                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - Simulator program starting" << std::endl;

                }else
                if(_pcbNewTasks->front().description == "end")
                {

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - Simulator program ending" << std::endl;

                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
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
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: preparing process " << this->_procNum << std::endl;


                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: starting process " << this->_procNum << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: starting process " << this->_procNum << std::endl;

                }else
                if(_pcbNewTasks->front().description == "end")
                {

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: removing process " << this->_procNum << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000
                    << " - OS: removing process " << this->_procNum << std::endl;

                }

                break;

            case 'P':

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start processing action" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start processing action" << std::endl;

                    usleep(_pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end processing action" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end processing action" << std::endl;


                break;

            case 'I':



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
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start hard drive input" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive input" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive input" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "keyboard") )
                {
                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start keyboard input" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start keyboard input" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end keyboard input" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end keyboard input" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "mouse") )
                {

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start mouse input" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start mouse input" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start mouse input" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start mouse input" << std::endl;

                }else
                {

                    // ERROR
                    std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;


                }

                break;

            case 'O':



                // Initialize the threadAttribute
                pthread_attr_init(&threadAttr);

                // Integer value to pass to thread
                passVal = (int*)malloc(sizeof(*passVal));
                *passVal = _pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask;

                if( (_pcbNewTasks->front().description == "hard drive") )
                {

                    pthread_mutex_lock(&mutex);

                    index = 0;

                    while( _flagHardDrives[index % _numOfHardDrives] == 1 )
                    {
                        index++;
                    }

                    indexHDD++;

                    // set flag since I'm about to use it
                    _flagHardDrives[index] = 1;

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start hard drive output on HDD " << indexHDD % _numOfHardDrives << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start hard drive output on HDD " << indexHDD % _numOfHardDrives << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive output" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end hard drive output" << std::endl;

                    // reset flag back to 0 now that its done
                    _flagHardDrives[index] = 0;

                    pthread_mutex_unlock(&mutex);

                }else
                if( (_pcbNewTasks->front().description == "monitor") )
                {

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start monitor output" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start monitor output" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end monitor output" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end monitor output" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "speaker") )
                {

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start speaker output" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start speaker output" << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end speaker output" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end speaker output" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "printer"))
                {

                    pthread_mutex_lock(&mutex);

                    index = 0;

                    while( _flagPrinters[index % _numOfPrinters] == 1 )
                    {
                        index++;
                    }

                    indexPrinters++;

                    // set flag since I'm about to use it
                    _flagPrinters[index] = 1;

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start printer output on PRNTR " << indexPrinters % _numOfPrinters << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start printer output on PRNTR" << indexPrinters % _numOfPrinters << std::endl;

                    pthread_create(&threadId, &threadAttr, runPCBThreadFunction, (void*)passVal );
                    pthread_join(threadId, NULL);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end printer output" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end printer output" << std::endl;

                    // reset flag back to 0 now that its done
                    _flagPrinters[index] = 0;

                    pthread_mutex_unlock(&mutex);

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
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": start memory blocking" << std::endl;

                    usleep(_pcbNewTasks->front().numberCycles * _pcbNewTasks->front().timeTask);

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end memory blocking" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": end memory blocking" << std::endl;

                }else
                if( (_pcbNewTasks->front().description == "allocate") )
                {

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": allocating memory" << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": allocating memory" << std::endl;

                    _memoryLocation = allocateMemory();

                    gettimeofday(&tvEnd, NULL);
                    std::cout << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": memory allocated at 0x" << std::setprecision(8) << std::hex << _memoryLocation << std::endl;
                    ostream << std::fixed << std::setprecision(6) << (float)((tvEnd.tv_sec - tvStart.tv_sec)) + (float)(tvEnd.tv_usec - tvStart.tv_usec) / 1000000 << " - Process " << this->_procNum
                    << ": memory allocated at 0x" << std::setprecision(8) << std::hex << _memoryLocation << std::endl;



                }else
                {

                    // ERROR
                    std::cout << "ERROR: deletion of task before sending to pcb" << std::endl;

                }

                break;

            default:
                std::cout << "ERROR: metaDataCode isn't matching up correctly and can't run the task" << std::endl;
        }


        }else
        {


            // TODO

        }

        _pcbNewTasks->pop();

    }

    ostream.close();
    pthread_mutex_destroy(&mutex);

    std::cout << std::dec;

}

void* PCBObj::runPCBThreadFunction(void* arg)
{

    int i = *((int*)arg);

    usleep(i * 1000);

    pthread_exit(0);

}

// Return a kilobyte answer that needs to be converted by the caller
unsigned int PCBObj::allocateMemory()
{
    unsigned int address;
    
    if(( _memoryCurrentSize + _blockSizes ) < _memoryMaxSize )
    {

        address = _memoryCurrentSize;
        _memoryCurrentSize += _blockSizes;

        return address;

    }else
    {

        address = 0;
        _memoryCurrentSize = 0;

        return address;

    }
    
	
}

#endif

