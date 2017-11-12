#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <string>
#include "PCBObj.h"

enum memoryAlloType
{
    KILO,
    MEGA,
    GIGA
};

enum algorithmChoices
{

    FIFO,
    SJF,
    PS

};

class ConfigFile
{

public:

    // constructor/destructor
    ConfigFile();
    ~ConfigFile();

    // Functions
    void loadConfigFile(const std::string &fileName);

    // Get/Set
    int getVersion();
    int getTimeProcessor();
    int getTimeMonitor();
    int getTimeHardDrive();
    int getTimePrinter();
    int getTimeKeyboard();
    int getTimeMemory();
    int getTimeMouse();
    int getTimeSpeaker();

    int getNumOfHardDrives();
    int getNumOfPrinters();
    
    memoryAlloType getMemoryAlloType();
    int getMemoryAlloSize();
    memoryAlloType getMemoryBlockType();
    int getMemoryBlockSize();


    logTo getLogTo();

    std::string getTestPath();
    std::string getLogToString();

    void outputLog();

private:

    std::string _configFileName;
    std::string _pathFile;
    std::string _pathLogFile;
    std::string _logToString;

    float _version;
    int _timeProcessorCyc;
    int _timeMonitorDis;
    int _timeHardDriCyc;
    int _timePrinterCyc;
    int _timeKeyboardCyc;
    int _timeMemoryCyc;
    int _timeMouseCyc;
    int _timeSpeakerCyc;
    int _memoryAllocationSize;
    int _memoryBlockSize;

    memoryAlloType _memoryAlloType;
    memoryAlloType _memoryBlockType;

    int _printerQuantity;
    int _harddriveQuantity;

    int _processorQuantumNum;
    algorithmChoices _CPUScheduling;


    logTo _logTo;

};


#endif
