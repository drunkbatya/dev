#!/bin/bash

# bash unofficial strict mode
set -euo pipefail

# public
PATH="${1:-""}";
STR="${2:-""}";
REPL="${3:-""}";

# private
PATH_TO_SRC="$(/usr/bin/dirname "$0")";

show_usage()
{
	echo;
	echo "$(/usr/bin/basename "$0") - replace substrings in text file. Writing changelog to $PATH_TO_SRC/files.log";
	echo -e "Usage:\n\t$0 [path to file(relative to the root!)] [string to be replaced] [replacement]";
	echo -e "Example:\n\t$0 \"/Users/griselle/dev/T02D02-0/src/history_of_vi.txt\" \"today\" \"yesterday\"";
	exit 0;
}

if [[ -z "$REPL" ]];then
	show_usage;
elif [[ ! "$PATH" =~ ^/ ]];then
	echo "Error! Path must be relative to root!";
	show_usage;
elif [[ ! -f "$PATH" ]];then
	echo "Error! File $PATH isn't available!";
	show_usage;
elif [[ "$STR" == "$REPL" ]];then
	echo "Error! String to be replaced must not be equal replacement!";
	show_usage;
fi

replace_one_string()
{
	/usr/bin/sed -i '' -e "1 s/$STR/$REPL/; t" -e "1,// s//$REPL/" "$PATH";
}

write_log()
{
	local SIZE;
	local SUM;
	local DATE;
	local OUT_STR;

	SIZE="$(/usr/bin/stat -f %z "$PATH")";
	SUM="$(/usr/bin/shasum -a 256 "$PATH" | /usr/bin/awk '{print $1}')";
	DATE="$(/bin/date "+%Y-%m-%d %H:%M")";
	OUT_STR="$PATH - $SIZE - $DATE - $SUM - sha256"
	echo "$OUT_STR" >> "$PATH_TO_SRC/files.log";
}

while (/usr/bin/grep -q "$STR" "$PATH");do
	replace_one_string;
	write_log;
done
