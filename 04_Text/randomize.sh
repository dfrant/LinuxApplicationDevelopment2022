#!/bin/bash

if [ -z $1 ]; then
    DELAY=0.05
else
    DELAY=$1
fi

INPUT=$(cat - | od -t x1 -An -w1 -v)
MAP=""
Y=0
X=0
while read -r CHAR; do
    if [ $CHAR = '20' ]; then
        ((X++))
	continue
    fi

    if [ $CHAR = '0a' ]; then
        ((Y++))
	X=0
	continue
    fi

    MAP="${MAP}${X} ${Y} ${CHAR}\n"
    ((X++))
done <<< $INPUT

MAP="$(echo -ne "$MAP" | shuf)"

tput clear
while read -r A B S; do
    tput cup "$B" "$A"
    echo -ne "\x${S}"
    sleep $DELAY
done <<< $MAP

tput cup $Y 0
