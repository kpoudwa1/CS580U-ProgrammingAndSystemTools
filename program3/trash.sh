#!/bin/bash

#For moving the object files (except hidden.o) and executables in the TRASH folder
#To check if the file exists and move it to the TRASH directory

for i in $@
do
	if [ -f $i ]
	then
		if [ -d TRASH ]
		then
			mv $i TRASH/
			echo "File $i has been moved to TRASH folder"
		else
			mkdir TRASH
			echo "The directory 'TRASH' has been created"
			mv $i TRASH/
			echo "File $i has been moved to TRASH folder"
		fi
	else
		echo "File $i does not exists !"
fi
done

#To delete the files in the trash directory whose last modified time is older than an hour
LIST=`find TRASH/ -mmin +60`
#LIST=`find TRASH/ -mmin -60`
#Flag for checking if there are files whose last modified time is greater than an hour
flag=0

for i in $LIST
do
	flag=1
	#Do not delete the TRASH directory
	if [ $i != "TRASH/" ]
	then
		rm -rf $i
		echo "File $i deleted from the TRASH folder"
	fi
done

if [ $flag -eq 0 ]
then
	echo "Currently there are no files older than an hour in the TRASH folder !"
fi
