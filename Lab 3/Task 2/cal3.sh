#!/bin/bash

if [ -z $1 ]; then 		#if 1st argument isn't set, then exits script

	echo you must provide at least one month

	exit 0

fi


if [ -n "$2" ]; then	#if 2nd argument is set, then script exits

	echo error, only give one argument

	exit 0
 
fi
cal $1 $(date +'%Y')	#calls the cal function with the given argument as the month, and the current year as the year

