#!/bin/bash

PID="$(ps aux | grep "ai_door_control.sh" | grep -v "grep" | awk '{print $2}')";

if [[ -n "$PID" ]];then
	kill -9 "$PID";
fi
