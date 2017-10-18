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

    delete _metaQueue;

}

std::queue<metaTask>* MetaDataFile::getQueue()
{

    // TODO To pass back a copy, copy the data out then push into a new queue.
    // That will give me a hard copy without the segmentation fault from trying to use
    // queues = operator.

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

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "start";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);


                    }else
                    if ( (hold == "(end)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "end";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: MetaData Operating System file problems" << std::endl;
                        return 1;

                    }

                    break;

                case 'A':
                    // Process application, Keywords (start, end)
                    if( (hold == "(start)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "start";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(end)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "end";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);


                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: MetaData Process Application file problems" << std::endl;
                        return 1;

                    }

                    break;

                case 'P':
                    // Process, Keyword (run)
                    if( (hold == "(run)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "run";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: MetaData Process file problems" << std::endl;
                        return 1;

                    }
                    break;

                case 'I':
                    // Input, Keywords (hard drive, keyboard, mouse)
                    if( (hold == "(hard drive)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "hard drive";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(keyboard)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "keyboard";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);


                    }else
                    if( (hold == "(mouse)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "mouse";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: MetaData Input file problems" << std::endl;
                        return 1;

                    }
                    break;

                case 'O':
                    // Output, Keywords (hard drive, monitor, speaker, printer)
                    if( (hold == "(hard drive)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "hard drive";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(monitor)") )
                    {


                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "monitor";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(speaker)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "speaker";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(printer)"))
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "printer";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: MetaData Output file problems" << std::endl;
                        return 1;

                    }
                    break;

                case 'M':
                    // Memory, Keywords (block, allocate)
                    if( (hold == "(block)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "block";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    if( (hold == "(allocate)") )
                    {

                        holdTask = new metaTask();
                        holdTask->metaDataCode = metaCode;
                        holdTask->description = "allocate";
                        holdTask->numberCycles = cycleNumber;

                        // push holdTask onto a queue
                        _metaQueue->push(*holdTask);

                    }else
                    {

                        // ERROR
                        std::cout << "ERROR: MetaData Memory file problems" << std::endl;
                        return 1;

                    }
                    break;

                default: // Meta data doesn't match the possible metacode inputs
                    std::cout << "ERROR: meta data doesn't match the possible metacode inputs" << std::endl;
                    loopBool = false;
                    break;

            }



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

    }
    return 0;
}


#endif
