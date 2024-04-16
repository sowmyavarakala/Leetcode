class Codec:
    def encode(self, strs: List[str]) -> str:
        return "\n".join(strs)
        """Encodes a list of strings to a single string.
        """
        

    def decode(self, s: str) -> List[str]:
        return s.split("\n")
        """Decodes a single string to a list of strings.
        """
        


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))