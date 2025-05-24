#!/bin/sh

filesdir=$1
searchstr=$2

if [ "$filesdir" = "" ] || [ "$searchstr" = "" ]; then
	echo "One of the parameters are not specified"
	exit 1
elif [ ! -d $1 ]; then
	echo "$1 is not a directory"
	exit 1
fi

echo "Path to directory $filesdir"
echo "Text string which will be searched $searchstr"

NUMFILES=$(find $filesdir -type f | wc -l )
MATCHSTR=$(grep -r $searchstr $filesdir | wc -l)

echo "The number of files are ${NUMFILES} and the number of matching lines are ${MATCHSTR}"
