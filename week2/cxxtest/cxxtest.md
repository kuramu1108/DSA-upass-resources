### Command Line
In order to implement the unit testing with cxxtest, run the following command in your project directory

```bash
cxxtestgen --error-printer -o runner YOURTESTFILE.h

g++ -o runner -I$CXXTEST runner.cpp
```

the argument runner would be the generated .cpp file to be compiled with the second command

$CXXTEST is the path to the installtion of your cxxtest library
