#!/usr/bin/env python

class CheckOut:
    class Discount:
        def __init__(self, noOfItems, price):
            self.noOfItems = noOfItems
            self.price = price

    def __init__(self):
        self.prices = {}
        self.discounts = {}
        self.items = {}
        self.total = 0

    def addItemPrice(self, item, price):
        self.prices[item] = price

    def addItem(self, item):
        if item not in self.prices:
            raise Exception("Bad Item")
        if item in self.items:
            self.items[item] += 1
        else:
            self.items[item] = 1


    def calculateTotal(self):
        total = 0
        for item, cnt in self.items.items():
            if item in self.discounts:
                discount = self.discounts[item]
                if cnt >= discount.noOfItems:
                    total += self.calculateItemDiscountedTotal(item, cnt, discount)
                else:
                    total += self.prices[item] * cnt
            else:
                total += self.prices[item] * cnt
        return total

    def calculateItemDiscountedTotal(self, item, cnt, discount):
        total = 0
        noOfDiscounts = cnt/discount.noOfItems
        total += noOfDiscounts * discount.price
        remaining = cnt % discount.noOfItems
        total += remaining * self.prices[item]
        return total

    def addDiscount(self, item, noOfItems, price):
        discount = self.Discount(noOfItems, price)
        self.discounts[item] = discount