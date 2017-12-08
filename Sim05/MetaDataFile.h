#ifndef METADATAFILE_H
#define METADATAFILE_H

#include <cstdlib>
#include <queue>
#include <string>

struct metaTask
{

    // <Meta-Data code>(Description)<number of cycles>
    char metaDataCode;
    std::string description;
    int numberCycles;

};


class MetaDataFile
{

public:

    // constructor/destructor
    MetaDataFile();
    ~MetaDataFile();

    int loadMetaData(const std::string &);
    std::queue<metaTask>* getQueue();

private:

    std::queue<metaTask>* _metaQueue;

};


#endif
