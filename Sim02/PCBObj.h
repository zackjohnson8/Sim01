#ifndef PCBOBJ_H
#define PCBOBJ_H

#include <string>

enum TaskState{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATE
};

typedef struct{

    TaskState taskState_p;
    char metaDataCode;
    std::string description;
    int numberCycles;
    int timeTask;

}PCBTask;

class PCBObj
{

public:

    // constructor/destructor
    PCBObj(); // TODO Will probably need config file data to know how fast the computer runs each task
    ~PCBObj();

    // Functions
    void addTask(PCBTask*);

private:



};


#endif

/*

    The PCB needs to handle the typical PCB operations.
    Split up everything into queues that can be looked at and manipulated
    in the appropriate way.

    NEW, READY, RUNNING, WAITING, TERMINATE

*/
