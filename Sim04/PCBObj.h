#ifndef PCBOBJ_H
#define PCBOBJ_H

#include <string>
#include <queue>

enum TaskState{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATE
};

enum logTo{
    BOTH,
    MONITOR,
    LOGFILE,
    NEITHER
};

enum algorithmChoices
{

    FIFO,
    SJF,
    PS

};

typedef struct{

    TaskState taskState_p;
    char metaDataCode;
    std::string description;
    int numberCycles;
    int timeTask;

    bool operator<(PCBTask const & rhs) const { numberCycles < rhs.numberCycles; }

}PCBTask;

class PCBObj
{

public:

    // constructor/destructor
    PCBObj(); // TODO Will probably need config file data to know how fast the computer runs each task
    ~PCBObj();

    // Functions
    void addTask(PCBTask*);
    void setProcessNum(int);
    void runPCB();
    void setLogTo(logTo, const std::string &);
    void setNumOfHardDrives(int);
    void setNumOfPrinters(int);
    void setBlockSize(int);
    void setMemorySize(int);
    void setCPUScheduling(algorithmChoices);

private:

    std::queue<PCBTask>* _pcbNewTasks;
    int _procNum;
    int _memoryAlloSize;
    unsigned int _memoryLocation;
    std::string _pathLogFile;
    unsigned int allocateMemory();

    int _blockSizes;
    int _memoryMaxSize;
    int _memoryCurrentSize;

    int _numOfPrinters;
    int _numOfHardDrives;

    int* _flagPrinters;
    int* _flagHardDrives;

    int indexPrinters;
    int indexHDD;

    logTo _logTo;

    algorithmChoices CPUScheduling;

    // private function
    static void* runPCBThreadFunction(void* arg);
};


#endif

/*

    The PCB needs to handle the typical PCB operations.
    Split up everything into queues that can be looked at and manipulated
    in the appropriate way.

    NEW, READY, RUNNING, WAITING, TERMINATE

*/
