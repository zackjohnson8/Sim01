#ifndef CONFIGFILE_CPP
#define CONFIGFILE_CPP

#include "ConfigFile.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

// constructor/destructor -------------------------------------------------
ConfigFile::ConfigFile()
{

    // may as well zero out the data until you read the files
    _version = 0;
    _timeProcessorCyc = 1;
    _timeMonitorDis = 1;
    _timeHardDriCyc = 1;
    _timePrinterCyc = 1;
    _timeKeyboardCyc = 1;
    _timeMemoryCyc = 1;
    _timeMouseCyc = 1;
    _timeSpeakerCyc = 1;
    _memoryAllocationSize = 1;

    _printerQuantity = 1;
    _harddriveQuantity = 1;

    _memoryAlloType = KILO;

    _logTo = NEITHER;
}

ConfigFile::~ConfigFile()
{

}

logTo ConfigFile::getLogTo()
{

    return _logTo;

}

void ConfigFile::loadConfigFile(const std::string &fileName)
{

    std::ifstream stream;
    std::string holdLine;


    stream.open(fileName.c_str());

    if(stream.good())
    {

        // Eat the first line
        std::getline(stream, holdLine);
        

        // Ate the first line. Now read and place the data in the correct locations.

        while(stream.good())
        {


            std::getline(stream, holdLine, ':');
            // std::cout << holdLine << std::endl;

            if(holdLine == "Version/Phase")
            {

                stream >> _version;

                std::getline(stream, holdLine);

                //std::cout << "version set" << std::endl;

            }else
            if( holdLine == "File Path")
            {

                std::getline(stream, _pathFile);
                _pathFile.erase(_pathFile.begin(), _pathFile.begin()+1);


                //std::cout << "File Path set" << std::endl;

            }else
            if(holdLine == "Processor Quantum Number") // processor quantum
            {
                
                stream >> _processorQuantumNum;

                std::getline(stream, holdLine);

            }else
            if(holdLine == "CPU Scheduling Code") // pcb alg to use
            {

                std::getline(stream, holdLine);
                
                holdLine.erase(holdLine.begin(), holdLine.begin()+1);

                if(holdLine == "FIFO")
                {
                    _CPUScheduling = FIFO;
                }else
                if(holdLine == "SJF")
                {
                    _CPUScheduling = SJF;

                }else
                if(holdLine == "PS")
                {
                    _CPUScheduling = PS;
                }else
                {

                    std::cout << "ERROR: configfile.cpp, trouble with CPU Scheduling, 128" << std::endl;
                    // DEFAULT FIFO
                    _CPUScheduling = FIFO;
                }   

            }else
            if( holdLine == "Processor cycle time (msec)")
            {

                //std::cout << "Processor set" << std::endl;
                stream >> _timeProcessorCyc;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Monitor display time (msec)")
            {

                stream >> _timeMonitorDis;

                //std::cout << "Monitor set" << std::endl;
                std::getline(stream, holdLine);

            }else
            if(holdLine == "Mouse cycle time (msec)")
            {

                stream >> _timeMouseCyc;
                std::getline(stream, holdLine);

            }else
            if( holdLine == "Hard drive cycle time (msec)")
            {

                //std::cout << "Hard drive set" << std::endl;
                stream >> _timeHardDriCyc;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Printer cycle time (msec)")
            {

                //std::cout << "Printer set" << std::endl;
                stream >> _timePrinterCyc;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Keyboard cycle time (msec)")
            {

                //std::cout << "Keyboard set" << std::endl;
                stream >> _timeKeyboardCyc;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Memory cycle time (msec)" )
            {

                //std::cout << "Memory cycle set" << std::endl;
                stream >> _timeMemoryCyc;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "System memory (kbytes)")
            {

                _memoryAlloType = KILO;
                stream >> _memoryAllocationSize;
                //std::cout << "System mem set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "System memory (Mbytes)")
            {
                _memoryAlloType = MEGA;
                stream >> _memoryAllocationSize;
                //std::cout << "System Memory set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "System memory (Gbytes)")
            {
                _memoryAlloType = GIGA;
                stream >> _memoryAllocationSize;
                //std::cout << "System mem set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Memory block size (kbytes)")
            {

                _memoryBlockType = KILO;
                stream >> _memoryBlockSize;
                //std::cout << "Memory block set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Memory block size (Mbytes)")
            {

                _memoryBlockType = MEGA;
                stream >> _memoryBlockSize;
                //std::cout << "Memory block set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Memory block size (Gbytes)")
            {

                _memoryBlockType = GIGA;
                stream >> _memoryBlockSize;
                //std::cout << "Memory block set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Printer quantity")
            {

                stream >> _printerQuantity;
                //std::cout << "Printer quan set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Hard drive quantity")
            {

                stream >> _harddriveQuantity;
                //std::cout << "Hard drive quan set" << std::endl;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Log")
            {

                std::getline(stream, _logToString);

                _logToString.erase(_logToString.begin(), _logToString.begin()+1);

                //std::cout << _logToString;

                // Based on string set _logTo to BOTH, MONITOR, or LOGFILE. Else FAIL
                if(_logToString == "Log to Both")
                {
                    _logTo = BOTH;

                }else
                if(_logToString == "Log to Monitor")
                {
                    _logTo = MONITOR;

                }else
                if(_logToString == "Log to File")
                {
                    _logTo = LOGFILE;
                }else
                {

                    std::cout << "ERROR: config file log to was neither BOTH, MONITOR, or FILE. Auto set to BOTH" << std::endl;
                    _logTo = BOTH;
                }

                //std::cout << "Log set" << std::endl;

            }else
            if(holdLine == "Speaker cycle time (msec)")
            {

                stream >> _timeSpeakerCyc;

                std::getline(stream, holdLine);

            }else
            if( holdLine == "Log File Path")
            {

                std::getline(stream, _pathLogFile);

                _pathLogFile.erase(_pathLogFile.begin(), _pathLogFile.begin()+1);

                //std::cout << "log path set" << std::endl;

            }else
            {

                if( holdLine[0] == 'E')
                {

                    // End of config file

                }else
                {

                    std::cout << "ERROR: reading in config file" << std::endl << std::endl;

                }

            }

        }


    }else
    {

        std::cout << "CONFIG FILE COULD NOT OPEN: " << fileName << std::endl;

    }

    stream.close();

}

int ConfigFile::getVersion()
{

    return _version;

}

int ConfigFile::getTimeProcessor()
{

    return _timeProcessorCyc;

}

int ConfigFile::getTimeMonitor()
{

    return _timeMonitorDis;

}

int ConfigFile::getTimeHardDrive()
{

    return _timeHardDriCyc;

}

int ConfigFile::getTimePrinter()
{

    return _timePrinterCyc;

}

memoryAlloType ConfigFile::getMemoryAlloType()
{

    return _memoryAlloType;

}

algorithmChoices ConfigFile::getCPUScheduling()
{

    return _CPUScheduling;

}

int ConfigFile::getMemoryAlloSize()
{

    return _memoryAllocationSize;

}

int ConfigFile::getTimeKeyboard()
{

    return _timeKeyboardCyc;

}

int ConfigFile::getTimeMemory()
{

    return _timeMemoryCyc;

}

int ConfigFile::getTimeMouse()
{

    return _timeMouseCyc;

}

int ConfigFile::getTimeSpeaker()
{

    return _timeSpeakerCyc;

}

std::string ConfigFile::getTestPath()
{

    return _pathFile;
}

std::string ConfigFile::getLogToString()
{

    return _pathLogFile;

}

int ConfigFile::getNumOfHardDrives()
{

    return _harddriveQuantity;

}

int ConfigFile::getNumOfPrinters()
{

    return _printerQuantity;

}

int ConfigFile::getMemoryBlockSize()
{

    return _memoryBlockSize;

}

memoryAlloType ConfigFile::getMemoryBlockType()
{

    return _memoryBlockType;

}

void ConfigFile::outputLog()
{

    std::ofstream ostream;

    std::cout << std::dec;

    // Now that you've got the data log it if specified above
    if(_logTo == BOTH)
    {

        std::cout << "Configuration File Data" << std::endl;
        std::cout << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Monitor = " << _timeMonitorDis << " ms/cycle" << std::endl;
        std::cout << "Hard Drive = " << _timeHardDriCyc << " ms/cycle" << std::endl;
        std::cout << "Printer = " << _timePrinterCyc << " ms/cycle" << std::endl;
        std::cout << "Keyboard = " << _timeKeyboardCyc << " ms/cycle" << std::endl;
        std::cout << "Memory = " << _timeMemoryCyc << " ms/cycle" << std::endl;
        std::cout << "Mouse = " << _timeMouseCyc << " ms/cycle" << std::endl;
        std::cout << "Speaker = " << _timeSpeakerCyc << " ms/cycle" << std::endl;
        std::cout << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

        ostream.open(_pathLogFile.c_str());
        if(ostream.good())
        {

            ostream << "Configuration File Data" << std::endl;
            ostream << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
            ostream << "Monitor = " << _timeMonitorDis << " ms/cycle" << std::endl;
            ostream << "Hard Drive = " << _timeHardDriCyc << " ms/cycle" << std::endl;
            ostream << "Printer = " << _timePrinterCyc << " ms/cycle" << std::endl;
            ostream << "Keyboard = " << _timeKeyboardCyc << " ms/cycle" << std::endl;
            ostream << "Memory = " << _timeMemoryCyc << " ms/cycle" << std::endl;
            ostream << "Mouse = " << _timeMouseCyc << " ms/cycle" << std::endl;
            ostream << "Speaker = " << _timeSpeakerCyc << " ms/cycle" << std::endl;
            ostream << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

            ostream.close();

        }else
        {

            std::cout << "ERROR: The log directory is not valid. Information will not be logged to a file until corrected." << std::endl << std::endl;

        }



    }else
    if(_logTo == LOGFILE)
    {

        ostream.open(_pathLogFile.c_str());

        if(ostream.good())
        {
            ostream << "Configuration File Data" << std::endl;
            ostream << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
            ostream << "Monitor = " << _timeMonitorDis << " ms/cycle" << std::endl;
            ostream << "Hard Drive = " << _timeHardDriCyc << " ms/cycle" << std::endl;
            ostream << "Printer = " << _timePrinterCyc << " ms/cycle" << std::endl;
            ostream << "Keyboard = " << _timeKeyboardCyc << " ms/cycle" << std::endl;
            ostream << "Memory = " << _timeMemoryCyc << " ms/cycle" << std::endl;
            ostream << "Mouse = " << _timeMouseCyc << " ms/cycle" << std::endl;
            ostream << "Speaker = " << _timeSpeakerCyc << " ms/cycle" << std::endl;
            ostream << "Logged to: " << _pathLogFile << std::endl << std::endl;

            ostream.close();
        }else
        {

            std::cout << "ERROR: The log directory is not valid. Information will not be logged until corrected." << std::endl << std::endl;

        }


    }else
    if(_logTo == MONITOR)
    {

        std::cout << "Configuration File Data" << std::endl;
        std::cout << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Monitor = " << _timeMonitorDis << " ms/cycle" << std::endl;
        std::cout << "Hard Drive = " << _timeHardDriCyc << " ms/cycle" << std::endl;
        std::cout << "Printer = " << _timePrinterCyc << " ms/cycle" << std::endl;
        std::cout << "Keyboard = " << _timeKeyboardCyc << " ms/cycle" << std::endl;
        std::cout << "Memory = " << _timeMemoryCyc << " ms/cycle" << std::endl;
        std::cout << "Mouse = " << _timeMouseCyc << " ms/cycle" << std::endl;
        std::cout << "Speaker = " << _timeSpeakerCyc << " ms/cycle" << std::endl;
        std::cout << "Logged to: " << "monitor" << std::endl << std::endl;

    }else
    if(_logTo == NEITHER)
    {

        // DO NOTHING

    }else
    {

        // There is a problem with _logTo not being set
        std::cout << "Problem with _logTo not being set in ConfigFile class" << std::endl;

    }

}


#endif































