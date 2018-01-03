# class-maker
Create C++ class header/source files using the command line


# Using the script
Change the my_name variable to your name, and compile with  `g++ class.cpp -o class`. 

You can also add the executable to your path so that you can call `class SomeClass` from anywhere.

The executable takes one argument, a class name, without any file extension.

__Example input__:

```bash
me@my-computer:~/Folder$ class ExampleClass
Successfully created exampleclass.cpp and exampleclass.h.
```
Where `exampleclass.h` contains
```C
// exampleclass.h
// My Name, 3/1/2018
#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

class ExampleClass
{
// Private variables
private:

// Public variables
public:

// Private methods
private:

// Public methods
public:

};

#endif //EXAMPLECLASS_H
```
