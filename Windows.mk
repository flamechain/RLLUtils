INSTALL_DIR=

.PHONY: init
.PHONY: install

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
	echo . > "$(INSTALL_DIR)/rllutils.temp"

install:
	@echo installing EasyATP ...
	cp bin/easyatp.exe "$(INSTALL_DIR)/bin"
	./bin/installer.exe "$(INSTALL_DIR)/bin/easyatp.exe"

	@echo done

uninstall:

	rm "$(INSTALL_DIR)/rllutils.temp"
	./bin/uninstaller.exe
	rm -r "$(INSTALL_DIR)"

	@echo done
