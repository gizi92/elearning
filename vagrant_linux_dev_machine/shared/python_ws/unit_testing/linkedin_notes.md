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

## TDD Workflow: RED, GREEN, REFACTOR
TDD has the following phases in its workflow:
- Write a failing unit test (the RED phase)
- Write just enough production code to make that test pass (the GREEN phase)
- Refactor the unit test and the production code to make it clean (the REFACTOR phase).
- Repeat until the feature is complete

## Uncle Bob's 3 laws of TDD
- You may not write any production code until you have written a failing unit test.
- You may not write more of a unit test than is sufficient to fail, and not compiling is failing.
- You may not write more production code than is sufficient to pass the currently failing unit test.
* * *
## What are Python Virtual Environments?
- By default all python packages are installed to a single directory on the system.
- Virtual environments solve this by creating isolated python environments that can be customized per project.
- Virtual environments are directories containing links to the system's python install and providing sub-directories for installing additional python packages in that particular virtual environment
- the `PATH` environment variable is updated to point to the virtual environment when that virtual environment is activated.

### Setting up a Python Virtual Environment in **Python 2.7**
- Install virtualenv via `pip install virtualenv`.
- Create a new virtual environment with the command `virtualenv <NameOfVirtualEnv>`.
- Activate your virtual environment by sourcing the activate script in the virtual environments bin directory (i.e. `source ./<NameOfVirtualEnv>/bin/activate`).
- Deactivate your virtual environment with the `deactivate` command.
- Delete your virtual environment by deleting its directory.

### Setting up a Python Virtual Environment in **Python 3**
- Python 3 comes with a virtual environment module built-in called `venv`.
- Virtualenv can also be used with the python 3 but venv is what's recommended by the python community as it is a built-in to python 3, it creates smaller virtual environments, and it is extendable.
- To create a virtual environment with `venv`, you run the command `python3 -m venv <NameOfVirtualEnv>`.
* * *
## Overview of PyTest
### What is Pytest?
- PyTest is a python unit testing framework
- It provides the ability to create Tests, Test Modules, and Test Fixtures
- Uses the built-in Python `assert` statement
- Has command line parameters to help filter which tests are executed and in what order
### Creating a Test
- Tests are python functions with "test" at the beginning of the function name.
```python
# test_SomeFunction.py
def test_SomeFunction():
    assert 1 == 1
```
- Tests do verification of values using the standard python assert statement.
- Similar tests can be grouped together by including them in the same module or class.
### Test Discovery
- PyTest will automatically discover tests when you execute based on a standard naming convention.
- Test functions should include "test" at the beginning of the function name.
- Classes with tests in them should have `Test` at the beginning of the class name and not have an `__init__` method.
- Filenames of test modules should start or end with "test". (i.e. `test_example.py` or `example_test.py`)
* * *
## xUnit Style Setup and Teardown
**xUnit** style setup/teardown functions will execute code before and after:
```python
# Test Modules
def setup_module():
def teardown_module():
# Test Functions
def setup_function():
def teardown_function():
# Test Classes
def setup_class():
def teardown_class():
# Test Methods in Test Classes
def setup_method():
def teardown_method():
```
* * *
## Test Fixtures
- Test Fixtures allow for re-use of setup and teardown code across tests.
- The `pytest.fixture` decorator is applied to functions that are decorators.
- Individual unit tests can specify which fixtures they want executed.
- The autouse parameter can be set to true to automatically execute a fixture before each test.
Ex:
```python
@pytest.fixture():
def math():
    return Math()

def test_Add(math):
    assert math.add(1,1) == 2
```
### Test Fixture Teardown
- Test Fixtures can each have their own optional teardown code which is called after a fixture goes out of scope.
- There are two methods for specifying teardown code. The `yield` keyword and the request-context object's `addfinalizer` method.

**Yield**
- When the `yield` keyword is used, the code after the `yield` is executed after the fixture goes out of scope.
- The `yield` keyword is a replacement for the return keyword so any return values are also specified in the yield statement.
```python
@pytest.fixture():
def setup():
    print("Setup!")
    yield
    print("Teardown!")
```

**addfinalizer**
- With the `addfinalizer` method a teardown method is defined added via the request-context's addfinalizer method.
- Multiple finalization functions can be specified
```python
@pytest.fixture():
def setup(request):
    print("Setup!")
    def teardown:
        print("Teardown!")
    request.addfinalizer(teardown)
```
**Test Fixtures Scope**
- Test fixtures can have the following four different scopes which specify how often the fixture will be called:
    - Function - run the fixture once for each test
    - Class - run the fixture once for each class of tests
    - Module - run once when the module goes in scope
    - Session - the fixture is run when pytest starts
