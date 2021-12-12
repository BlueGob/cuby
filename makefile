install:
	@gcc source-code/cuby.c -o cuby
	@mkdir algorithms
	@chmod +x script.sh
	@./script.sh
	@rm algorithms/cuby
	@echo "Cuby has been installed succesfully"
