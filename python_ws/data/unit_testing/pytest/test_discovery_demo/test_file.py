#!/usr/bin/env python

import pytest

class TestClass:
    @classmethod
    def setup_class(cls):
        print("Setup TestClass!")

    @classmethod
    def teardown_class(cls):
        print("Teardown TestClass!")

    def setup_method(self, method):
        if method == self.test1:
            print("\nSetting up test1!")
        elif method == self.test2:
            print("\nSetting up test2!")
        else:
            print("\nSetting up unknown test!")

    def teardown_method(self, method):
        if method == self.test1:
            print("\nTearing down test1!")
        elif method == self.test2:
            print("\nTearing down test2!")
        else:
            print("\nTearing down unknown test!")

    def test1(self):
        assert True

    def test2(self):
        assert True
