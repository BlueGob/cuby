install:
	@gcc source-code/cuby.c -o cuby
	@mkdir algorithms
	@chmod +x script.sh
	@./script.sh
	@rm algorithms/cuby
	@echo "Cuby has been installed succesfully"
remove:
	@rm -r algorithms/
	@rm cuby
	@chmod -x script.sh
	@echo "Cuby has been removed from your computer"
update:
	@./script.sh
	@echo "Cuby has been updated succesfully"