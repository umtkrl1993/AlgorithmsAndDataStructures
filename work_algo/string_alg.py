
import pdb
import urllib


NUMBER_OF_CHARS = 256
def init(pattern):
  #  pdb.set_trace()
    init_arr = [0]
    i = 0
    for j in range(1, len(pattern)):

        while i>0 and pattern[i] != pattern[j]:
            i = init_arr[i-1]

        if pattern[i] == pattern[j]:
            init_arr.append(i+1)
            i += 1
        else:
            init_arr.append(i)

    return init_arr




def string_match(text, pattern):

    init_table = init(pattern)

    print(str(init_table))

    pattern_index = 0

    pdb.set_trace()
    for text_index in range(0, len(text)):

        while pattern_index > 0 and text[text_index] != pattern[pattern_index]:
            pattern_index = init_table[pattern_index-1]

        if pattern_index==len(pattern)-1:
            return True
        if pattern_index != 0 and pattern[pattern_index] == text[text_index]:
            pattern_index = pattern_index + 1
        elif pattern_index == 0:
            if pattern[pattern_index] == text[text_index]:
                pattern_index += 1

    print(pattern_index)
        
    if pattern_index == len(pattern) -1:
        return True
    return False



def bm_init_index(right, pattern):
   

    for j in range(0, len(pattern)):
        right[ord(pattern[j])] = j

def boyer_moore(text, pattern):
    
    right = [-1]*NUMBER_OF_CHARS
    bm_init_index(right, pattern)

    text_len = len(text)
    pattern_len = len(pattern)
    skip = 1
    #pdb.set_trace()

    for i in range(0, text_len - pattern_len+1, skip):
       
        skip = 0
        for j in range(pattern_len-1, -1, -1 ):
            if text[i+j] != pattern[j]:
                skip = j-right[ord(text[i+j])]
                if right[ord(text[i+j])] == -1:
                    skip = len(pattern)
                else:
                    if skip < 1:
                        skip = 1
                break

        if skip == 0:
            return i


    return text_len

            





if  __name__ == "__main__":

    pattern = "algorithm"
    #text = "hi this is a test"

  #  print boyer_moore(text, pattern)

    with open("string_test.txt", "r") as fd:
       # pdb.set_trace()
        for index, line in enumerate(fd.readlines()):
            line = line.strip('\n')
            find_index = boyer_moore(line, pattern)

            if find_index != len(line):
                print "found at line %s and starting index %s" %(index, find_index)
           
  
    #print(string_match(text, pattern))
