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

        // Now read in all the data
        std::getline(stream, holdLine, ':');
        stream >> _version;

//////////////////////////////////

        // get path and delete first white space
        std::getline(stream, holdLine, ':');
        std::getline(stream, _pathFile);
        _pathFile.erase(_pathFile.begin(), _pathFile.begin()+1);

//////////////////////////////////

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeProcessorCyc;

        //std::cout << _timeProcessorCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeMonitorDis;

        //std::cout << _timeMonitorDis << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeHardDriCyc;

        //std::cout << _timeHardDriCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timePrinterCyc;

        //std::cout << _timePrinterCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeKeyboardCyc;

        //std::cout << _timeKeyboardCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeMemoryCyc;

        //std::cout << _timeMemoryCyc << std::endl;

/* Previously used in proj 1 but not in 2
        //
        std::getline(stream, holdLine, ':');
        stream >> _timeMouseCyc;

        //std::cout << _timeMouseCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeSpeakerCyc;

        //std::cout << _timeSpeakerCyc << std::endl;
*/

        std::getline(stream, holdLine, '(');
        // take in the char to find out if its k, M, G
        stream >> holdChar;
        if(holdChar == 'k')
        {

            _memoryAlloType = KILO;

        }else
        if(holdChar == 'M')
        {

            _memoryAlloType = MEGA;

        }else
        if(holdChar == 'G')
        {

            _memoryAlloType = GIGA;

        }else // error
        {

            std::cout << "ERROR: configFile.cpp, _memoryAlloType could not be specified from file provided" << std::endl;

        }
        std::getline(stream,holdLine,':');
        stream >> _memoryAllocationSize;

        //
        std::getline(stream, holdLine, ':');
        std::getline(stream, _logToString);

        _logToString.erase(_logToString.begin(), _logToString.begin()+1);

        //std::cout << _logToString << std::endl;

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

        //
        std::getline(stream, holdLine, ':');
        std::getline(stream, _pathLogFile);

        _pathLogFile.erase(_pathLogFile.begin(), _pathLogFile.begin()+1);

        //std::cout << _pathLogFile << std::endl;



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































