import pytest

def fizzBuzz( value ):
    if isMultiple(value, 3):
        if isMultiple(value, 5):
            return "FizzBuzz"
        return "Fizz"
    if isMultiple(value,5):
        return "Buzz"
    return str(value)

def isMultiple( value, mod ):
    return (value % mod) == 0

def checkFizzBuzz( value, expectedRetVal ):
    retVal = fizzBuzz(value)
    assert retVal == expectedRetVal

def test_returns1With1PassedIn():
    checkFizzBuzz(1,"1")

def test_returns2With2PassedIn():
    checkFizzBuzz(2,"2")

def test_returnsFizzWith3PassedIn():
    checkFizzBuzz(3, "Fizz")

def test_returnsBuzzWith3PassedIn():
    checkFizzBuzz(5, "Buzz")

def test_returnsFizzWith6Entered():
    checkFizzBuzz(6, "Fizz")

def test_returnsFizzWith10PassedIn():
    checkFizzBuzz(10, "Buzz")

def test_returnsFizzBuzzWith15PassedIn():
    checkFizzBuzz(15, "FizzBuzz")

def test_helloWorld():
    checkFizzBuzz(30, "FizzBuzz")