#!/usr/bin/env bash

SOURCES=$(find src -name "*.java")
TESTS=$(find test -name "*.java")
rm -rf classes
mkdir -p classes
javac -cp "lib/*:." -d classes $SOURCES
javac -cp "classes:lib/*" -d classes $TESTS

rm -f java_set_submit.zip
zip -q -r java_set_submit src
