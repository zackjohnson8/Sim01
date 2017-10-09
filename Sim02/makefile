CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LFLAGSLIBS = -lpthread

sim02 : main.o ConfigFile.o MetaDataFile.o MemoryFunction.o PCBObj.o
	$(CC) $(LFLAGS) main.o ConfigFile.o MetaDataFile.o MemoryFunction.o PCBObj.o -o sim02 $(LFLAGSLIBS)

main.o : main.cpp ConfigFile.h MetaDataFile.h MemoryFunction.h
	$(CC) $(CFLAGS) main.cpp

ConfigFile.o : ConfigFile.cpp ConfigFile.h
	$(CC) $(CFLAGS) ConfigFile.cpp

MetaDataFile.o : MetaDataFile.cpp MetaDataFile.h
	$(CC) $(CFLAGS) MetaDataFile.cpp

MemoryFunction.o : MemoryFunction.cpp MemoryFunction.h
	$(CC) $(CFLAGS) MemoryFunction.cpp

PCBObj.o : PCBObj.cpp PCBObj.h
	$(CC) $(CFLAGS) PCBObj.cpp

clean:
	\rm *.o sim02

