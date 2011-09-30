#!/bin/sh

CPP="/usr/local/bin/g++46"
TARGET_PATH="/srv/.nginx/"

mkdir -p $TARGET_PATH

export LDFLAGS="-Wl,--gc-sections"

${CPP} -Wall -pedantic -pipe -O2 -march=native -mtune=native -fomit-frame-pointer -Wl,--gc-sections -ffunction-sections -fdata-sections -o ${TARGET_PATH}spawn spawn.cpp
${CPP} -Wall -pedantic -pipe -O2 -march=native -mtune=native -fomit-frame-pointer -Wl,--gc-sections -ffunction-sections -fdata-sections -o ${TARGET_PATH}geoupdater geoupdater.cpp

cp spawn.db ${TARGET_PATH}

chown www:www ${TARGET_PATH}spawn
chmod a+x ${TARGET_PATH}spawn
chown root:wheel ${TARGET_PATH}geoupdater
chmod a+x ${TARGET_PATH}geoupdater


