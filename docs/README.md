### Generate Documentation

Download and install [Doxygen](https://www.doxygen.nl/download.html) and run the command below.

```
doxygen Doxygen.doxyfile
```

To generate the UML diagrams, install [Graphviz](https://graphviz.org/) and make sure that the correct path to `dot` is added in the `DOT_PATH` entry of the `Doxygen.doxyfile` file.

```
DOT_PATH               = /usr/local/bin/dot
```