
from graphadt import GraphADT
import pdb

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

class DiGraph(GraphADT):

    def __init__(self, number_of_vertex):
        self.number_of_vertex = number_of_vertex
        
        self._graph = [[] for i in range(0, self.number_of_vertex)]
        self._vertex_def = {}

        self.is_cyclic = False

    def add_vertex(self, src, definition = ''):
        self._vertex_def[src] = definition

    def add_edge(self, src, dst, weight = 0):
      #  pdb.set_trace()
        self._graph[src].append(Edge(dst, weight))


    def get_edges(self, src):
        if src in self._vertex_def:
            return self._graph[src]
        
        return None



    def _sort_top_util(self, vertex, stack):
    
        if vertex in stack:
            pass
        else:
            for edge in self._graph[vertex]:
                self._sort_top_util(edge.dst, stack)
            stack.append(vertex)

    
    def sort_top(self):
        stack = []
        for key, value in self._vertex_def.items():
            if not key in stack:
                self._sort_top_util(key, stack)

        return stack


############################ Breadth First Search ################################################
    def find_path_bfs(self, src, dst):
        is_visited = [False]*self.number_of_vertex
        parent = [-1] * self.number_of_vertex
        queue = [src]
        parent[src] = src

        distance = 0

        distance_index = [-1]*self.number_of_vertex

        while len(queue) != 0:

            vertex = queue.pop(0)

            is_visited[vertex] = True
            distance += 1

            distance_index[vertex] = distance

            for edge in self._graph[vertex]:
                if is_visited[edge.dst] == False:
                    queue.append(edge.dst)
                    parent[edge.dst] = vertex

        return parent

    def _visit_bfs(self, vertex, parent, is_visited, distance):
        is_visited[vertex] = True

        for edge in self._graph[vertex]:
            if is_visited[edge.dst] == False:
                parent[edge.dst] = vertex
                self._visit_bfs(edge.dst, parent, is_visited, distance)

    def recursive_bfs(self):
        is_visited = [False]*self.number_of_vertex
        parent = [-1] * self.number_of_vertex

        distance = 0
        pass

        for vertex in self._vertex_def.keys():
            if is_visited[vertex]==False:
                self._visit_bfs(vertex, parent, is_visited, distance)


##########################GRAPH TRAVERSAL##################################################


    def _process_edge_recursive_postorder(self, vertex, marked, visit_stack):

        marked[vertex] = True
        

        for edge in self._graph[vertex]:
            if marked[edge.dst] == False:
                self._process_edge_recursive_postorder(edge.dst, marked, visit_stack)

        visit_stack.append(vertex)

    def _process_edge_recursive_preorder(self, vertex, marked, visit_stack):
        marked[vertex] = True

        for edge in self._graph[vertex]:
            pass



###############################DEPTH FIRST SEARCH#######################################
    def dfs_recursive(self, src):
        marked = [False] * self.number_of_vertex

        visit_stack = []

        for vertex in self._vertex_def.keys():

            if marked[vertex] == False:
                self._process_edge_recursive(vertex, marked, visit_stack )


    def find_path_dfs(self, src, dst):
        is_visited = [False]*self.number_of_vertex
        parent = [-1] * self.number_of_vertex

        vertex_stack = [src]

        while len(vertex_stack) != 0:

            vertex = vertex_stack.pop(-1)
            is_visited[vertex] = True


            for edge in self._graph[vertex]:
                if is_visited[edge.dst] == False:
                    vertex_stack.append(edge.dst)
                    parent[edge.dst] = vertex




####################################### STRONGLY CONNECTED COMPONENTS #####################################################



    def _reverse_graph(self):
        new_graph = [ [] for i in range(0, self.number_of_vertex) ]

        for i in range(0, self.number_of_vertex):

            for edge in self._graph[i]:
                new_graph[edge.dst].append(i)

        self._graph = new_graph


    def scc_util(self, vertex, is_visited ,visit_stack):

        is_visited[vertex] = True

        for edge in self._graph[vertex]:
            if is_visited[edge.dst] == False:
                self.scc_util(edge.dst, is_visited, visit_stack)
                visit_stack.append(edge.dst)


    def _find_SCCs(self, vertex, is_visited, vertex_ids, idv):

        is_visited[vertex] = True
        vertex_ids[vertex] = idv

        for edge in self._graph[vertex]:
            if is_visited[edge.dst] == False:
                self._find_SCCs(edge.dst, is_visited, vertex_ids, idv)




    """ Finds strongly connected components"""
    def find_scc(self):
        is_visited = [False]*self.number_of_vertex
        idv = [-1] * self.number_of_vertex
        visit_stack = []


        for i in self._vertex_def.keys():
            if is_visited[i] == False:
                self.scc_util(i, is_visited, visit_stack)
                visit_stack.append(i)

        self._reverse_graph()

        is_visited = [False]*self.number_of_vertex

        vertex_ids = [-1] * self.number_of_vertex

        while len(visit_stack) != 0:
            vertex = visit_stack.pop(-1)
            if is_visited[vertex] == False
                self._find_SCCs(vertex, is_visited, vertex_ids, idv)
            idv += 1



#########################CYCLE ALGORITHMS##############################
        


    """ A utility function to traverse edges of the given vertex"""
    def _process_edge_cycle(self, vertex, stack, is_visited):

        if vertex in stack:
            self.is_cyclic = True
            return
        stack.append(vertex)
        is_visited[vertex] =  True

        for edge in self._graph[vertex]:
            if edge.dst in stack:
                self.is_cyclic = True
                break
            else:
                if is_visited[edge.dst] == False:
                    self._process_edge_cycle(edge.dst, stack, is_visited)

        stack.pop(-1)

    """ Finds the graph has any cycles"""
    def has_cycle(self, vertex=0):
       # pdb.set_trace()
        start_vertex = vertex
        is_visited = [False] * self.number_of_vertex

        stack = [vertex]
        is_visited[vertex] = True

        for edge in self._graph[vertex]:
            if self.is_cyclic == False and is_visited[edge.dst] == False:
                self._process_edge_cycle(edge.dst, stack, is_visited)

        stack.pop(-1)

        return self.is_cyclic



    def get_vertex_def(self, vertex_number):
        if vertex_number in self._vertex_def:
            return self._vertex_def[vertex_number]

        return -1



if __name__ == '__main__':
    digraph = DiGraph(6)

    digraph.add_vertex(0,"java")
    digraph.add_vertex(1,"object-oriented")
    digraph.add_vertex(2,"algorithms")
    digraph.add_vertex(3,"advanced java")
    digraph.add_vertex(4,"machine learning")
    digraph.add_vertex(5,"data mining")

    """
    digraph.add_edge(0, 1)
    digraph.add_edge(1, 2)
    digraph.add_edge(0, 2)
    digraph.add_edge(0, 3)
    digraph.add_edge(2, 4)
    digraph.add_edge(4, 0)
    """
    
    digraph.add_edge(0,1)
    digraph.add_edge(0,3)
    digraph.add_edge(0,5)
    digraph.add_edge(2,0)
    digraph.add_edge(1,2)
    digraph.add_edge(4,3)
    digraph.add_edge(4,5)
    digraph.add_edge(5,2)


  #  digraph._reverse_graph()
   # print(str(digraph._graph))

   # sorted = digraph.sort_top()

    print(str(digraph.has_cycle()))