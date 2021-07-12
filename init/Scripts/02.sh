# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    02.sh                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 18:30:50 by dieroyer          #+#    #+#              #
#    Updated: 2019/03/27 18:33:44 by dieroyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

a="1"
while [ $a != "2" ]
do
	echo "The 02.sh file allows you do delete a user, do you wish to continue ? yes/no\n"
	read rep
	if [ $rep = yes ]
	then
		list=`who | awk '{print $1}'`
		echo "List of users:\n$list\n"
		echo "What user do you wish to destroy ?"
		read who
		for i in $list
		do
			if [ $i = $who ]
			then
				userdel $who
				echo "User $who as been destroyed"
			else
				echo "There is no such user here"
			fi
			done
		else if ([ $rep != no ] && [ $rep != yes ])
	then
		echo "TRY AGAIN\n"
	else
		echo "The program will close, bye :*"
		a="2"
	fi
	fi
done
