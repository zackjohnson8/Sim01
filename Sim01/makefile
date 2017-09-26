CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

sim01 : main.o ConfigFile.o MetaDataFile.o MemoryFunction.o
	$(CC) $(LFLAGS) main.o ConfigFile.o MetaDataFile.o MemoryFunction.o -o sim01

main.o : main.cpp ConfigFile.h MetaDataFile.h MemoryFunction.h
	$(CC) $(CFLAGS) main.cpp

ConfigFile.o : ConfigFile.cpp ConfigFile.h
	$(CC) $(CFLAGS) ConfigFile.cpp

MetaDataFile.o : MetaDataFile.cpp MetaDataFile.h
	$(CC) $(CFLAGS) MetaDataFile.cpp

MemoryFunction.o : MemoryFunction.cpp MemoryFunction.h
	$(CC) $(CFLAGS) MemoryFunction.cpp

clean:
	\rm *.o sim01

