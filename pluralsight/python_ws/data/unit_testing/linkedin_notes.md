## What is unit testing?

**Why do we unit test?**
- Software bugs hurt the business!
- Software testing catches the bugs before they get to the field
- Need several levels of safety nets

**Levels of testing**
- **Unit Testing** - Testing at the functional level.
- **Component testin** - Testing is at the library and compiled binary level.
- **Systen testing** - Tests the external interfaces of a system which is a collection of sub-systems.
- **Performance testing** - Testing done at sub-system and system levels to verify timing and resource usages are acceptable.

**Unit testing specifics**
- Tests individual functions.
- A test should be written for each test case for a function (all positive and negative test cases).
- Groups of tests can be combined into test suites for better organization.
- Executes in the development environment rather than the production environment.
- Execution of the test should be automated

**Summary**
- Unit test are the first safety net for catching bugs before they get to the field.
- Unit tests validate test cases for individual functions.
- They should build and run in the developer's development environment
- Unit test should run fast!
* * *
## Overview of Test-Driven Development
**What is Test-Driven Development?**
- A process where the developer takes personal responsability for the quality of their code.
- Unit tests are written *before* the production code at once.
- Don't write all the tests or production code at once.
- Tests and production code are both written together in small bits of functionality.

**What are some of the benefits of TDD?**
- Gives you the confidence to change the code.
- Gives you immediate feedback
- Documents what the code is doing.
- Drives good object oriented design.

> **TDD Beginnings**
> - Created by Kent Beck in the 1990's as part of the Extreme Programming software development process.
> - He wrote the first TDD unit testing framework in Smalltalk called SUnit.
> - Collaborated with Erich Gamma to implement the first Java unit testing framework JUnit.
> - JUnit has been the basis for many other xUnit testing frameworks written for other languages.

## TDD Workflow: <span style="color:red">RED</span>, <span style="color:green">GREEN</span>, REFACTOR

!!MERMAID TEST!!
```mermaid
graph TD;
A-->B;
A-->C;
B-->D;
C-->D;
```