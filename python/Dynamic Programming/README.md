# Dynamic Programming

- overlapping subproblems and optimal substructure.

⚙️ 4️⃣ Summary of Direction Rules
Case	Dependency	Loop Direction	Example
1D → depends on left (i-1)	Past	Left → Right	Fibonacci, Coin Change
1D → depends on right (i+1)	Future	Right → Left	Jump Game, Stone Game
2D → depends on bottom (i+1) and left (j-1)	Mixed	i: Right → Left
j: Left → Right	Stone Game VII, Matrix DP