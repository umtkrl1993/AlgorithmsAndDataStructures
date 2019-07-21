from abc import ABCMeta, abstractmethod

class GraphADT(metaclass=ABCMeta):

    @abstractmethod
    def add_vertex(self, src, definition = ''):
        pass

    @abstractmethod
    def add_edge(self, src, dst, weight = 0):
        pass

    @abstractmethod
    def find_path_dfs(self, src, dst):
        pass

