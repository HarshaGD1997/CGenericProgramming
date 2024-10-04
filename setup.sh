#!/bin/bash

if [ -z "$1" ]; then
	echo "Provide path as an argument."
	exit 1
fi

FOLDER_PATH="$1"

if [ ! -d "$FOLDER_PATH" ]; then
	echo "Path does not exist or is not directory."
	exit 1
fi

if [ -z "$(find "$FOLDER_PATH" -mindepth 1 -type d)" ]; then
	echo "Creating 'bin', 'include', and 'src'"

	mkdir -p "$FOLDER_PATH/bin"
	mkdir -p "$FOLDER_PATH/include"
	mkdir -p "$FOLDER_PATH/src"

	echo "SubFolders created successfully."
else
	echo "Aldready contains subfolders."
fi
