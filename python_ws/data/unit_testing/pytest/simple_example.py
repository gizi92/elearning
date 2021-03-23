import pytest

# Production code
def str_len( theStr ):
    return len( theStr )

# A Unit Test
def test_string_length():
    testStr = "1"             # Setup
    result = str_len(testStr) # Action
    assert result == 1        # Assert