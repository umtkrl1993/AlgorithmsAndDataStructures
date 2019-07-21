

CHAR_NUMBER = 26

class Node():
	def __init__(self, value):
		self.value = value
		self.children = [ None for i in xrange(0,CHAR_NUMBER) ]
		self.end_word = False



class Trie():
    def __init__(self):
        self.root = Node(None)

    def contains(self, word):
        current = self.root

        for i in xrange(len(word)):
            asci_code = ord(word[i]) - ord('a')
            if current.children[asci_code] == None:
                return False
            current = current.children[asci_code]

		
        return current.end_word

    def insert(self, word):
        current = self.root


        for i in xrange(len(word)):

            asci_value = ord(word[i]) - ord('a')

            if current.children[asci_value] == None:
                current.children[asci_value] = Node(word[i])

            current = current.children[asci_value]

        current.end_word = True

    def delete(self, word):

        current = self.root
        parent = current

        for i in xrange(len(word)):
            asci_code = ord(word[i]) - ord('a')
            current.children[asci_code].value

            if current.children[asci_code] == None:
                return -1
            parent = current
            current = current.children[asci_code]

        if current.end_word == False:
            return -1

        if self._has_link(current) == True:
            current.end_word = False
        else:
            parent.children[ord(current.value) - ord('a')] = None
            if self._has_link(parent) == False and parent.end_word == False:
                word = word[0:len(word) - 1]
                self._clean_trie(word)

            # current = None

        return True

    def _get_prefixes(self, current, queue, prefix):

        for i in xrange(0, CHAR_NUMBER):

            if current.children[i] != None:
                temp_prefix = prefix + current.children[i].value
                queue.append(temp_prefix)
                self._get_prefixes(current.children[i], queue, temp_prefix)

    def collect_prefix(self, prefix):

        current = self.root
        prefix_queue = [prefix]

        for i in xrange(0, len(prefix)):

            asci_code = ord(prefix[i]) - ord('a')
            current = current.children[asci_code]

        self._get_prefixes(current, prefix_queue, prefix)

        return prefix_queue


    def search(self, word):

        current = self.root
        for i in xrange(len(word)):
            asci_code = ord(word[i]) - ord('a')
            if current.children[asci_code] == None:
                return False
            current = current.children[asci_code]

        return current.end_word

    def _has_link(self, current):
        for i in xrange(0,CHAR_NUMBER):
            if current.children[i] != None:
                return True

        return False

    def clean_trie(self, word):
        current = self.root
        parent = current

        for i in xrange(len(word)):
            asci_code = ord(word[i]) - ord('a')
            if current.children[asci_code] == None:
                return
            parent = current
            current = current.children[asci_code]
		
        if current.end_word == False and self._has_link(current) == False:
            parent.children[ord(current.value) - ord('a')] = None
            if parent.end_word == False and self._has_link(parent) == False:
                word = word[0:len(word)-1]
                self.clean_trie(word)
    			


    ### largest key less than or equal to key
    ### currently does not check if it is end_word and if it equal
    def floor(self, key):
        current = self.root
        last = key[-1]
        prefix_key = key[0:len(key)-1]
        print "prefix key is %s" %prefix_key
        for i in xrange(0, len(key)-1):
            asci_code = ord(key[i]) - ord('a')
            current = current.children[asci_code]

        print current.value

        asci_code = ord(last) - ord('a')


        for i in range(asci_code-1, -1, -1):
            if current.children[i] != None:
                prefix_key += current.children[i].value
                break

        return prefix_key

    def ceil(self, key):
        current = self.root
        last = key[-1]
        prefix_key = key[0:len(key-1)]

        for i in xrange(0, len(key)-1):
            asci_code = ord(key[i]) - ord('a')
            current = current.children[asci_code]





#### delete does not work ############

if __name__ == '__main__':
    search_dict = Trie()
    search_dict.insert('berke')
    search_dict.insert('berka')


#	print str(search_dict.contains('berke'))
#	print str(search_dict.contains('berk'))
#	print str(search_dict.contains('burak'))

#	print str(search_dict.collect_prefix("ber"))

	#print search_dict.delete('berke')

	#print str(search_dict.contains('berke'))

#	print str(search_dict.contains('ber'))
    print search_dict.floor('berke')





