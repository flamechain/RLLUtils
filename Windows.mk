INSTALL_DIR=

.PHONY: init
.PHONY: install

all: init install

init:
ifeq ($(INSTALL_DIR),)
	$(error no install directory provided (example: make INSTALL_DIR="C:/Program Files/RLLUtils"))
endif

	@echo installing to $(INSTALL_DIR) ...
	-mkdir "$(INSTALL_DIR)"
	-mkdir "$(INSTALL_DIR)/bin"
	echo . > "$(INSTALL_DIR)/rllutils.temp"

install:
	@echo installing EasyATP ...
	copy ".\\bin\\easyatp.exe" "$(INSTALL_DIR)\\bin"
	./bin/installer.exe "$(INSTALL_DIR)/bin/easyatp.exe"

	@echo done

uninstall:

	del /f "$(INSTALL_DIR)\\rllutils.temp"
	./bin/uninstaller.exe
	rmdir /s "$(INSTALL_DIR)"

	@echo done
