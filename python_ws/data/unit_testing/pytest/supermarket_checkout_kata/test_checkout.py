#!/usr/bin/env python
import pytest
from checkout import CheckOut

@pytest.fixture()
def checkout():
    checkout = CheckOut()
    return checkout

def test_CanCalculateTotal(checkout):
    checkout.addItemPrice("a",1)
    checkout.addItem("a")
    assert checkout.calculateTotal() == 1