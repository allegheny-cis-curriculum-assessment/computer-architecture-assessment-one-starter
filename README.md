# 🚀 Evalugator Assessment

![Platforms: Linux, MacOS, Windows](https://img.shields.io/badge/Platform-Linux%20%7C%20MacOS%20%7C%20Windows-blue.svg)
[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://www.open-std.org/jtc1/sc22/wg14/)
[![Hardware: Raspberry Pi Pico](https://img.shields.io/badge/Hardware-Raspberry%20Pi%20Pico-e30b5d.svg)](https://https://www.raspberrypi.com/products/raspberry-pi-pico/)

## ⚠️ Notes about this assessment

### Taking this assessment

Unlike other assessments given to Allegheny College Department of Computer 
and Information Science courses, this assessment requires:

* Raspberry Pi Pico hardware
* Raspberry Pi Pico SDK
* A GCC cross-compiling toolchain [detailed here](https://github.com/allegheny-college-cmpsc-200-fall-2023/course-materials/wiki/00-Installing-Toolchains)

This assessment also _does not use_ GitHub CodeSpaces due to the need for physical
hardware and individual machine-level setup.

### Assessing your progress

This assessment relies on several background processes to compile, run, and
self-evaluate. It is possible that you may not be able to fully assess your 
progress on your `clone`d copy of this repository. The GitHub Actions workflow
for evaluating this work can take nearly 6 minutes to complete.

Focus on the `TODO`s in [`assessment.c`](source/assessment.c) with the goal
of producing a program that `print`s a series of statements that average
line-by line. A successful running program resembles the following:

```bash
AVERAGE: 1.0031 kWs
AVERAGE: 1.0024 kWs
...
```

The numbers above may not match your output exactly, but are close enough
to be a representative sample.

## Table of Contents

* [✨ Quick Task List](#-quick-task-list)
* [🧗 Introduction](#-introduction)
* [🚧 Honor Code](#-honor-code)
* [🌐 Assessment Overview](#-assessment-overview)
* [🔬 Assessment Details](#-assessment-details)
* [📙 Learning Objectives](#-learning-objectives)

## ✨ Quick Task List

- [ ] Read the `Introduction` section for a brief overview
- [ ] Read the `Honor Code` section and then digitally sign your pledge
- [ ] Complete the requested programming tasks in the `assessment.c` file
- [ ] Use the VS Code `Run and Debug` menu to run the program using the `Pico Debug` configuration
- [ ] Type `gatorgrade` in the terminal to assess the quality of the solution
- [ ] Frequently use Git to `commit` and `push` your work to the repository
- [ ] Complete all assignment these tasks using your Raspberry Pi Pico hardware device
- [ ] Read all of the content in this `README.md` file for more details
- [ ] Ask a professor if you have any questions about this assessment
- [ ] Complete as much of the assessment as you can in fifty minutes

## 🧗 Introduction

If you are a student completing this assessment as part of a class at Allegheny
College, you will need to complete the programming tasks according to the
instructions inside of the `assessment.py` Python source code file in the
`source/` directory of this repository. If you have questions about this
assessment, please see the course instructor during the assessment time period.
You must read and ensure that you understand all of the instructions in this
file before starting the assessment.

## 😁 Note:vAdd Your Name Here

Note: You must delete `Add Your Name Here` add your name to the subsection header

## 🚧 Honor Code

- You **must** adhere to the Honor Code throughout your completion of the assessment
- You **must** answer all of the questions in the assessment using your own source code and documentation
- You **must** use your laptop computer and the web-based GitHub Codespaces development environment
- You **may** use any software development tools that are available to you through GitHub Codespaces
- You **may** use any automated code and/or documentation generation tools to which you have access
- You **must** cite the source of any program code or documentation generated by any software tool
- You **must** cite any references that you consult to aid you in completing this assessment
- You **may not** discuss any aspect of the assessment with anyone except the course instructor
- You **may not** modify any part of the provided source code in the `evalugator/` directory

**IMPORTANT**: All students in this course are obligated to adhere to the
Allegheny College Honor Code throughout the completion of this assessment. If
the instructor detects that a student has committed a likely violation of the
Allegheny College Honor Code, this will result in the filing of a report with
the Dean of Students Office and the furnishing of all details about the likely
violation. Please make sure that you review the [Allegheny College Honor
Code](https://sites.allegheny.edu/about/honor-code/) before you start to take
this assessment.

## 🌟 Re-type the sentence "I adhered to the Allegheny College Honor Code while completing this assessment."

Note: You must retype the sentence here in order to digitally sign your pledge.

`TODO: Retype the sentence above.`

**IMPORTANT:** If you do not type the required sentence then the course
instructor will not know that you adhered to the Allegheny College Honor Code
while completing the assessment.

## 🌐 Assessment Overview

- **Assessment Released**: At the start of your class session
- **Assessment Due**: At the end of your class session

**Please note that your `git push` access to the GitHub repository containing
the assessment will be disabled after the assessment's due date.**

- The assessment is out of a total of 100 percent, with an automatically reported percentage.
- You must provide answers to all these questions by typing in the `assessment.py` Python source code file.
- The final version of the Python source code file must be in your GitHub repository by the due date.
- You may run the provided Python program in the GitHub Codespaces terminal by using the `python source/assessment.py` command.
- You may run the automated assessment in the GitHub Codespaces terminal by using the `gatorgrade` command.
- Unless you already made special arrangements with the instructor, no late work will be accepted for this assessment.
- You may review details from running the automated assessment in GitHub by using the GitHub Actions tab.
- You may talk to the course instructor if you have questions about or you need troubleshooting help with this assessment.

## 🔬 Assessment Details

After accepting the assignment and opening it in GitHub Codespaces, please follow these instructions:

- Study the instructions and source code for the assessment that are available in this file: `assessment.py`
- For each file there are six sub-parts, denoted as `Part One` through `Part Six` in the provided Python source code.
- Following the instructions for each sub-part, you should provide and/or modify the requested function(s) so as to
ensure that they meet the specification. When you read the commented source code for each sub-part you will see examples
of what output the requested function will produce when it is provided with the given input(s).
- Generally, the instructions for each sub-part will invite you to write, repair, or reorder the requested function.
- Using a terminal window in GitHub Codespaces, you can run the assessment program by typing the following command from
the root of this GitHub repository: `python source/assessment.py`
- When you run a program in the terminal window using the aforementioned command, each of the assessment's sub-parts
will produce a single line of output.
- Using a terminal window in GitHub Codespaces, you can assess your work and see the status of each check by typing the
following command from the root of this GitHub repository: `gatorgrade`
- Using the comments in the source code as a guide, you can confirm that the functions are producing the expected output.
- After committing and pushing your code, you can review the output from running GatorGrader in GitHub Actions. If one
of the functions is not producing the correct output and/or one of the GatorGrader checks is not passing correctly, you
may make an unlimited number of re-attempts during the time designated for completing this assessment.
- Please completely delete the `TODO` markers and their labels from all of the provided source code. This means that
instead of only deleting the `TODO` marker from the code you should instead delete the `TODO` marker and the prompt and
then add your own comments to demonstrate that you understand all of the source code in this assessment.

## 📙 Learning Objectives

The work that you complete for this assessment will not in any way influence
your grade in the Databases course. You are taking this
assessment to measure achievement of the following learning objectives
necessitated by **Program Outcome 1** for **all majors** offered by the
Department of Computer and Information Science. Please review the following
explanations for more details.

- Learning Objectives for the **CMPSC 200** Course:

    - **LO 1**: Write a step-by-step description that explains how programs written in high-level computer programming languages execute through the use of lower-level computer circuitry.
    - **LO 2**: Identify the levels of the memory hierarchy and explain the implications of using the various levels to implement high-performance programs.
    - **LO 3**: Develop C and Assembly language programs that use the appropriate levels of the memory hierarchy and processor registers to create performant, executable programs and arithmetic logic units.
    - **LO 4**: Describe and use parallel processing techniques to increase a program’s performance and efficiency.
    - **LO 5**: Integrate hardware and software components using original C and Assembly language code to develop hardware-based, performant computational projects.

- Program Outcome 1 for the **Computer Science** Major:

    - **PO1**: Demonstrate and be able to communicate the knowledge of data types, algorithms, and mathematical principles behind discrete objects.

    - **Covered By**: LO3, LO4
