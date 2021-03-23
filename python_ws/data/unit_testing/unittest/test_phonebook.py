#!/usr/bin/env python3

"""
Given a list of names and phone numbers
Make a Phonebook
Determine if it is consistent:
 - no number is a prefix of another
 - e.g. Bob 91125426, Anna 97625992
 - Emergency 911
 - Bob and Emergency are inconsistent

Run the test in the cli in the same path with `$ python -m unittest`
"""
import unittest
from phonebook import PhoneBook

# Declare a class containing the tests
class PhoneBookTest(unittest.TestCase):
    
    # Set up test fixture method
    def setUp(self) -> None:
        self.phonebook = PhoneBook()
    # Tear down fixture method
    # def tearDown(self):
    #     pass

    # First Test Case
    def test_lookup_by_name(self):
        self.phonebook.add("Bob", 12345)
        number = self.phonebook.lookup("Bob")
        self.assertEqual(12345, number)

    # Second test case
    def test_missing_name(self):
        with self.assertRaises(KeyError):
            self.phonebook.lookup("missing")

    def test_empty_phonebook_is_consistent(self):
        self.assertTrue(self.phonebook.is_consistent())

    def test_is_consistent_with_different_entries(self):
        self.phonebook.add("Bob", "12345")
        self.phonebook.add("Anna", "012345")
        self.assertTrue(self.phonebook.is_consistent())

    def test_inconsistent_with_duplicate_entries(self):
        self.phonebook.add("Bob", "12345")
        self.phonebook.add("Sue", "12345")
        self.assertFalse(self.phonebook.is_consistent())

    def test_inconsistent_with_duplicate_prefix(self):
        self.phonebook.add("Bob", "12345")
        self.phonebook.add("Sue", "123")
        self.assertFalse(self.phonebook.is_consistent())

    @unittest.skip("WIP")
    def test_phonebook_adds_names_and_numbers(self):
        self.phonebook.add("Sue", "1233345")
        self.assertIn("Sue", self.phonebook.get_names())
        self.assertIn("1233345", self.phonebook.get_numbers())