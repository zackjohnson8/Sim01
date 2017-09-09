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
    int _version = 0;
    int _timeProcessorCyc = 0;
    int _timeMonitorDis = 0;
    int _timeHardDriCyc = 0;
    int _timePrinterCyc = 0;
    int _timeKeyboardCyc = 0;
    int _timeMemoryCyc = 0;
    int _timeMouseCyc = 0;
    int _timeSpeakerCyc = 0;

    _logTo = NEITHER;
}

ConfigFile::~ConfigFile()
{

}

void ConfigFile::collectDataFrom(const std::string &fileName)
{

    std::ifstream stream;
    std::ofstream ostream;
    std::string holdLine;

    stream.open(fileName.c_str());

    if(stream.good())
    {

        // Eat the first line
        std::getline(stream, holdLine);

        // Now read in all the data
        std::getline(stream, holdLine, ':');
        stream >> _version;

        std::cout << _version << std::endl;

        // get path and delete first white space
        std::getline(stream, holdLine, ':');
        std::getline(stream, _pathFile);
        _pathFile.erase(_pathFile.begin(), _pathFile.begin()+1);

        std::cout << _pathFile << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeProcessorCyc;

        std::cout << _timeProcessorCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeMonitorDis;

        std::cout << _timeMonitorDis << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeHardDriCyc;

        std::cout << _timeHardDriCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timePrinterCyc;

        std::cout << _timePrinterCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeKeyboardCyc;

        std::cout << _timeKeyboardCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeMemoryCyc;

        std::cout << _timeMemoryCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeMouseCyc;

        std::cout << _timeMouseCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        stream >> _timeSpeakerCyc;

        std::cout << _timeSpeakerCyc << std::endl;

        //
        std::getline(stream, holdLine, ':');
        std::getline(stream, _logToString);

        _logToString.erase(_logToString.begin(), _logToString.begin()+1);

        std::cout << _logToString << std::endl;

        //TODO Hard programmed the logto file variable until specified from TA
        _logTo = BOTH;

        //
        std::getline(stream, holdLine, ':');
        std::getline(stream, _pathLogFile);

        _pathLogFile.erase(_pathLogFile.begin(), _pathLogFile.begin()+1);

        std::cout << _pathLogFile << std::endl;



    }else
    {

        std::cout << "CONFIG FILE COULD NOT OPEN: " << fileName << std::endl;

    }

    stream.close();

    // Now that you've got the data log it if specified above
    if(_logTo == BOTH)
    {

        ostream.open(_pathLogFile.c_str());

        ostream << "Configuration File Data" << std::endl;
        ostream << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Monitor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Hard Drive = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Printer = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Keyboard = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Memory = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Mouse = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Speaker = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

        ostream.close();

        std::cout << "Configuration File Data" << std::endl;
        std::cout << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Monitor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Hard Drive = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Printer = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Keyboard = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Memory = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Mouse = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Speaker = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;
    }else
    if(_logTo == LOGFILE)
    {

        ostream.open(_pathLogFile.c_str());

        ostream << "Configuration File Data" << std::endl;
        ostream << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Monitor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Hard Drive = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Printer = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Keyboard = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Memory = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Mouse = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Speaker = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        ostream << "Logged to: " << "monitor and " << _pathLogFile << std::endl << std::endl;

        ostream.close();

    }else
    if(_logTo == MONITOR)
    {

        std::cout << "Configuration File Data" << std::endl;
        std::cout << "Processor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Monitor = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Hard Drive = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Printer = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Keyboard = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Memory = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Mouse = " << _timeProcessorCyc << " ms/cycle" << std::endl;
        std::cout << "Speaker = " << _timeProcessorCyc << " ms/cycle" << std::endl;
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


#endif































