if __name__ == '__main__':
    with open('triangle.txt', 'r') as f:
        triangle = f.readlines()
        triangle = [[int(x) for x in row.split()] for row in triangle]

        SIZE = len(triangle)
        
        arr = [[0] * SIZE for n in range(SIZE)]
        arr[0][0] = triangle[0][0]
        for i in range(SIZE):
            arr[i][0] = arr[i - 1][0] + triangle[i][0]
            for j in range(1, i + 1):
                arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + triangle[i][j]

        print max(arr[SIZE - 1])
