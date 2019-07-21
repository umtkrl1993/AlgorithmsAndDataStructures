
from abc import ABCMeta, abstractmethod
from graphadt import GraphADT

import pdb

import copy
class Edge(object):
    def __init__(self, dst, weight, mark = ''):
        self.dst = dst
        self.weight = weight
        self.mark = mark

    def __eq__(self, obj):
        return isinstance(obj, Edge) and self.dst == obj.dst and self.weight == obj.weight and self.mark == obj.mark

    def __str__(self):
        return "destination is %s" %str(self.dst)

    def __repr__(self):
        return "destination is %s" %str(self.dst)






class Graph(GraphADT):
    def __init__(self, number_of_vertex, directed = False):
        self.number_of_vertex = number_of_vertex
        self._graph = [[] for i in range(0, self.number_of_vertex)]
        self.directed = directed
        self._vertex_def = {}


    def __call__(self, graph_to_copy):
        self.number_of_vertex = graph_to_copy.number_of_vertex

        self._graph = [[]] * self.number_of_vertex

        visited = [False] * graph_to_copy.number_of_vertex
        edges = graph_to_copy._graph

        for index in range(len(edges)):
            for edge in edges[index]:
                self._graph[index].append(copy.deepcopy(edge))


    def get_edges(self):
        return self._graph




    def add_vertex(self, src, definition = ''):

        if src in self._vertex_def:
            return -1

        self._vertex_def[src] = definition


    def get_vertexes(self):

        for key, value in self._vertex_def.items():
            print("id is %d and city is %s" %(key,value))




    def add_edge(self, src, dst, weight = 0):

        if self.directed == False:




            edge = Edge( dst, weight)

            if edge in self._graph[src]:
                return False

             
            self._graph[src].append(edge)

            edge = Edge( src, weight)
            self._graph[dst].append(edge)



    def find_path_dfs(self, src, dst):

        search_stack = []

        search_stack.append(src)

        is_visited = [ False for i in range(0,self.number_of_vertex)]

        parent = [-1 for i in range(0, self.number_of_vertex)]

        parent[src] = src

        while len(search_stack) != 0:
            current_vertex = search_stack.pop(-1)
            is_visited[current_vertex] = True
            if current_vertex == dst:
                return parent

            for edge in self._graph[current_vertex]:
                if is_visited[edge.dst] == False:
                    parent[edge.dst] = current_vertex
                    search_stack.append(edge.dst)

        return False

    def find_ccs(self):

        marked = [ False for i in range(0, self.number_of_vertex)]
        count = 0


        for i in range(0, self.number_of_vertex):

            if marked[i] == False:
                count += 1
                dfs_util(i, marked, count)


    def dfs_util( self, vertex, marked, count):
            marked[vertex] = True

            edges = self._graph[vertex]
            for edge in edges:

                if marked[edge.dst] == False:
                    dfs_util(edge.dst, marked)

    def _root(self, vertex, root):

        while root[vertex] != vertex:
            vertex = root[vertex]

        return vertex

    def _union(self, parent, vertex1, vertex2):

        parent_vertex1 = self._root(vertex1, parent)

        parent_vertex2 = self._root(vertex2, parent)

        parent[parent_vertex2] = parent_vertex1




    def has_cycle(self):

        #root = [ i for i in range(0, self.number_of_vertex)]

        for key in sorted(self._number_of_vertex.keys()):
            root.append(key)
		
        start_vertex = 1


        for i in range(0, self.number_of_vertex):

            for edge in self._graph[i]:
                if self._root(i, root) != self._root(edge.dst, root):
                    self._union(root, i, edge.dst)

                else:
                    return True

        return False



if __name__ == '__main__':

    pass
    