**Test Fixture Return Objects and Params**
- Test Fixtures can optionally return data, which can be used in the test.
- The optional `params` array argument in the fixture decorator can be used to specify the data returned to the test.
- When a `params` argument is specified then the test will be called one time with each value specified.
* * *
## Using the `assert` statement
- Pytest allows the use of the built in python assert statement for performing verifications in a unit test.
- Comparison on all of the python data types can be perforemd using the standard comparison operators: <, >, <=, >=, ==, !=
- Pytest expands on the message returned from assert failures to provide more context in the test results.
```python
def test_IntAssert():
    assert 1 == 1

def test_StrAssert():
    assert "str" == "str"

def test_floatAssert():
    assert 1.0 == 1.0

def test_arrayAssert():
    assert [1,2,3] == [1,2,3]

def test_dictAssert():
    assert {"1",1} == {"1":1}
```
**Comparing Floating Point Values**
- Validating floating point values can sometimes be difficult as internally the value is a binary fraction (i.e. 1/3 is internally 0.3333333333...)
- Because of this some floating point comparisons that would be expected to pass, will fail.
- The pytest `approx` function can be used to verify that two floating point values are "approximately" equivalent to each other with a default tolerance of `1e-6`
```python
# Failing test!!!
def test_BadFloatCompare():
    assert (0.1 + 0.2) == 0.3

# Passing test!!!
def test_GoodFloatCompare():
    val = 0.1 + 0.2
    assert val == approx(0.3)
```
**Verifying exceptions**
- In some cases we want to verify that a function throws an exception under certain conditions.
- Pytest provides the "raises" helper to perform this verification using the `with` keyword.
- If the specified exception is not raised in the code block specified after the `raises` line then the test fails.
```python
def test_Exception():
    with raises(ValueError)
        raise ValueError
```
* * *
## PyTest Command Line Arguments
**Specifying what tests should run**
- By default PyTest will automatically discover and run all tests in all properly named modules from the current working directory and sub-directories
- There are several command line arguments for controlling which discovered tests actually are executed:
    - `moduleName` - Simply specify the module name to run only the tests in that module.
    - `DirectoryName/` - Runs any tests found in the specified directory.
    - `-k "expression"` - Matches tests found that match the evaluable expression in the string. The string values can include module, class and function names (i.e. `TestClass` and `TestFunction`).
    - `-m "expression"` - Matches tests found that have a `pytest.mark` decorator that mathces the specified expression
    - `-v` - report in verbose mode.
    - `-q` - Run in quiet mode (can be helpful when running hundreds or thousands of tests at once).
    - `--ignore` - ignore the specified path when discovering tests.
    - `--maxfail` - stop after the specified number of failures.
* * *
## Unit test isolation with dummies, fakes, stubs, spies and mocks
**What are test doubles?**
- Almost all code depends (i.e. collaborates) with other parts of the system.
- Those other parts of the system are not always easy to 
replicate in the unit test environment or would make tests slow if used directly
- Test doubles are objects that are used in unit tests 
as replacements to the real production system collaborators.
**Types of test doubles**
- **Dummy** - objects that can be passed around as necessary 
but do not have any type of test implementation and should never be used
- **Fake** - these objects generally have a simplified functional implementation
of a particular interface that is adequate for testing
but not for production
- **Stub** - these objects provide implementations with canned answers that are
suitable for the test
- **Spies** - these objects provide implementations that record the values 
that were passed in so they can be used by the test
- **Mocks** - these objects are pre-programmed to expect 
specific calls and parameters and can throw exceptions when necessary

**Mock frameworks**
- Most `mock` frameworks provide easy ways for automatically creating any of these types of test doubles **at runtime**.
- They provide a fast means for creating mocking expectations for your tests.
- They can be much more efficient than implementing custom mock object of your own creation.

**unittest.mock**
- Python mocking framework
- Built-in to python 3.3 and newer
- Needs to be installed for older versions of python with the command `pip install mock`

