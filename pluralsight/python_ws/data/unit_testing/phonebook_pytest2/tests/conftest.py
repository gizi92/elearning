"""Shared fixtures."""

import pytest

from phonebook.phonenumbers import PhoneBook

@pytest.fixtures
def phonebook(tmpdir):
    """Provides an empty PhoneBook"""
    return PhoneBook(tmpdir)