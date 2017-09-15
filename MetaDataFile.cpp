#ifndef METADATAFILE_CPP
#define METADATAFILE_CPP

#include "MetaDataFile.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <queue>

MetaDataFile::MetaDataFile()
{


}

MetaDataFile::~MetaDataFile()
{


}

/*
FUNCTION:
    Parse all the data from the file. As you parse and determine if the data
    is acceptable, place said data into a queue that can be returned to main
    when called for.

*/
void MetaDataFile::loadMetaData(const std::string &metaFileName)
{

    // <Meta-Data code>(Description)<number of cycles>
    std::ifstream stream;
    std::string hold;
    std::queue<metaTask> dataQueue;
    char metaCode;
    int cycleNumber;
    char exitChar = '.';
    bool loopBool = true;

    // Parse data

    //open file
    stream.open(metaFileName.c_str());

    if(stream.good())
    {

        // eat first like
        std::getline(stream, hold);

        while(loopBool)
        {


            // <Meta-Data code>(Description)<number of cycles>
            // read in the data
            stream >> metaCode;
            std::getline(stream, hold, ')');
            hold += ')';
            stream >> cycleNumber;

            std::cout << metaCode << hold << cycleNumber << std::endl;

            // TODO above we read in the data and then need to check if its
            // acceptable.

            // Since the file ends with a period I've just used that to check.
            // TODO What maybe better is to determine where in the file reads
            // END of some kind which I know is in the last line.

            stream >> exitChar;

            if(exitChar == '.')
            {

                // loop exit
                loopBool = false;

            }

            switch(metaCode)
            {

                case 'S':
                    // Operating System, Keywords (start, end)
                    break;

                case 'A':
                    // Process application, Keywords (start, end)
                    break;

                case 'P':
                    // Process, Keyword (run)
                    break;

                case 'I':
                    // Input, Keywords (hard drive, keyboard, mouse)
                    break;

                case 'O':
                    // Output, Keywords (hard drive, monitor, speaker)
                    break;

                case 'M':
                    // Memory, Keywords (block, allocate)
                    break;

                default: // Meta data doesn't match the possible metacode inputs TODO
                    std::cout << "ERROR: meta data doesn't match the possible metacode inputs" << std::endl;
                    break;

            }



        }

        stream.close();
    }

}


#endif
