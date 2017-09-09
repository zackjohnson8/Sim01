#include <iostream>
#include <cstdlib>
#include <string>
#include "FileHandler.h"
#include "ConfigFile.h"

using namespace std;

int main(int argc, char* argv[])
{

    /*
        Based on the description we'll need to complete said tasks in order...

        1.) Read in the config file which will provide the specifics for the program.
            Based on what I've read this can change so which data do we need to take in?

            List:
            Starting the program with ./sim01 config_1.conf

            For now lets get
            Processor cycle time (msec): 10
            Monitor display time (msec): 20
            Hard drive cycle time (msec): 15
            Printer cycle time (msec): 25
            Keyboard cycle time (msec): 50
            Memory cycle time (msec): 30
            Mouse cycle time (msec): 10
            Speaker cycle time (msec): 20
            Log: Log to Both
            Log File Path: logfile_1.lgf

        2.) there is then the input file that will need to be read which looks like
            Start Program Meta-Data Code:
            S(start)0; A(start)0; P(run)11; M(allocate)2;
            O(monitor)7; I(hard drive)8; I(mouse)8; O(printer)20;
            P(run)6; O(printer)4; M(block)6;
            I(keyboard)17; M(block)4; O(speaker)8; P(run)5; P(run)5;
            O(hard drive)6; P(run)18; A(end)0; S(end)0.
            End Program Meta-Data Code.

    */

    // The program will be given a specific amount of configure files
    // Parameters for config files
    ConfigFile* ConfigFile_p;
    ConfigFile_p = new ConfigFile[argc-1];

    for(int index = 1; index < argc; index++)
    {

        ConfigFile_p->collectDataFrom(argv[index]);

    }


    delete[] ConfigFile_p;
}
