#!/usr/bin/python3
def print_list_integer(my_list=[]):
    """
    Print all integers of a list, one integer per line.

    Args:
        my_list (list): List containing integers.

    Returns:
        None
    """
    for integer in my_list:
        print("{:d}".format(integer))

if __name__ == "__main__":
    my_list = [1, 2, 3, 4, 5]
    print_list_integer(my_list)
