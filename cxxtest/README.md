# Command Line
## Installation on Mac OSX/Linux
### Easy Way
run the following command in your terminal

Mac OSX
```bash
brew install cxxtest
```

Linux (not tested yet but should be working)
```bash
apt-get install cxxtest
```

### Hard Way
download the source code [here](https://sourceforge.net/projects/cxxtest/files/cxxtest) and extract it to a place that you would never move it

under your root directory, create a file .bash_profile with text editors and enter the following script

```bash
export PATH=PATHTOYOUREXTRACTEDFOLDER/cxxtest/bin:$PATH

export CXXTEST=PATHTOYOUREXTRACTEDFOLDER/cxxtest
```

## Usage
In order to implement the unit testing with cxxtest, run the following command in your project directory

```bash
cxxtestgen --error-printer -o THEOUTPUTFILE.cpp YOURTESTFILE.h

g++ -o OUTPUTPROGRAM THEOUTPUTFILE.cpp FILEBEINGTESTED.cpp (if installing easy way)

or

g++ -o OUTPUTPROGRAM -I$CXXTEST THEOUTPUTFILE.cpp FILEBEINGTESTED.cpp (if installing hard way)
```

the argument THEOUTPUTFILE would be the generated .cpp file to be compiled with the second command

OUTPUTPROGRAM is the name of the executable program after compiled

-I flag indicate the library to be include when compiling, $CXXTEST is the path to the installtion of your cxxtest library

