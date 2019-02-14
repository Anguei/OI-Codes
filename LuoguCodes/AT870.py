a = [map(int, raw_input().split()) for _ in range(4)]
dir = [ (1, 0), (-1, 0), (0, 1), (0, -1) ]
for x in range(4):
    for y in range(4):
        for dx, dy in dir:
            if 0 <= x + dx <= 3 and 0 <= y + dy <= 3:
                if a[x][y] == a[x + dx][y + dy]:
                    print ';CONTINUE';
                    exit()
print ';GAMEOVER';                    
