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
    _timeProcessorCyc = 0;
    _timeMonitorDis = 0;
    _timeHardDriCyc = 0;
    _timePrinterCyc = 0;
    _timeKeyboardCyc = 0;
    _timeMemoryCyc = 0;
    _timeMouseCyc = 0;
    _timeSpeakerCyc = 0;
    _memoryAllocationSize = 0;

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

// TODO Still need to parse the data
void ConfigFile::loadConfigFile(const std::string &fileName)
{

    std::ifstream stream;
    std::string holdLine;
    char holdChar;

    stream.open(fileName.c_str());

    if(stream.good())
    {

        // Eat the first line
        std::getline(stream, holdLine);

        // Ate the first line. Now read and place the data in the correct locations.

        while(stream.good())
        {


            std::getline(stream, holdLine, ':');

            if(holdLine == "Version/Phase")
            {

                stream >> _version;

            }else
            if( holdLine == "File Path")
            {

                std::getline(stream, _pathFile);
                _pathFile.erase(_pathFile.begin(), _pathFile.begin()+1);

            }else
            if( holdLine == "Processor cycle time (msec)")
            {

                stream >> _timeProcessorCyc;

            }else
            if( holdLine == "Monitor display time (msec)")
            {

                stream >> _timeMonitorDis;

            }else
            if( holdLine == "Hard drive cycle time (msec)")
            {

                stream >> _timeHardDriCyc;

            }else
            if( holdLine == "Printer cycle time (msec)")
            {

                stream >> _timePrinterCyc;

            }else
            if( holdLine == "Keyboard cycle time (msec)")
            {

                stream >> _timeKeyboardCyc;

            }else
            if( holdLine == "Memory cycle time (msec)" )
            {

                stream >> _timeMemoryCyc;

            }else
            if( holdLine == "System memory (kbytes)")
            {

                _memoryAlloType = KILO;
                stream >> _memoryAllocationSize;

            }else
            if( holdLine == "System memory (Mbytes)")
            {
                _memoryAlloType = MEGA;
                stream >> _memoryAllocationSize;

            }else
            if( holdLine == "System memory (Gbytes)")
            {
                _memoryAlloType = GIGA;
                stream >> _memoryAllocationSize;

            }else
            if( holdLine == "Memory block size (kbytes)")
            {

                _memoryBlockType = KILO;
                stream >> _memoryBlockSize;

            }else
            if( holdLine == "Memory block size (Mbytes)")
            {

                _memoryBlockType = MEGA;
                stream >> _memoryBlockSize;

            }else
            if( holdLine == "Memory block size (Gbytes)")
            {

                _memoryBlockType = GIGA;
                stream >> _memoryBlockSize;

            }else
            if( holdLine == "Printer quantity")
            {

                stream >> _printerQuantity;

            }else
            if( holdLine == "Hard drive quantity")
            {

                stream >> _harddriveQuantity;

            }else
            if( holdLine == "Log")
            {

                std::getline(stream, _logToString);

                _logToString.erase(_logToString.begin(), _logToString.begin()+1);

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

            }else
            if( holdLine == "Log File Path")
            {

                std::getline(stream, _pathLogFile);

                _pathLogFile.erase(_pathLogFile.begin(), _pathLogFile.begin()+1);

            }else
            {

                if( holdLine[0] == 'E')
                {

                    // End of config file

                }else
                {

                    std::cout << "ERROR: reading in config file" << std::endl;

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

void ConfigFile::outputLog()
{

    std::ofstream ostream;


    // Now that you've got the data log it if specified above
    if(_logTo == BOTH)
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
            ostream << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

            ostream.close();

        }else
        {

            std::cout << "ERROR: The log directory is not valid. Information will not be logged to a file until corrected." << std::endl << std::endl;

        }

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
            ostream << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

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
        std::cout << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

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































