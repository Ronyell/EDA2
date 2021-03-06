class Person:

    def __init__(self, key, name, gender, neighbours=None, number=None):
        self.key = key
        self.name = name
        self.gender = gender
        self.number = None
        if neighbours is None:
            neighbours = []
        self.neighbours = neighbours

    def add_neighbour(self, node):
        self.neighbours.append(node)

    def set_number(self, number):
        if self.number is None:
            self.number = number
            number = number + 1
        else:
            # Nothing to do.
            pass

        return number

    def __str__(self):
        return self.name
