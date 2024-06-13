CC = gcc-14

# Define include path and SDK path for gcc on Mac
INCLUDE_DIR = /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
SDK_PATH = $(shell xcrun --sdk macosx --show-sdk-path)

CFLAGS = -I$(INCLUDE_DIR) -fopenmp -isysroot $(SDK_PATH)

SOURCES = $(wildcard *.c)

TARGETS = $(addprefix build/,$(SOURCES:.c=))

all: build $(TARGETS)

build:
	mkdir -p build

build/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf build
