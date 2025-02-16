class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        arr = [0] * (2*n-1)
        visited = [False] * (n+1)
        i = 0

        def dfs(arr, i, visited):
            if i >= 2*n-1:
                return True
            
            for x in range(n, 0, -1):

                if (x > 1 and (not (arr[i]==0 and (i+x < 2*n-1) and arr[i+x]==0) or visited[x])) or (x == 1 and (arr[i] != 0 or visited[x])):
                    continue
                
                if x > 1:
                    arr[i] = x
                    arr[i+x] = x
                else:
                    arr[i] = x
                visited[x] = True
                nextp = i+1

                while nextp < 2*n-1 and arr[nextp]:
                    nextp += 1
                
                if dfs(arr, nextp, visited):
                    return True

                if x > 1:
                    arr[i] = 0
                    arr[i+x] = 0
                else:
                    arr[i] = 0
                visited[x] = False

            return False


        dfs(arr, i, visited)
        return arr
        