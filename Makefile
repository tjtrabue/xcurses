# Directory vars
BUILD_DIR = build
DEBUG_DIR = debug

# The actual CMake build command
CMAKE_BUILD_CMD=--build .
# CMake flags common to any build type
CMAKE_BUILD_OPTS=--use-stderr

### Targets ###

all: build

build:
	mkdir -p ${BUILD_DIR}
	( cd ${BUILD_DIR} && cmake -DCMAKE_BUILD_TYPE=Release .. && \
		cmake ${CMAKE_BUILD_CMD} ${CMAKE_BUILD_OPTS} )

debug:
	mkdir -p ${DEBUG_DIR}
	( cd ${DEBUG_DIR} && cmake -DCMAKE_BUILD_TYPE=Debug .. && \
		cmake ${CMAKE_BUILD_CMD} ${CMAKE_BUILD_OPTS} )

clean:
	rm -rf ${BUILD_DIR} ${DEBUG_DIR}

.PHONY: all build clean debug