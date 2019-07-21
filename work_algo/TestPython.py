




class Node(object):
    def __init__(self, value):
        self.value = value
        self.link_count = 0
        self.children = [ None for i in range(0,26)]

class Trie(object):
    def __init__(self):
        self.root = Node(None)

    def insert( self, key ):
        
        current = self.root
        for i in range( len(key) ):
            if current.children[ord(key[i]) - ord('a') ] == None:
                current.children[ord(key[i]) - ord('a') ] = Node(key[i])

            current = current.children[ord(key[i]) - ord('a')]

    def contains(self, key):

        current = self.root

        for i in range( len(key) ):
            int_value = ord(key[i]) - ord('a')
            if current.children[int_value] == None:
                return False
            current = current.children[int_value]

        return True

    def _getPrefix(self, current, prefix, all_prefixes):

        for i in range(0,26):
            if current.children[i] != None:
                new_prefix = prefix + current.children[i]
                all_prefixes.append(new_prefix)
                self._getPrefix(current.children[i], new_prefix, all_prefixes)

    def keysWithPrefix(self,prefix):

        current = self.root

        for i in xrange(0,len(prefix) ):
            asci_code = ord(prefix[i]) - ord('a')
            current = current.children[asci_code]

        all_prefixes = []

        self._getPrefix(current, prefix, all_prefixes)

    def delete(self, key):
        pass


import sys




def foo(age,name="test"):
    print(name)




if __name__ == "__main__":


    print("%s\n", str(foo.__kwdefaults__))


 






    #print(str(arr))

    """
    trie = Trie()
    trie.insert("thisistest")
    trie.insert("thisisdemo")
    trie.insert("sea")
    trie.insert("shells")
    trie.insert("sells")
  #  print(str(trie.contains("this")))

    friends = Graph(10)
    friends.add_vertex(1, "umit")
    friends.add_vertex(2, "berke")
    friends.add_vertex(3, "burak")
    friends.add_vertex(4, "ali")
    friends.add_vertex(5, "veli")
    friends.add_vertex(6, "murat")
    friends.add_vertex(7, "onur")
    friends.add_vertex(8, "omer")

    friends.add_edge(1,4,400)
    friends.add_edge(2,3,200)
    friends.add_edge(1,3,100)
   

  #  friends.print_vertexes()

    friends.print_edges()
    """

   # line = sys.stdin.readline()
    #print(line)