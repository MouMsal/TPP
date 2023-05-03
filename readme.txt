

CPU:
For my CPU, I created functions that resemble CPU instructions. These functions work by accessing my
memory class which allocates memory every time I create a variable of type Integer, Decimal, or PreciseDecimal.
In the future,I will be able to expand this to handle strings.
I am using templates to make these functions for all of these datatypes.

Memory:
In my memory class, I have a resize function, that initially resizes the vector to allow values to be assigned
to specific addresses without using pushback, an allocateMemory function that allocates memory every time I create a
variable, and a getVal function that returns a reference allowing me to modify and get data using that function. This
function also takes care of casting the right datatype and indexing so that addresses don't overlap. I use templates
to allow any of my datatypes to work.

Main:
This contains all of my overloaded functions including my output (std::cout), input (std::cin) and my disp() function,
(which is kind of redundant now, but you can still use it.) These are located in my namespace.
I have three big classes, Integer, Decimal, and PreciseDecimal. They are essentially all the same with minor modifications.
In them, I have a default and a non-default constructor. They both allocate memory but my non-default constructor allows
me to initialize my variable if necessary. They also contain overloaded = operators which call my CPU function store()
that allows me to modify my data. In my main(), I have a short leap year program that calculates the leap year based on
the data the user inputs. I know my if statement is not the correct way of doing it like an assembler does, but that is
what I can do with the time I have. I made it by creating a macro at the top.

Below that I have my overloaded functions which all work relatively the same way. The CPU retrieves a value by using the
address provided and use typeof to match the correct datatype for the load function. I do a cast for functions that I don't
want to allow many datatypes as I don't feel like dealing with the headache, but that's pretty much all.





Resources that I remember using:
http://eceweb.ucsd.edu/~gert/ece30/CN2.pdf
Learned:
How to use templates properly and how they work.
Polymorphism in more depth.
A decent amount about assembly,virtual machines, parsers, and assemblers.
Memory Allocation and Management
Instruction encoding
A lot of other stuff that I can't think of at the top of my head.