VALUES = {'K': -2, 'R': -1, 'Y': 0, 'G': 1, 'B': 2}
CODES = {0: 'F', 1: 'P', 2: 'C', 3: 'O'}

def targetCode(rings):
    # rings is the list of the 5 colours of the target
    # Returns the code to report, or None if the target is fake
    total = sum(VALUES[color] for color in rings)
    return CODES.get(total)
