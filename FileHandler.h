#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler
{

public:

    // constructor/destructor
    FileHandler();
    FileHandler(const std::string &fileN, const std::string &fileT);
    ~FileHandler();

    // get/set
    std::string getFileName();
    std::string getType();
    void setFileName(std::string &newFileName);
    void setType(std::string &newTypeName);

    // function
    void addTextToFile(const std::string & strAddition);
    void addTextToFile(int);
    bool deleteBySearch(const std::string & searchedValue);
    std::string peakTop();
    void readConfigFile();




private:

    std::string fileName;
    std::string fileType;
    std::string appendedName;

};


#endif
