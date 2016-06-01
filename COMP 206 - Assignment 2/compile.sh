#!/bin/bash

#Ravi Chaganti
#ID:260469339

alias compile=~/comp206/project/source/ass2/compile.sh

L1="Syntax of the compiler---->  $ compile -o filename -clean -backup -archive -help cfilenames"
L2="1. $: Unix prompt"
L3="2. compile: name of your bash program"
L4="3. -o filename: mandatory argument that indicates the name of the executable"
L5="4. -clean: optional; deletes all the .o files before compiling"
L6="5. -backup: optional; copies all the .c and .h files into your backup directory"
L7="6. -archive: optional; TARs all the contents of your source directory"
L8="7. -help: how to use bash compile"
L9="8. cfilenames: list of source files that will be compiled together"

L10="You should pass at least 1 argument. See the following syntax and the functions: "
L11="You are missing -o filename, which is mandatory. See the following syntax and functions: "
L12="All the .o files have been deleted"
L13="All the .c and .h files have been backed up"
L14="All the contents of the source directory are TARed"



#HELP function describes all the functions of the compiler
 
function HELP() {
	echo "$L1"
	echo "$L2"
	echo "$L3"
	echo "$L4"
	echo "$L5"
	echo "$L6"
	echo "$L7"
	echo "$L8"
	echo "$L9"
}  

if [[ $# == 0 ]]	#If no arguments are passed
then
	echo "$L10" 
	HELP

elif [[ $1 != '-o' ]]		#If no executable file name is given
then
	echo "$L11"
	HELP

else
	file_name="$2"
	shift
	shift

	for f in "$@"
	do

		if [[ $f == '-clean' ]]		#If clean function is called
		then
			rm -f -r *.o	#removes all .o files
			echo "$L12"
			shift
		fi

		
		if [[ $f == '-backup' ]]	#If backup function is called
		then
			cp *.[ch] ~/comp206/project/backup	 	#copies all files into the backup directory
			echo "$L13"
			shift
		fi


		if [[ $f == '-archive' ]]	#If archive function is called
		then
			tar -cf sourcefiles.tar *		#TARs all the files
			mv sourcefiles.tar ~/comp206/project/archive		#moves  sourcefile.tar to archive directory  
			echo "$L14"
			shift
		fi


		if [[ $f == '-help' ]]		#If help function is called
		then
			HELP			#displays all the contents in HELP function
			shift
		fi

	done	


	gcc -c $*
	gcc -o $file_name $*
	#gcc -o $2 `ls | grep .o` 

fi
	

