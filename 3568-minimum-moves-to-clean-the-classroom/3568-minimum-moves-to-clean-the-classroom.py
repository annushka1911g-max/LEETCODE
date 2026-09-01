from collections import deque
from typing import List


class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:

        m = len(classroom)
        n = len(classroom[0])

        # Find starting position and assign
        # an index to every litter cell
        start_r = start_c = 0
        litter_index = {}
        litter_count = 0

        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'S':
                    start_r, start_c = r, c

                elif classroom[r][c] == 'L':
                    litter_index[(r, c)] = litter_count
                    litter_count += 1

        # No litter to collect
        if litter_count == 0:
            return 0

        # If there are k litter cells:
        # target = 111...111 (k bits)
        target_mask = (1 << litter_count) - 1

        # BFS state:
        # (row, col, remaining_energy, mask, moves)

        queue = deque()

        queue.append(
            (start_r, start_c, energy, 0, 0)
        )

        # Store states that we have already visited
        visited = set()

        visited.add(
            (start_r, start_c, energy, 0)
        )

        directions = [
            (1, 0),   # down
            (-1, 0),  # up
            (0, 1),   # right
            (0, -1)   # left
        ]

        while queue:

            r, c, curr_energy, mask, moves = queue.popleft()

            # All litter collected
            if mask == target_mask:
                return moves

            # If energy is 0, we cannot move anymore
            # unless we are standing on R.
            if curr_energy == 0:
                continue

            for dr, dc in directions:

                nr = r + dr
                nc = c + dc

                # Check boundaries
                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue

                # Cannot enter obstacle
                if classroom[nr][nc] == 'X':
                    continue

                # Moving costs 1 energy
                new_energy = curr_energy - 1

                # If we enter a reset cell,
                # restore energy to maximum.
                if classroom[nr][nc] == 'R':
                    new_energy = energy

                # Collect litter if this cell contains L
                new_mask = mask

                if (nr, nc) in litter_index:

                    bit = litter_index[(nr, nc)]

                    new_mask |= (1 << bit)

                state = (
                    nr,
                    nc,
                    new_energy,
                    new_mask
                )

                # Avoid revisiting identical states
                if state in visited:
                    continue

                visited.add(state)

                queue.append(
                    (
                        nr,
                        nc,
                        new_energy,
                        new_mask,
                        moves + 1
                    )
                )

        # Impossible to collect all litter
        return -1