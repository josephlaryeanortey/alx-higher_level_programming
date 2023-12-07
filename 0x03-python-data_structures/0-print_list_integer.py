def print_list_integer(my_list=[]):
    """
    Print all integers of a list.
    
    Args:
    - my_list (list): List of integers to be printed.
    
    Format: one integer per line. See example.
    
    You are not allowed to cast integers into strings.
    You have to use str.format() to print integers.
    """
    for integers in my_list:
        print("{:d}".format(integers))
