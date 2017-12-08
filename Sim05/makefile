CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LFLAGSLIBS = -lpthread

sim05 : main.o ConfigFile.o MetaDataFile.o PCBObj.o
	$(CC) $(LFLAGS) main.o ConfigFile.o MetaDataFile.o PCBObj.o -o sim05 $(LFLAGSLIBS)

main.o : main.cpp ConfigFile.h MetaDataFile.h
	$(CC) $(CFLAGS) main.cpp

ConfigFile.o : ConfigFile.cpp ConfigFile.h
	$(CC) $(CFLAGS) ConfigFile.cpp

MetaDataFile.o : MetaDataFile.cpp MetaDataFile.h
	$(CC) $(CFLAGS) MetaDataFile.cpp

PCBObj.o : PCBObj.cpp PCBObj.h
	$(CC) $(CFLAGS) PCBObj.cpp

clean:
	\rm *.o sim05
