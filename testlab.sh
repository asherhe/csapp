# cd to current directory
cd $1
# Every lab has a makefile that does stuff
make
# Now execute the tests
./btest
./dlc -e $2