# Contributing

Thanks for helping improve this competitive programming reference. This repository is meant to stay practical: correct solutions, clear explanations, and easy navigation by topic.

## Ways to contribute

- Add a missing solution to an existing topic folder.
- Improve the readability, complexity notes, or edge-case handling of an existing solution.
- Add or improve topic notes in Markdown.
- Fix broken links, typos, formatting, or GitHub Pages documentation behavior.
- Report incorrect solutions or confusing explanations with a minimal failing case.

## Repository structure

- Topic folders such as `Graph/`, `Dynamic Programming/`, `Binary Search/`, and `Stack/` contain source solutions and notes.
- `docs/` contains the static GitHub Pages viewer.
- `docs/build_tree.py` regenerates `docs/tree.json` and mirrors repository content into `docs/content/`.
- `.github/` contains issue templates, pull request guidance, and automation.

## Adding or updating solutions

1. Put the file in the most specific existing topic folder. Create a new folder only when the topic does not already exist.
2. Use the naming style already used in the repo:

   ```text
   <problem-number>. <Problem Title>.py
   ```

   If a problem has no stable number, use a clear descriptive title.
3. Prefer Python unless the surrounding folder already uses another language.
4. Keep solutions self-contained. Avoid depending on local files such as `in.txt` or `out.txt`.
5. Include imports needed outside online judges, for example:

   ```python
   from typing import List, Optional
   ```

6. Add brief complexity notes when they make the approach easier to review.
7. Preserve accepted online-judge signatures when relevant, such as `class Solution`.
8. Do not commit generated caches, editor files, logs, or local virtual environments.

## Adding or updating notes

- Keep notes concise and example-driven.
- Prefer working code snippets over abstract descriptions when possible.
- Put topic-level explanations in that topic folder's `README.md` or existing guide file.
- Avoid copying long problem statements or editorial text from external platforms. Summarize in your own words and link to the source when useful.

## GitHub Pages content

The Pages workflow runs `python3 docs/build_tree.py` automatically on deploy. If you change the docs viewer itself or want to verify navigation locally, run:

```bash
python3 docs/build_tree.py
```

Do not hand-edit files under `docs/content/`; they are generated mirrors of the source files.

## Local checks

Before opening a pull request, run the checks that apply to your change:

```bash
python3 -m py_compile path/to/solution.py
python3 docs/build_tree.py
```

For algorithm fixes, include the test case or input that proves the bug and explain the expected output.

## Pull request checklist

- The file is in the right topic folder.
- The solution is correct for important edge cases.
- Complexity is documented when helpful.
- Generated or local-only files are not included accidentally.
- The pull request description explains what changed and why.

## Review expectations

Maintainers may ask for simpler code, clearer naming, complexity notes, or a failing test case before merging. Small, focused pull requests are easier to review than broad rewrites.
