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




    }else
    {

        std::cout << "CONFIG FILE COULD NOT OPEN: " << fileName << std::endl;

    }

}

#endif