**unittest.mock - Mock Class**
- `unittest.mock` provides the `Mock` class which can be used 
as a fake, stub, spy, or true mock for all your tests.
- The `Mock` class has many initialization parameters for controlling
its behavior.
- Once it has been called a `Mock` object has many built-in functions
for verifying how it was used.
```python
# Example
def test_Foo():
    bar = Mock()
    functionThatUsesBar( bar )
    bar.assert_called_once()
```
**Mock - Initialization**
- Mock provides many initialization parameters which can be used
to control the mock objects behavior.
- The `spec` parameter specifies the interface that `Mock` object is
implementing.
- The `side_effect` parameters specifies a function that should be
called when the mock is called.
- The `return_value` parameter specifies the return value when the `Mock` is called.
```python
# Example
def test_Foo():
    bar = Mock( spec=SpecClass )
    bar2 = Mock( side_effect=barFunc )
    bar3 = Mock( return_value=1 )
```
**Mock - Verification**
- Mock provides many built-in functions for verifying how it was used such as the following asserts:
    - `assert_called` - assert the mock was called.
    - `assert_called_once` - assert the mock was called once.
    - `assert_called_with` - assert the last call to the mock was with the specified parameters.
    - `assert_called_once_with` - assert the mock was called once with the specified parameters.
    - `assert_any_call` - assert the mock was ever called with the specified parameters
    - `assert_not_called` - assert the mock was not called.

**Mock - Aditional verification**
- Mock provides these aditional built-in attributes for verification:
    - `assert_has_calls` - assert the mock was called with the list of calls.
    - `called` - a boolean value indicating if the mock was ever called.
    - `call_count` - an integer value representing the number of times the mock object was called.
    - `call_args` - the arguments the mock was last called with.
    - `call_args_list` - a list containing the arguments that were used for each call to the mock.

**unittest.mock - MagicMock Class**
- unittest.mock also provides the `MagicMock class`
- `MagicMock` is derived from `Mock` and provides a default implementation of many of the default "magic" methods defined for objects in python (i.e `__str__`).
- The following magic methods are not implemented by default in `MagicMock`: `__getattr__`, `__setattr__`, `__init__`, `__new__`, `__prepare__`, `__instancecheck__`, `__subclasscheck__` and `__del__`

**PyTest Monkeypatch test fixture**
- PyTest provides the monkeypatch test fixture to allow a test to dynamically replace:
    - module and class attributes
    - dictionary entries
    - environment variables

```python
def callIt():
    print("Hello World")

def test_patch(monkeypatch)
    monkeypatch(callIt, Mock())
    callIt()
    callIt.assert_called_once()
```
* * *
## Test-Driven Development Best Practices
1. Always do the next simplest test case
    - Doing the next simplest test case allows you to gradually 
    increase the complexity of your code
    - If you jump into the complex test cases too quickly you will find
    yourself stuck writing a lot of functionality all at once.
    - Beyond just slowing you down, this can also lead to bad desig decisions

2. Use descriptive test names
    - code is read 1000 times more than it's written. Make it clear and readable!
    - Unit tests are the best documentation for how your code works.
    Make them easy to understand.
    - Test suites should name the class or function under test and the test
    names should describe the functionality being tested.

3. Keep tests fast
    - One of the biggest benefits of TDD is the fast feedback on how your changes have affected things.
    - This goes away if your unit tests take more than a few seconds to build and run.
    - To help your test stay fast try to:
        - Keep console output to a minimum. This slows things down and can clutter
        up the testing framework output.
        - Mock out any slow collaborators with test doubles that are fast.

4. Use code coverage tools
    - Once you have all your test cases covered and you think you're done
    run your unit test through a code coverage tool
    - This can help you identify any test cases you may have missed (i.e negative test cases)
    - You should have a goal of 100% code coverage in functions with real logic in them (i.e. not simple getters/setters)

5. Run your tests multiple times and in random order
    - Running your tests many times will help to ensure that you don't have
    any flaky tests that faill intermittently.
    - Running your tests in random order ensures that your tests don't
    have any dependencies between each other.
    - Use the `pytest-random-order` plugin to randomize the order that the tests
    are executed, `pytest-repeat` plugin to repeat one or more tests a specific number of times.

6. Use a static code analysis tool
    - `Pylint` is an excellent open source static code analysis tool that will
    find errors in your code that you may have missed in your testing.
    - `Pylint` can verify your python code meets your team's coding standard
    (or the PEP8 standard by default).
    - `Pylint` can also detect duplicated code and can generate UML diagrams from it's analysis of the code.
* * *
## Additional reading on TDD
- Kent Beck - Test Driven Development: By Example (ISBN 978-0321146533)
- Robert Martin - Clean Code: A Handbook of Agile Software Craftmanship (ISBN 078-0132350884)
- Michael Feathers - Working Effectively with Legacy Code (ISBN 978-0131177055)