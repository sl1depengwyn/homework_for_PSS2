## About

This is a system for taxi app.

Many thanks to the contributors!

## Details

My system has the following features:

It registers users and save them to database.

It creates orders and manipulates them keeping all necessary information in database.

It has rating system.

## Dependencies
sqlite_orm/1.6


## Usage



```shell script
cd ../hw4/modules
conan install .. --build=missing
cd ..
cmake . -DCMAKE_MODULE_PATH:FILEPATH="../path/to/conan/generated/libs"
```
