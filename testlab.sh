# cd to lab directory
cd $1
# Every lab has a makefile that does stuff
make
# Now execute the tests
./btest
./dlc -e $2 # count operator count in code
