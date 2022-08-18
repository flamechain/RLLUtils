CC=g++
CCFLAGS=-static -Isrc/EasyATP/include
SOURCE_FILES=src/EasyATP/src/main.cpp
INSTALL_DIR=

main:
	$(CC) $(CCFLAGS) $(SOURCE_FILES) -o easyatp.exe

installer:
	$(CC) $(CCFLAGS) src/EasyATP/installer.cpp -o installer.exe

move:
	cp easyatp.exe "$(INSTALL_DIR)/bin"

install:
	installer.exe "$(INSTALL_DIR)/bin/easyatp.exe"

cleanup:
	rm easyatp.exe
	rm installer.exe

all: installer install main move cleanup

uninstall:
	$(CC) $(CCFLAGS) src/EasyATP/uninstaller.cpp -o uninstaller.exe
	uninstaller.exe
	rm uninstaller.exe
