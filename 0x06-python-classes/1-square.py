#!/usr/bin/python3
"""
1. Square with size
A class Square that defines a square
"""


class Square:
    """
    Class that defines a square

    Attributes:
        __size (int): The size of the square.
    """

    def __init__(self, size):
        """
        Initializes a new instance of the Square class.

        Args:
            size (int): The size of the square.
        """
        self.__size = size
