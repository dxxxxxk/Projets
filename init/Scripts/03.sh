#!/bin/bash

a="1"
moi=`whoami`
while [ $a != "2" ]
do
	echo "Hi $moi,\nWould you like to send a mail? yes/no\n"
	read rep
	if [ $rep = yes ] || [ $rep = y ]
	then
		echo "Who do you want to send it to?\nEnter his LOGIN:\n"
		read login
		echo "Right the message you wish to send:\n"
		read message
		echo "Right the subject:\n"
		read subject
		echo "$message" | mail -s "$subject" $login@student.42.fr
		echo "\n\033[0;32m\nMail sent\033[0m"
		a="2"
		if [ $a != 2 ]
		then
			echo "\n\033[0;31mWARNING ERROR\033[0m"
		fi
	else
		a="2"
		echo "\n\033[0;46mEnd.\033[0m"
	fi
done
