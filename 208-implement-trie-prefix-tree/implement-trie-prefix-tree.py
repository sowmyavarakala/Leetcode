class TrieNode:
    def __init__(self):
        self.isWord = False
        self.child = [None] * 26  # To store 26 lowercase English letters

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        p = self.root
        for char in word:
            index = ord(char) - ord('a')  # Calculate index for the character
            if not p.child[index]:
                p.child[index] = TrieNode()
            p = p.child[index]
        p.isWord = True
    
    def search(self, word: str, prefix: bool = False) -> bool:
        p = self.root
        for char in word:
            index = ord(char) - ord('a')
            if not p.child[index]:
                return False
            p = p.child[index]
        if not prefix:
            return p.isWord
        return True
    
    def startsWith(self, prefix: str) -> bool:
        return self.search(prefix, True)


# Example usage:
# obj = Trie()
# obj.insert("word")
# param_2 = obj.search("word")
# param_3 = obj.startsWith("prefix")
