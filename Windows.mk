INSTALL_DIR=

all: init install

init:
ifneq ($(shell id -u), 0)
	$(error cannot install without administrator permissions)
endif

ifeq ($(INSTALL_DIR),)
	$(error no install directory provided (example: make INSTALL_DIR="C:/Program Files/RLLUtils"))
endif


	@echo installing to $(INSTALL_DIR) ...
	-mkdir "$(INSTALL_DIR)"
	-mkdir "$(INSTALL_DIR)/bin"
	echo . > rllutils.temp

install:
	@echo installing EasyATP ...
	copy bin/easyatp.exe "$(INSTALL_DIR)/bin"
	cd bin
	./installer.exe "$(INSTALL_DIR)/bin/easyatp.exe"
	cd ..

	@echo done

uninstall:

	rm "$(INSTALL_DIR)/rllutils.temp"
	cd bin
	./uninstaller.exe
	rm -r "$(INSTALL_DIR)"

	@echo done
