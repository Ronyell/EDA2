class Edge:

    def __init__(self, source, target):
        self.source = source
        self.target = target
        self.source.add_neighbour(self.target)
        self.target.add_neighbour(self.source)
