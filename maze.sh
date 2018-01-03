#!/bin/bash
#The statement above is the mandatory first line of all (Bash) script files.

#This is a script file formatted for use by the Bash shell.

#Author: Elias Perez
#Course: CPSC 223c
#Semester: 2017 Spring
#Date: 13 May 2017


#First erase any old object files and old executable files, if any exist from past compilations
rm *.o

rm maze


gcc -g -c leftTurn.c -o leftTurn.o 

gcc -g -c rightTurn.c -o rightTurn.o 

gcc -g -c rightsideBlocked.c -o rightsideBlocked.o

gcc -g -c leftsideBlocked.c -o leftsideBlocked.o

gcc -g -c frontBlocked.c -o frontBlocked.o

gcc -g -c showMaze.c -o showMaze.o 

gcc -g -c maze.c -o maze.o 

gcc -g -c fillMaze.c -o fillMaze.o

gcc -g -c random.c -o random.o

#Next link four object files together and execute file
g++ *.o -o maze


echo The mouse maze program has terminated.




