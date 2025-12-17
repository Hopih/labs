matrix = []
while True:
    line = input().strip()
    if line == "end":
        break
    row = list(map(int, line.split()))
    matrix.append(row)

rows = len(matrix)
cols = len(matrix[0])

result = [[0] * cols for _ in range(rows)]

for i in range(rows):
    for j in range(cols):
        top = matrix[i-1][j]
        bottom = matrix[(i+1) % rows][j]
        left = matrix[i][j-1]
        right = matrix[i][(j+1) % cols]
        result[i][j] = top + bottom + left + right

for i in range(rows):
    for j in range(cols):
        print(result[i][j], end=" ")
    print()


























