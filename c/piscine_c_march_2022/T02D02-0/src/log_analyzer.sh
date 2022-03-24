#!/bin/bash

# bash unofficial strict mode
set -euo pipefail;

# public
PATH="${1:-""}";

# private
LINES=0;
FILES=();
HASHES=();

show_usage()
{
	echo;
	echo "$(/usr/bin/basename "$0") - script for analyzing the log file";
	echo -e "Usage:\n\t$0 [path to log file (relative to root!)]";
	echo -e "Example:\n\t$0 \"/Users/griselle/dev/T02D02-0/src/files.log\"";
	exit 0;
}

if [[ -z "$PATH" ]];then
	show_usage;
elif [[ ! "$PATH" =~ ^/ ]];then
	echo "Error! Path must be relative to root!";
	show_usage;
elif [[ ! -f "$PATH" ]];then
	echo "Error! File $PATH isn't available!";
	show_usage;
fi

# reading file line by line
while read -r CUR;do
	((LINES++));
	FILENAME="$(/usr/bin/awk '{print $1}' <<< "$CUR")";
	HASH="$(/usr/bin/awk '{print $8}' <<< "$CUR")";
	if [[ -z "$FILENAME" ]] || [[ -z "$HASH" ]];then
		echo "Error while parsing $PATH";
		exit 1;
	fi
	FILES+=( "$FILENAME" );
	HASHES+=( "$HASH" );
done < "$PATH";

# uniquing array with filenames and array with hashes
FILES=( $(printf "%s\n" "${FILES[@]}" | /usr/bin/sort -u) );
HASHES=( $(printf "%s\n" "${HASHES[@]}" | /usr/bin/sort -u) );

# output
printf "%s %s %s\n" "$LINES" "${#FILES[@]}" "${#HASHES[@]}";
