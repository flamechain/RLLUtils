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
	-touch "$(INSTALL_DIR)/rllutils.temp"

install:
	@echo installing EasyATP ...
	@make -s -f src/EasyATP/Makefile all

	@echo installing IPHelper ...
	@make -s -f src/IPHelper/Makefile all

	@echo done

uninstall:

	rm "$(INSTALL_DIR)/rllutils.temp"

	@make -s -f src/IPHelper/Makefile uninstall
	@make -s -f src/EasyATP/Makefile uninstall
	-rm -r "$(INSTALL_DIR)"

	@echo done
