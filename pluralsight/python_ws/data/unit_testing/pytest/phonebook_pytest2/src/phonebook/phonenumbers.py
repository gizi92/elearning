import os

from phonebook.data_processing import clean_phonenumber

class PhoneBook:

    def __init__(self, cache_directory=None):
        self.numbers = {}
        cache_dir = cache_directory or os.getcwd()
        self.filename = os.path.join(cache_dir, "phonebook.txt")
        self.cache = open(self.filename, "w")

    def add(self, name, number):
        self.numbers[name] = number

    def lookup(self,name):
        return self.numbers[name]

    def is_consistent(self):
        for name1, number1 in self.numbers.items():
            for name2, number2 in self.numbers.items():
                if name1 == name2:
                    continue
                if number1.startswith(number2):
                    return False
        return True