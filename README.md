# LLVM
![cpp-badge](https://img.shields.io/badge/Solutions-blue?logo=C%2B%2B
)
![docker-badge](https://img.shields.io/badge/Build%20with-green?logo=docker
)
## Table of Contents
 - [About the Project](#about-the-project)
 - [Author](#author)

## About the project
This repository is dedicated to the LLVM project, a component of the Master's course in Software Engineering. The primary objective of this course was to develop a testing tool utilizing LLVM and to implement range validation for programming languages such as C, C++, and Golang.

The repository is structured into two main directories. The first directory contains the implementation of KLEE, a symbolic virtual machine built on top of the LLVM compiler infrastructure. KLEE is designed to automatically generate tests that achieve high coverage on a diverse set of complex and environmentally-intensive programs.

The second directory houses the LLVM tools developed to examine and validate the range of C++ vectors and memory. These tools are instrumental in preventing common programming errors like buffer overflows and underflows, thereby enhancing the safety and reliability of C++ programs.

## Author
Timothy Hwang