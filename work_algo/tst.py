class TSTNode():
    	def __init__(self, value):
		self.value = value
		self.lc = None
		self.rc = None
		self.mc = None
		self.end_word = False

import pdb
class TST():
    def __init__(self):
        self._root = None


    def _insert(self, word, current, index):
    	pass
    	

    def insert(self, word):
    	if len(word) == 0:
            raise Exception("empty string")
        if self._root == None:
            self._root = TSTNode(word[0])
			

        current = self._root
        prev = None
        i = 0
        while i < len(word):
            prev = current
            if current.value == word[i]:
                if current.mc == None:
                    if i+1 < len(word):
                        current.mc = TSTNode(word[i+1])

                current = current.mc
                i += 1
            elif current.value > word[i]:
                if current.lc == None:
                    current.lc = TSTNode(word[i])
                current = current.lc
            else:
                if current.rc == None:
                    current.rc = TSTNode(word[i])
                current = current.rc

		#prev.end_word = True

    def get(self, word):
        current = self._root
        i = 0
        while current != None:
            if word[i] == current.value:
                i +=1
                current = current.mc
            elif word[i] < current.value:
                current = current.lc
            else:
                current = current.rc

        return True if i == len(word) else False
    

if __name__ == '__main__':

	dicti = TST()
	dicti.insert('berke')
	dicti.insert('berkay')

	print str(dicti.get('berky'))
