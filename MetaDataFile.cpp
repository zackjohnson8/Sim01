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

    _metaQueue = new std::queue<metaTask>();

}

MetaDataFile::~MetaDataFile()
{


}

std::queue<metaTask>* MetaDataFile::getQueue()
{

    //std::queue<metaTask>* _returnedValue;

    //*_returnedValue = *_metaQueue;

    return _metaQueue;

}

/*
FUNCTION:
    Parse all the data from the file. As you parse and determine if the data
    is acceptable, place said data into a queue that can be returned to main
    when called for.

    Return value is an int. 0 is good, anything else is error break program or
    solve in main.

*/
int MetaDataFile::loadMetaData(const std::string &metaFileName)
{

    // <Meta-Data code>(Description)<number of cycles>
    std::ifstream stream;
    std::string hold;
    std::queue<metaTask> dataQueue;
    char metaCode;
    int cycleNumber;
    char exitChar = '.';
    bool loopBool = true;

    metaTask* holdTask;

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
            stream >> exitChar;

            // Based on the meta data code
            switch(metaCode)
            {

                // If it makes it into one of the cases we'll need to still
                // check if the keyword works

                case 'S':
                    // Operating System, Keywords (start, end)
                    if( (hold == "(start)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "start";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);


                    }else
                    if ( (hold == "(end)") )
                    {

                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "end";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // TODO ERROR
                        std::cout << "ERROR1" << std::endl;
                        return 1;

                    }

                    break;

                case 'A':
                    // Process application, Keywords (start, end)
                    if( (hold == "(start)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "start";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(end)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "end";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);


                    }else
                    {

                        // TODO ERROR
                        std::cout << "ERROR2" << std::endl;
                        return 1;

                    }

                    break;

                case 'P':
                    // Process, Keyword (run)
                    if( (hold == "(run)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "run";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // TODO ERROR
                        std::cout << "ERROR3" << std::endl;
                        return 1;

                    }
                    break;

                case 'I':
                    // Input, Keywords (hard drive, keyboard, mouse)
                    if( (hold == "(hard drive)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "hard drive";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(keyboard)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "keyboard";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);


                    }else
                    if( (hold == "(mouse)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "mouse";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // TODO ERROR
                        std::cout << "ERROR4" << std::endl;
                        return 1;

                    }
                    break;

                case 'O':
                    // Output, Keywords (hard drive, monitor, speaker, printer)
                    if( (hold == "(hard drive)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "hard drive";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(monitor)") )
                    {

                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "monitor";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(speaker)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "speaker";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(printer)"))
                    {

                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "printer";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // TODO ERROR'
                        std::cout << "ERROR5" << std::endl;
                        return 1;

                    }
                    break;

                case 'M':
                    // Memory, Keywords (block, allocate)
                    if( (hold == "(block)") )
                    {
                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "block";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(allocate)") )
                    {

                        std::cout << "WORKS" << std::endl;
                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "allocate";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // TODO ERROR
                        std::cout << "ERROR6" << std::endl;
                        return 1;

                    }
                    break;

                default: // Meta data doesn't match the possible metacode inputs TODO
                    std::cout << "ERROR: meta data doesn't match the possible metacode inputs" << std::endl;
                    loopBool = false;
                    break;

            }

            std::cout << metaCode << hold << cycleNumber << std::endl;

            // TODO above we read in the data and then need to check if its
            // acceptable.

            // Since the file ends with a period I've just used that to check.
            // TODO What maybe better is to determine where in the file reads
            // END of some kind which I know is in the last line.



            if(exitChar == '.')
            {

                // loop exit
                loopBool = false;

            }



        }

        stream.close();
        return 0;
    }

}


#endif
