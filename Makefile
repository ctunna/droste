TARGET=tdriver
MODULES=tdriver.o intutil.o droste.o
MAGICKFLAGS=-lMagick++ -lMagickWand -lMagickCore -lz -lm -lgomp -lpthread
CPPFLAGS=-I/usr/local/include/ImageMagick -g -O2 -pthread -Wall -Wextra

$(TARGET): $(MODULES)
	g++ $(MODULES) $(CPPFLAGS) $(MAGICKFLAGS) -o $(TARGET)

clean:
	/bin/rm *.o $(TARGET)

all: clean $(TARGET)

intutil.o: intutil.cpp intutil.h

droste.o: droste.cpp droste.h

tdriver.o: tdriver.cpp
