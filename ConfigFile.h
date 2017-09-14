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

    std::string getTestPath();

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

    logTo _logTo;

};


#endif
