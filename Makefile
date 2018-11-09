
ifeq ($(OS),Windows_NT)
	ARG := g++ main.cpp functions.cpp -o main.exe
	ARG1:= g++ -g main.cpp functions.cpp -o dmain.exe
else
	ARG := g++ main.cpp functions.cpp -o main
	ARG1:= g++ -g main.cpp functions.cpp -o dmain
	ARG2:=gnome-terminal -- ./main #
endif


all:
	@echo start compiling
	@$(ARG)
	@$(ARG1)
	@$(ARG2)
	@echo Compiled succesfully