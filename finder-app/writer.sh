#!/bin/sh

writefile=$1
writestr=$2

if [ "$writefile" = "" ] || [ "$writestr" = "" ]; then
	echo "One of the parameters are not specified"
	exit 1
fi

dirname "$writefile"

[ ! -d $(dirname "$writefile") ] && mkdir -p $(dirname "$writefile")

touch "$writefile"
echo "$writestr" > $writefile
