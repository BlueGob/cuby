# cuby
this is an alogrithm for scheduling processes based on config file and using algorithms fifo/sjf/round robin/..
this project is developped using make file and C under linux.
i love to call it cuby 👊
## installation
you only need to copy and paste this line to install 

```bash
make install
```
this command will compile all the source code in source-code folder and create algorithms directory and put all the compiled code inside of it. 

## how to use

### config file
cuby need a config file to work it's called **config.conf** in which we define the processes.

you need to put one process per line in this order **name-priority-arrivalTime-cpuTime** and don't forget the **-** between each attribute
for exemple : p1-1-0-5

*note*: you can put comments inside config file with # as the first caracter in the line

### run
cuby need config file as parameter so you can simply run it with :

```
./cuby config.conf
```
after that you can type **help** to see what cuby has to offer

![2022-05-06_15-38](https://user-images.githubusercontent.com/59932913/167206087-a53db4ac-a3a4-4fcb-9b9a-999f03430bda.png)

so we have
- menu: to display the available cpu scheduling algorithms  
- clear : to clear screen
- config : to display the config file
- 1 .. n : to choose one between the cpu scheduling algorithms 

For exemple we choose the first algorithm 

![2022-05-06_15-42](https://user-images.githubusercontent.com/59932913/167206595-ac0312b3-e43c-4996-a22e-7c639ef1a74d.png)

wee see the GANTT diagram of the execution .

## additional information

### make file
make file has 3 command 
```
make install 
```
which i talked about in the installation
```
make remove
```
to remove the compiled files
```
make update
```
this commande will recompile the source code in case you change something or you add new cpu scheduling algorithm

### add your algorithm

you can add your own algorithms inside source code and update with **make update** and it will be automatically added in the menu

