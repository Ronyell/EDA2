import igraph


class Graph:

    # Contrutor para grafo vazio ou com um argumento, o numero de vertices
    def __init__(self, V=None):
        if V is not None:
            self.V = V
            self.E = 0
            self.adj_Lista()

        else:
            self.V = int(input('Nome V: '))
            self.E = 0
            self.adj_Lista()

            e = int(input('Range: '))

            for i in range(e):
                entrada1 = input('v :')
                entrada2 = input('w :')
                v = int(entrada1)
                w = int(entrada2)
                self.addEdge(v, w)

    # Funcao que cria a lista de adjacencia, usada no construtor
    def adj_Lista(self):
        self.adj = []
        for _ in range(self.V):
            self.adj.append([])

    # Retorna o numero de vertices
    def vertices(self):
        return self.V
    # retorna o numero de arestas

    def arestas(self):
        return self.E

    # metodo para adicionar arestas
    def addEdge(self, v, w):
        self.adj[v].append(w)
        self.E += 1

    # representando como string
    def __str__(self):
        string = str(self.V) + " vertices e " + str(self.E) + " arestas"
        return string

    # imprimindo arestas
    def imprime_arestas(self):
        v = 0
        n = 0
        i = 0

        while v < self.V:
            n = len(self.adj[v])
            if n > 0:
                while i < n:
                    print(v, self.adj[v][i])
                    i += 1
            v += 1
            i = 0

    # grau de V
    def grau_de_v(self, v):
        return len(self.adj[v])

    # maior grau
    def maior_grau(self):
        lista = []
        for i in range(self.V):
            lista.append(self.grau_de_v(i))
        return max(lista)

    # grau medio
    def grau_medio(self):
        return 2 * self.E / float(self.V)

    # conta auto-loops
    def numero_auto_loops(self):
        pass

    # o grafo e conectado
    def connected(self):
        self.visitado = [False] * self.V
        self.count = 0

        self.dfs(0)

        if self.count == self.V:
            return "Conectado"
        else:
            return "Nao conectado"

    # deep first searsh para a funcao conectado
    def dfs(self, origem):
        self.visitado[origem] = True
        self.count += 1

        for i in self.adj[origem]:
            if self.visitado[i] is False:
                self.dfs(i)

    def plot(self):
        g = igraph.Graph()
        g.add_vertices(self.V)
        g.vs["name"] = ["Alice", "Bob", "Claire", "Dennis", "Esther"]

        k = 0
        for v in self.adj:
            for n in v:
                for i in range(len(v)):
                    g.add_edges([(k, self.adj[k][i])])
            k += 1

        g.vs["label"] = g.vs["name"]
        layout = g.layout("kk")
        igraph.plot(g, layout=layout, margin=20)


graph = Graph()
graph.connected()
graph.dfs(1)
graph.plot()
