![](assets/ascii-death-star_cpp_banner.png)

Introduction
============

This is the central student repository for the module UFCFGL-30-1,  Programming
in C++, forming the base for the 6 challenges and assignment. Each student
should "fork" their own copy at the beginning of the module, and perform updates
each week as new material is provided as the course develops.

Challenges
==========

As described in the modules handbook (add link), there are 6 challenges that
must be completed:

* [Challenge 000](https://blackboard.uwe.ac.uk/webapps/assignment/uploadAssignment?content_id=_5772054_1&course_id=_287254_1&group_id=&mode=cpview)
* [Challenge 001](https://blackboard.uwe.ac.uk/webapps/assignment/uploadAssignment?content_id=_5772059_1&course_id=_287254_1&group_id=&mode=cpview)
* [Challenge 010](https://blackboard.uwe.ac.uk/webapps/assignment/uploadAssignment?content_id=_5772061_1&course_id=_287254_1&group_id=&mode=cpview)
* [Challenge 011](https://blackboard.uwe.ac.uk/webapps/assignment/uploadAssignment?content_id=_5772543_1&course_id=_287254_1&group_id=&mode=cpview)
* [Challenge 100](https://blackboard.uwe.ac.uk/webapps/assignment/uploadAssignment?content_id=_5772547_1&course_id=_287254_1&group_id=&mode=cpview)
* [Challenge 101](https://blackboard.uwe.ac.uk/webapps/assignment/uploadAssignment?content_id=_5772552_1&course_id=_287254_1&group_id=&mode=cpview)

The details of each challenge and how to submit your completed work is
documented in the above links. For all but the first challenge you are required
to write one or more programs in the C++ programming language, solutions for
each challenge will be provided following the submission deadline, appearing in
the directory *solutions* in this repository.

As most challenges will expect to you develop programs, the corresponding source
code used for the programs should be stored in your copy of this repository,
under the directory challenges. To help support this a utility program,
*create_challenge*, is provided in the repository's *bin* directory. You can
run this program at the command line, from the repository's root directory,
with the command:

```bash
bin/create_challenge
```

As no arguments are provided this will ouput the programs "usage":

```bash
usage name author
```

This command can be used to create an empty program for a challenge, for
example, if the required to implement a program *foo* for a given challenge,
then you can use the command:

```bash
bin/create_challenge "FirstName LastName" foo
```

Note, the use of the speech marks around the name, this makes it a single
argument to *foo*, otherwise the space would imply multiple arguments.

After running this command a new directory, *foo*, will be added under the
directory *challenges*, which includes a *Makefile*, used to build your program,
an initial source file, *main.cpp*. You change into that directory with the
command

```bash
cd challenges/foo
```

Once there you can build the program with the command:

```bash
make
```

This creates a directory *build*, which contains the interminate files needed
to build the application and the program itself. The program can be run with the
command:

```bash
./build/foo
```

Before you modify the program it will display the output:

```bash
Now implement your code!
```

At this point you are ready to begin work on the challenge itself, following
the instructions in the corresponding link from above.

Bin directory
=============

The *bin* directory provides a number of programs, some of which  demonstrate
the behaviour of programs required to be implemented as part  of a given
challenge, others can be used to generate input and other aspects  needed to
test a challenge's solution, and there are also some utility programs to help
throughout the module.

Support Library Documentation
=============================

To help you develop solutions to the challenges and the course assignment a
number of support libraries are provided. Documentation on the different
libraries, how to use them in your programs can be found in the docs directory
and the root [docs/index.html](docs/index.html) page.


