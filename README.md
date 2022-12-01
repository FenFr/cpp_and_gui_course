<div align = "center">
    <h1> C++ / GUI </h1>
    <h3> This is my Repository for the C++ / GUI course at my University. </h3>
</div>

&nbsp;

<div align = "center">

![Code Size][code-size-img] &nbsp; ![Code File Size][code-file-img] &nbsp; ![Lines of Code][code-lines-img]

</div>

## QMake

### Installing in Ubuntu

In the Terminal, type in:
```
$ sudo apt-get install qtbase5-dev
```

### Compiling

To compile the Tutorial-Code you have to add the following line to the .pro files:
```
QT += widgets
```

**Compiling your code**
```
$ qmake
$ make
```

<!-- Link anchors -->

[code-size-img]:    https://img.shields.io/github/languages/code-size/FenFr/cpp_and_gui_course?label=Code%20Size&style=flat-square
[code-file-img]:    https://img.shields.io/github/directory-file-count/fenfr/cpp_and_gui_course?label=Files&style=flat-square
[code-lines-img]:   https://img.shields.io/tokei/lines/github/fenfr/cpp_and_gui_course?label=Lines%20of%20Code&style=flat-square