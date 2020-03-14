# makefile
all: orafce

clean:
	cd ./build && $(MAKE) clean

orafce: ./build/Makefile
	cd ./build && $(MAKE)

./build/Makefile:
	./bootstrap

