#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <string>

enum logTo{
    BOTH,
    MONITOR,
    LOGFILE,
    NEITHER
};

class ConfigFile
{

public:

    // constructor/destructor
    ConfigFile();
    ~ConfigFile();

    // Functions
    void collectDataFrom(const std::string &fileName);



private:

    std::string _configFileName;
    std::string _pathFile;
    std::string _pathLogFile;
    std::string _logToString;

    int _version;
    int _timeProcessorCyc;
    int _timeMonitorDis;
    int _timeHardDriCyc;
    int _timePrinterCyc;
    int _timeKeyboardCyc;
    int _timeMemoryCyc;
    int _timeMouseCyc;
    int _timeSpeakerCyc;

    logTo _logTo;

};


#endif
