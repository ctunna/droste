TARGET=tdriver
MODULES=droste.o tdriver.o
MAGICKFLAGS=`Magick++-config --cppflags --cxxflags --ldflags --libs`
CPPFLAGS=-DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/Cellar/imagemagick/7.0.6-10/include/ImageMagick-7 -g -O2 -Wall -Wextra -std=c++11

$(TARGET): $(MODULES)
	g++ $(MODULES) $(MAGICKFLAGS) $(CPPFLAGS) -o $(TARGET)

clean:
	/bin/rm *.o $(TARGET)

all: clean $(TARGET)

#intutil.o: intutil.cpp intutil.h

droste.o: droste.cpp droste.h

tdriver.o: tdriver.cpp
