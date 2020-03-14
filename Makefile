# makefile
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

all: orafce

clean:
	cd $(ROOT_DIR)/build && $(MAKE) clean

distclean:
	cd $(ROOT_DIR) && rm -rf ./build

orafce: ./build/Makefile
	cd $(ROOT_DIR)/build && $(MAKE)

./build/Makefile:
	cd $(ROOT_DIR) && ./bootstrap

