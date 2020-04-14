class Solution:
    def entityParser(self, text: str) -> str:
        special_tokens = {
            "&quot;": "\"", 
            "&apos;": "'",
            "&gt;": ">",
            "&lt;": "<",
            "&frasl;": "/"
        }
        for entity, character in special_tokens.items():
            text = text.replace(entity, character)
        text = text.replace("&amp;", "&")
        return text