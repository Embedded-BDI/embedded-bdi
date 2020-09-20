## Description

Master's thesis on programming of embedded agents using propositional logic & BDI architecture for embedded systems.

[GitHub repository](http://github.com/matuzalemmuller/embedded-bdi)

## Requirements:
* [OpenJDK](https://openjdk.java.net/) (or [Java SDK](https://www.oracle.com/java/technologies/javase-downloads.html)).
* C++11 compiler. [g++ 4.9 or later](https://gcc.gnu.org/gcc-4.9/changes.html) is recommended as the [Makefile](Makefile) is based on that compiler, otherwise modifications in the [Makefile](Makefile) will be necessary to run the project from command line.
* (Recommended) [Doxygen](https://www.doxygen.nl/index.html) for documentation generation.
* (Recommended) [Graphviz](https://graphviz.org/) for UML/chart support in documentation.

## Documentation

HTML documentation can be generated using [Doxygen](https://www.doxygen.nl/download.html). To generate the documentation, simply run `make docs` at the root folder of the repository or check the [docs](docs/) folder for more details.

## Building Agent

See the [usage](Usage.md) documentation for more information.

## Unit Tests

[CircleCI](https://circleci.com/) is used for continuous integration and all code committed to the `master/main` branch passed Unit Tests. To run the tests locally, run `make tests` and then run the binary available at `build/unittest.out`.