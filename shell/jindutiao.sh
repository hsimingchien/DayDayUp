#!/bin/bash

# progressbar.sh
# print a progress bar
#
# Author: Jerry Fleming <jerryfleming2006@gmail.com>

function progress()
{
	i=0
	bar=''
	index=0
	arr=( "|" "/" "-" "\\" )
	while [ $i -le 100 ]
	do
		let index=index%4
		printf "\e[43;46;1m%c\e[0m %-100s %3d%%\r" "${arr[$index]}" "$bar" "$i"
		let i++
		let index++
		usleep 30000
		bar+='#'
	done
	printf "\n"
}

progress

exit 0
