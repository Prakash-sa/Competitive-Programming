/* =========================================================
   Interactive algorithm traces for Markdown guides
   Dependency-free so they work from the GitHub Pages bundle.
   ========================================================= */

(function () {
  "use strict";

  const FRAME_DELAY = 1350;
  const reducedMotion = window.matchMedia("(prefers-reduced-motion: reduce)");
  let activeVisualizers = [];

  function cellRow(values, options = {}) {
    const {
      active = [],
      range = [],
      done = [],
      muted = [],
      labels = {},
      valuesBelow = {},
    } = options;

    return `<div class="viz-array" role="img" aria-label="${values.join(", ")}">
      ${values
        .map((value, index) => {
          const classes = ["viz-cell"];
          if (active.includes(index)) classes.push("is-active");
          if (range.includes(index)) classes.push("is-range");
          if (done.includes(index)) classes.push("is-done");
          if (muted.includes(index)) classes.push("is-muted");
          return `<div class="viz-cell-wrap">
            <span class="viz-pointer">${labels[index] || ""}</span>
            <span class="${classes.join(" ")}">${value}</span>
            <span class="viz-index">${valuesBelow[index] ?? index}</span>
          </div>`;
        })
        .join("")}
    </div>`;
  }

  const slidingFrames = [
    { start: 0, sum: 8, note: "Build the first size-3 window: 2 + 1 + 5 = 8." },
    { start: 1, sum: 7, note: "Drop 2, add 1. The new sum is 7." },
    { start: 2, sum: 9, note: "Drop 1, add 3. This is the best window so far." },
    { start: 3, sum: 6, note: "Drop 5, add 2. Every element changed the sum once." },
  ];

  const pointerFrames = [
    { left: 0, right: 5, sum: 16, note: "16 is too large, so move the right pointer left." },
    { left: 0, right: 4, sum: 12, note: "12 is too small, so move the left pointer right." },
    { left: 1, right: 4, sum: 13, note: "Still too small—advance the left pointer again." },
    { left: 2, right: 4, sum: 15, note: "Target found: 4 + 11 = 15." },
  ];

  const binaryFrames = [
    { left: 0, right: 7, mid: 3, note: "Check the middle: 8 < 11, so discard the left half." },
    { left: 4, right: 7, mid: 5, note: "Now 14 > 11, so discard the right half." },
    { left: 4, right: 4, mid: 4, note: "The remaining value is 11—the target is found." },
  ];

  const traversalFrames = [
    { current: "A", visited: ["A"], frontier: ["B", "C"], note: "Visit A and enqueue its children B and C." },
    { current: "B", visited: ["A", "B"], frontier: ["C", "D", "E"], note: "Visit B; D and E join the back of the queue." },
    { current: "C", visited: ["A", "B", "C"], frontier: ["D", "E", "F", "G"], note: "Visit C; the whole next level is now queued." },
    { current: "D", visited: ["A", "B", "C", "D"], frontier: ["E", "F", "G"], note: "BFS continues left-to-right through the next level." },
    { current: "E", visited: ["A", "B", "C", "D", "E"], frontier: ["F", "G"], note: "Each node enters and leaves the queue once." },
    { current: "F", visited: ["A", "B", "C", "D", "E", "F"], frontier: ["G"], note: "Only G remains in the frontier." },
    { current: "G", visited: ["A", "B", "C", "D", "E", "F", "G"], frontier: [], note: "Traversal complete in level order: A, B, C, D, E, F, G." },
  ];

  const backtrackingFrames = [
    { active: "root", visited: ["root"], path: "", note: "Start with an empty choice path." },
    { active: "A", visited: ["root", "A"], path: "A", note: "Choose A and continue deeper." },
    { active: "AB", visited: ["root", "A", "AB"], path: "AB", note: "Choose B; one choice remains." },
    { active: "ABC", visited: ["root", "A", "AB", "ABC"], path: "ABC", note: "A complete permutation is emitted." },
    { active: "AB", visited: ["root", "A", "AB", "ABC"], path: "AB", note: "Undo C: backtrack to the last decision." },
    { active: "AC", visited: ["root", "A", "AB", "ABC", "AC"], path: "AC", note: "Try the next unused choice, C." },
    { active: "ACB", visited: ["root", "A", "AB", "ABC", "AC", "ACB"], path: "ACB", note: "A second solution is found; the same pattern explores the rest." },
  ];

  const prefixFrames = [
    { upto: 0, note: "Start with prefix[0] = 0—the sum before the array." },
    { upto: 1, note: "prefix[1] = 0 + 3 = 3." },
    { upto: 2, note: "prefix[2] = 3 + 1 = 4." },
    { upto: 3, note: "prefix[3] = 4 + 4 = 8." },
    { upto: 4, note: "prefix[4] = 8 + 1 = 9." },
    { upto: 5, note: "prefix[5] = 9 + 5 = 14." },
    { upto: 5, query: true, note: "Range [1, 4) = prefix[4] − prefix[1] = 9 − 3 = 6." },
  ];

  const stackFrames = [
    { i: 0, stack: [0], resolved: {}, note: "Push day 0 (73); no warmer day is known yet." },
    { i: 1, stack: [1], resolved: { 0: 1 }, note: "74 resolves day 0, then day 1 enters the stack." },
    { i: 2, stack: [2], resolved: { 0: 1, 1: 1 }, note: "75 resolves day 1. The stack stays decreasing." },
    { i: 3, stack: [2, 3], resolved: { 0: 1, 1: 1 }, note: "71 is cooler, so its index is pushed." },
    { i: 4, stack: [2, 3, 4], resolved: { 0: 1, 1: 1 }, note: "69 is cooler again; unresolved days accumulate." },
    { i: 5, stack: [2, 5], resolved: { 0: 1, 1: 1, 3: 2, 4: 1 }, note: "72 pops and resolves both 69 and 71." },
    { i: 6, stack: [6], resolved: { 0: 1, 1: 1, 2: 4, 3: 2, 4: 1, 5: 1 }, note: "76 resolves 72 and 75. Every index is pushed and popped once." },
  ];

  const sortingFrames = [
    { values: [5, 2, 4, 6, 1, 3], sorted: 0, active: [0], note: "Insertion sort treats the first item as sorted." },
    { values: [2, 5, 4, 6, 1, 3], sorted: 1, active: [0, 1], note: "Insert 2 before 5; the sorted prefix grows." },
    { values: [2, 4, 5, 6, 1, 3], sorted: 2, active: [1, 2], note: "Shift 5 right and insert 4." },
    { values: [2, 4, 5, 6, 1, 3], sorted: 3, active: [3], note: "6 is already in the correct prefix position." },
    { values: [1, 2, 4, 5, 6, 3], sorted: 4, active: [0, 4], note: "Insert 1 at the front after shifting the prefix." },
    { values: [1, 2, 3, 4, 5, 6], sorted: 5, active: [2], note: "Insert 3. The entire array is now sorted." },
  ];

  const intervalFrames = [
    { active: 0, merged: [], current: [1, 4], note: "Start the merged result with [1, 4]." },
    { active: 1, merged: [], current: [1, 6], note: "[3, 6] overlaps, so extend the end to 6." },
    { active: 2, merged: [[1, 6]], current: [8, 10], note: "[8, 10] starts after 6; commit [1, 6]." },
    { active: 3, merged: [[1, 6]], current: [8, 12], note: "[9, 12] overlaps the current interval, so merge it." },
    { active: 3, merged: [[1, 6], [8, 12]], current: null, note: "Done: the four inputs collapse into two disjoint intervals." },
  ];

  function treeSvg(frame) {
    const nodes = [
      ["A", 180, 28], ["B", 95, 90], ["C", 265, 90],
      ["D", 50, 155], ["E", 135, 155], ["F", 225, 155], ["G", 310, 155],
    ];
    const edges = [[180, 43, 95, 75], [180, 43, 265, 75], [95, 105, 50, 140], [95, 105, 135, 140], [265, 105, 225, 140], [265, 105, 310, 140]];
    return `<div class="viz-tree-layout">
      <svg class="viz-tree" viewBox="0 0 360 185" role="img" aria-label="Binary tree breadth-first traversal">
        ${edges.map((edge) => `<line x1="${edge[0]}" y1="${edge[1]}" x2="${edge[2]}" y2="${edge[3]}" />`).join("")}
        ${nodes.map(([name, x, y]) => `<g class="viz-tree-node ${frame.visited.includes(name) ? "is-visited" : ""} ${frame.current === name ? "is-current" : ""}"><circle cx="${x}" cy="${y}" r="18"/><text x="${x}" y="${y + 1}">${name}</text></g>`).join("")}
      </svg>
      <div class="viz-queue"><span>queue</span>${frame.frontier.length ? frame.frontier.map((node) => `<b>${node}</b>`).join("") : "<em>empty</em>"}</div>
    </div>`;
  }

  function backtrackingSvg(frame) {
    const nodes = [
      ["root", "start", 180, 24], ["A", "A", 115, 82], ["B", "B", 245, 82],
      ["AB", "AB", 75, 140], ["AC", "AC", 150, 140], ["BA", "BA", 215, 140], ["BC", "BC", 285, 140],
      ["ABC", "ABC", 50, 195], ["ACB", "ACB", 160, 195],
    ];
    const edges = [[180, 38, 115, 67], [180, 38, 245, 67], [115, 97, 75, 125], [115, 97, 150, 125], [245, 97, 215, 125], [245, 97, 285, 125], [75, 155, 50, 180], [150, 155, 160, 180]];
    return `<div class="viz-backtrack-layout">
      <svg class="viz-tree viz-backtrack-tree" viewBox="0 0 360 220" role="img" aria-label="Backtracking decision tree">
        ${edges.map((edge) => `<line x1="${edge[0]}" y1="${edge[1]}" x2="${edge[2]}" y2="${edge[3]}" />`).join("")}
        ${nodes.map(([id, label, x, y]) => `<g class="viz-tree-node ${frame.visited.includes(id) ? "is-visited" : ""} ${frame.active === id ? "is-current" : ""}"><circle cx="${x}" cy="${y}" r="18"/><text x="${x}" y="${y + 1}">${label}</text></g>`).join("")}
      </svg>
      <div class="viz-path"><span>path</span><b>${frame.path || "∅"}</b></div>
    </div>`;
  }

  function conceptFlow(labels, frame) {
    const active = frame.active || [];
    const done = frame.done || [];
    const muted = frame.muted || [];
    return `<div class="viz-concept-flow" role="img" aria-label="${labels.join(" then ")}">
      ${labels
        .map((label, index) => `<div class="viz-flow-item">
          <div class="viz-flow-node ${active.includes(index) ? "is-active" : ""} ${done.includes(index) ? "is-done" : ""} ${muted.includes(index) ? "is-muted" : ""}">${label}</div>
          ${index < labels.length - 1 ? '<span class="viz-flow-arrow" aria-hidden="true">→</span>' : ""}
        </div>`)
        .join("")}
    </div>`;
  }

  function taskLanes(frame) {
    const labels = ["Task A", "Task B", "Task C"];
    return `<div class="viz-task-lanes" role="img" aria-label="Async event loop task states">
      ${labels.map((label, index) => `<div class="viz-task-lane">
        <b>${label}</b>
        <span class="viz-task-state is-${frame.states[index]}">${frame.states[index]}</span>
      </div>`).join("")}
      <div class="viz-loop-owner"><span>event loop is running</span><strong>${frame.owner}</strong></div>
    </div>`;
  }

  const definitions = {
    "sliding-window": {
      title: "Watch a fixed window move",
      concept: "Each step removes one value and adds one value—constant work per move.",
      frames: slidingFrames,
      render(frame) {
        const values = [2, 1, 5, 1, 3, 2];
        const range = [frame.start, frame.start + 1, frame.start + 2];
        return `${cellRow(values, { range })}<div class="viz-equation"><span>window sum</span><strong>${frame.sum}</strong><span>best</span><strong>${Math.max(...slidingFrames.slice(0, slidingFrames.indexOf(frame) + 1).map((item) => item.sum))}</strong></div>`;
      },
    },
    "two-pointers": {
      title: "Converge on a target pair",
      concept: "Sorted order tells us which pointer can move without missing an answer.",
      frames: pointerFrames,
      render(frame) {
        const values = [1, 2, 4, 7, 11, 15];
        const labels = { [frame.left]: "L", [frame.right]: frame.left === frame.right ? "L / R" : "R" };
        return `${cellRow(values, { active: [frame.left, frame.right], range: Array.from({ length: frame.right - frame.left + 1 }, (_, i) => frame.left + i), labels })}<div class="viz-equation"><span>${values[frame.left]} + ${values[frame.right]}</span><strong>${frame.sum}</strong><span>target</span><strong>15</strong></div>`;
      },
    },
    "binary-search": {
      title: "Halve the search space",
      concept: "One comparison rules out half of the remaining sorted values.",
      frames: binaryFrames,
      render(frame) {
        const values = [2, 4, 6, 8, 11, 14, 18, 21];
        const labels = { [frame.left]: "L", [frame.mid]: frame.mid === frame.left ? "L · M" : "M", [frame.right]: frame.right === frame.mid ? (frame.mid === frame.left ? "L · M · R" : "M · R") : "R" };
        const range = Array.from({ length: frame.right - frame.left + 1 }, (_, i) => frame.left + i);
        const muted = values.map((_, i) => i).filter((i) => !range.includes(i));
        return `${cellRow(values, { active: [frame.mid], range, muted, labels })}<div class="viz-equation"><span>remaining</span><strong>${range.length}</strong><span>target</span><strong>11</strong></div>`;
      },
    },
    traversal: {
      title: "Traverse level by level with BFS",
      concept: "The queue preserves discovery order and exposes the next frontier.",
      frames: traversalFrames,
      render: treeSvg,
    },
    backtracking: {
      title: "Choose, explore, then undo",
      concept: "Backtracking restores the previous state before trying another branch.",
      frames: backtrackingFrames,
      render: backtrackingSvg,
    },
    "dynamic-programming": {
      title: "Build a DP table from solved states",
      concept: "For grid paths, each cell reuses the answers directly above and left.",
      frames: Array.from({ length: 16 }, (_, i) => ({ i, note: i === 0 ? "Seed the start cell with one path." : `Fill cell ${i + 1}: add the values from above and left.` })),
      render(frame) {
        const values = [];
        for (let i = 0; i < 16; i++) {
          if (i > frame.i) { values.push(""); continue; }
          const row = Math.floor(i / 4);
          const col = i % 4;
          values.push(row === 0 || col === 0 ? 1 : values[i - 4] + values[i - 1]);
        }
        const dependencies = [frame.i - 4, frame.i - 1].filter((i) => i >= 0 && (i !== frame.i - 1 || frame.i % 4 !== 0));
        return `<div class="viz-grid" role="img" aria-label="Four by four dynamic programming table">${values.map((value, i) => `<span class="viz-grid-cell ${i === frame.i ? "is-active" : ""} ${dependencies.includes(i) ? "is-dependency" : ""} ${i < frame.i ? "is-done" : ""}">${value}</span>`).join("")}</div><div class="viz-equation"><span>paths to current cell</span><strong>${values[frame.i]}</strong></div>`;
      },
    },
    "prefix-sum": {
      title: "Precompute once, query in O(1)",
      concept: "Subtract two cumulative totals to isolate any contiguous range.",
      frames: prefixFrames,
      render(frame) {
        const values = [3, 1, 4, 1, 5];
        const prefix = [0, 3, 4, 8, 9, 14];
        const visiblePrefix = prefix.map((value, i) => (i <= frame.upto ? value : "·"));
        const queryRange = frame.query ? [1, 2, 3] : [];
        return `<div class="viz-labeled-row"><span>array</span>${cellRow(values, { range: queryRange, valuesBelow: { 0: 0, 1: 1, 2: 2, 3: 3, 4: 4 } })}</div><div class="viz-labeled-row"><span>prefix</span>${cellRow(visiblePrefix, { active: frame.query ? [1, 4] : [frame.upto], valuesBelow: { 0: 0, 1: 1, 2: 2, 3: 3, 4: 4, 5: 5 } })}</div>${frame.query ? '<div class="viz-equation"><span>prefix[4] − prefix[1]</span><strong>6</strong></div>' : ""}`;
      },
    },
    "monotonic-stack": {
      title: "Resolve earlier values with a monotonic stack",
      concept: "The stack keeps unresolved indices in decreasing temperature order.",
      frames: stackFrames,
      render(frame) {
        const values = [73, 74, 75, 71, 69, 72, 76];
        const done = Object.keys(frame.resolved).map(Number);
        return `${cellRow(values, { active: [frame.i], done })}<div class="viz-stack-row"><span>stack</span><div class="viz-stack">${frame.stack.map((index) => `<b>${index}<small>${values[index]}°</small></b>`).join("")}</div></div><div class="viz-answer-row"><span>waits</span>${values.map((_, i) => `<b class="${frame.resolved[i] ? "is-ready" : ""}">${frame.resolved[i] ?? "·"}</b>`).join("")}</div>`;
      },
    },
    sorting: {
      title: "Grow a sorted prefix",
      concept: "Insertion sort shifts larger values, then places the current value into the gap.",
      frames: sortingFrames,
      render(frame) {
        return `<div class="viz-bars" role="img" aria-label="Insertion sort bars">${frame.values.map((value, i) => `<div class="viz-bar-wrap"><span class="viz-bar ${i <= frame.sorted ? "is-done" : ""} ${frame.active.includes(i) ? "is-active" : ""}" style="height:${value * 18}px"></span><b>${value}</b></div>`).join("")}</div>`;
      },
    },
    intervals: {
      title: "Merge overlapping intervals",
      concept: "After sorting by start, compare only with the current merged interval.",
      frames: intervalFrames,
      render(frame) {
        const intervals = [[1, 4], [3, 6], [8, 10], [9, 12]];
        const intervalHtml = intervals.map(([start, end], i) => `<div class="viz-interval-track"><span>${start}</span><b class="${i === frame.active ? "is-active" : ""}" style="left:${start * 6.5}%;width:${(end - start) * 6.5}%">[${start}, ${end}]</b></div>`).join("");
        const result = [...frame.merged, ...(frame.current ? [frame.current] : [])];
        return `<div class="viz-intervals">${intervalHtml}</div><div class="viz-merged"><span>result</span>${result.map(([start, end]) => `<b>[${start}, ${end}]</b>`).join("")}</div>`;
      },
    },
    "python-objects": {
      title: "Watch names bind to Python objects",
      concept: "Mutation changes a shared object; rebinding points one name at a new object.",
      frames: [
        { labels: ["values + alias", "[1, 2]", "shared object"], active: [0, 1], note: "Both names initially refer to the same mutable list." },
        { labels: ["append(3)", "[1, 2, 3]", "both names see it"], active: [0, 1], done: [2], note: "Appending mutates the existing list, so both names observe the change." },
        { labels: ["word + other", '"cat"', "immutable object"], active: [0, 1], note: "Both names can also begin by referring to the same immutable string." },
        { labels: ["word += s", '"cats"', 'other → "cat"'], active: [0, 1], done: [2], note: "String concatenation creates a new object and rebinds only word." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
    "python-arguments": {
      title: "Trace argument binding through a call",
      concept: "Parameters are local names bound to the caller's objects.",
      frames: [
        { labels: ["caller values", "function values", "same list"], active: [0, 1], note: "The caller and parameter names refer to the same list object." },
        { labels: ["values.append", "mutate list", "caller sees change"], active: [0, 1], done: [2], note: "Mutating the shared list is visible after the function returns." },
        { labels: ["caller count", "function count", "same int"], active: [0, 1], note: "The count names initially refer to the same immutable integer." },
        { labels: ["count += 1", "new int", "caller unchanged"], active: [0, 1], done: [2], note: "Rebinding the local parameter cannot rebind the caller's name." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
    "python-legb": {
      title: "Follow Python's LEGB name lookup",
      concept: "Name resolution stops at the first scope containing the requested name.",
      frames: [
        { active: [0], note: "Python first checks the current local scope." },
        { done: [0], active: [1], note: "If absent locally, it checks enclosing function scopes." },
        { done: [0, 1], active: [2], note: "Next it checks the module's global scope." },
        { done: [0, 1, 2], active: [3], note: "Built-ins are the final namespace checked before NameError." },
      ],
      render(frame) {
        return conceptFlow(["Local", "Enclosing", "Global", "Built-ins"], frame);
      },
    },
    "python-copy": {
      title: "Compare shallow and deep copies",
      concept: "A shallow copy duplicates only the outer container; a deep copy duplicates nested data too.",
      frames: [
        { labels: ["original", "outer list", "nested lists"], active: [0, 1, 2], note: "The original owns an outer container that refers to nested lists." },
        { labels: ["shallow copy", "new outer list", "shared nested lists"], active: [0, 1], done: [2], note: "A shallow copy creates a new outer list but keeps references to the same children." },
        { labels: ["mutate child", "original changes", "shallow changes"], active: [0], done: [1, 2], note: "Mutating a shared nested list is visible through both outer containers." },
        { labels: ["deep copy", "new outer list", "new nested lists"], active: [0], done: [1, 2], note: "A deep copy recursively creates independent nested objects." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
    "python-dictionary": {
      title: "Trace a dictionary lookup",
      concept: "A stable key hash narrows the search to a bucket before equality confirms the key.",
      frames: [
        { active: [0], note: "Start with the lookup key." },
        { done: [0], active: [1], note: "Python computes the key's hash." },
        { done: [0, 1], active: [2], note: "The hash identifies where to probe in the table." },
        { done: [0, 1, 2], active: [3], note: "Equality checks distinguish keys if a collision occurs." },
        { done: [0, 1, 2, 3], active: [4], note: "The matching entry yields its stored value." },
      ],
      render(frame) {
        return conceptFlow(["key", "hash", "bucket", "equality", "value"], frame);
      },
    },
    "python-iterator": {
      title: "Consume an iterator one value at a time",
      concept: "The iterator remembers its position and eventually signals exhaustion.",
      frames: [
        { position: 0, active: [0], note: "iter(numbers) creates an iterator positioned before the first item." },
        { position: 1, active: [0], done: [0], note: "The first next() call returns 1 and advances the iterator." },
        { position: 2, active: [1], done: [0], note: "The second call returns 2." },
        { position: 3, active: [2], done: [0, 1], note: "The third call returns 3 and reaches the end." },
        { position: 3, active: [], done: [0, 1, 2], note: "Another next() call raises StopIteration." },
      ],
      render(frame) {
        const labels = frame.position < 3 ? { [frame.position]: "next" } : {};
        return `${cellRow([1, 2, 3], { active: frame.active, done: frame.done, labels })}<div class="viz-equation"><span>iterator position</span><strong>${frame.position < 3 ? frame.position : "exhausted"}</strong></div>`;
      },
    },
    "python-decorator": {
      title: "See a decorator wrap a function",
      concept: "Decoration replaces the original name with the callable returned by the decorator.",
      frames: [
        { active: [0], note: "Python first creates the original add function." },
        { done: [0], active: [1], note: "The function is passed to traced at definition time." },
        { done: [0, 1], active: [2], note: "traced returns wrapper, which is stored under the name add." },
        { done: [0, 1, 2], active: [3], note: "Calling add now enters wrapper, which logs and calls the original function." },
      ],
      render(frame) {
        return conceptFlow(["original add", "traced(add)", "wrapper", "call result"], frame);
      },
    },
    "python-mro": {
      title: "Walk a multiple-inheritance MRO",
      concept: "C3 linearization gives every class a consistent attribute lookup order.",
      frames: [
        { active: [0], note: "Lookup begins on Child itself." },
        { done: [0], active: [1], note: "The first declared branch, Left, is searched next." },
        { done: [0, 1], active: [2], note: "The other branch, Right, follows without revisiting shared ancestors." },
        { done: [0, 1, 2], active: [3], note: "The shared Base class appears once after both branches." },
        { done: [0, 1, 2, 3], active: [4], note: "object completes the lookup chain." },
      ],
      render(frame) {
        return conceptFlow(["Child", "Left", "Right", "Base", "object"], frame);
      },
    },
    "python-context": {
      title: "Guarantee cleanup with a context manager",
      concept: "Both successful and exceptional paths pass through __exit__.",
      frames: [
        { labels: ["with", "__enter__", "resource ready"], active: [0, 1], done: [2], note: "Entering the with statement acquires or prepares the resource." },
        { labels: ["resource ready", "execute block", "work"], done: [0], active: [1, 2], note: "The managed resource is available inside the block." },
        { labels: ["normal return", "__exit__", "cleanup"], active: [0, 1], done: [2], note: "Normal completion invokes __exit__ and performs cleanup." },
        { labels: ["exception", "__exit__", "cleanup + decision"], active: [0, 1], done: [2], note: "An exception also invokes __exit__, which may suppress it or let it propagate." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
    "python-concurrency": {
      title: "Choose a Python concurrency model",
      concept: "Workload shape determines whether processes, threads, or an event loop fit best.",
      frames: [
        { labels: ["workload", "CPU-bound", "processes"], active: [0, 1], done: [2], note: "CPU-heavy pure-Python work often benefits from process-based parallelism." },
        { labels: ["workload", "blocking I/O", "threads"], active: [0, 1], done: [2], note: "Threads are a straightforward fit for a moderate number of blocking I/O tasks." },
        { labels: ["many I/O tasks", "async libraries", "asyncio"], active: [0, 1], done: [2], note: "An async-compatible stack can efficiently coordinate many concurrent I/O operations." },
        { labels: ["candidate", "measure workload", "verify choice"], active: [0, 1], done: [2], note: "Benchmark the real workload because overhead and library behavior matter." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
    "python-async": {
      title: "Watch tasks cooperate on one event loop",
      concept: "A task that awaits I/O yields the event-loop thread so another ready task can run.",
      frames: [
        { owner: "Task A", states: ["running", "ready", "ready"], note: "Task A begins on the event-loop thread." },
        { owner: "Task B", states: ["waiting", "running", "ready"], note: "Task A awaits I/O, so Task B gets a turn." },
        { owner: "Task C", states: ["waiting", "waiting", "running"], note: "Task B also awaits, allowing Task C to run." },
        { owner: "Task A", states: ["running", "waiting", "done"], note: "Task C finishes and Task A's I/O becomes ready." },
        { owner: "Task B", states: ["done", "running", "done"], note: "Task A completes, then Task B resumes." },
        { owner: "none", states: ["done", "done", "done"], note: "All three tasks complete without running simultaneously on this thread." },
      ],
      render: taskLanes,
    },
    "python-memory": {
      title: "See how CPython reclaims objects",
      concept: "Reference counting handles most objects; cyclic garbage collection handles unreachable cycles.",
      frames: [
        { labels: ["name", "object", "refcount 1"], active: [0, 1], note: "Binding a name adds a reference to the object." },
        { labels: ["second name", "same object", "refcount 2"], active: [0, 1], note: "Another binding raises the reference count." },
        { labels: ["del names", "refcount 0", "reclaim"], active: [0, 1], done: [2], note: "When the count reaches zero, CPython can reclaim the object." },
        { labels: ["A refers to B", "B refers to A", "cycle"], active: [0, 1], note: "A cycle can keep reference counts above zero even when nothing outside can reach it." },
        { labels: ["unreachable cycle", "cycle detector", "reclaim"], active: [0, 1], done: [2], note: "The cyclic garbage collector detects and reclaims the unreachable group." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
    "python-lru": {
      title: "Trace an O(1) LRU cache access",
      concept: "A dictionary finds nodes quickly while a linked list maintains recency order.",
      frames: [
        { labels: ["lookup key", "dictionary", "node"], active: [0, 1], done: [2], note: "The dictionary locates the cache node in average O(1) time." },
        { labels: ["detach node", "linked list", "old position removed"], active: [0, 1], done: [2], note: "A cache hit detaches the node from its current list position." },
        { labels: ["node", "move to front", "most recent"], active: [0, 1], done: [2], note: "The node becomes the most recently used entry." },
        { labels: ["cache full", "tail node", "least recent"], active: [0, 1], note: "When full, the tail identifies the least recently used entry." },
        { labels: ["remove tail", "delete dictionary key", "space ready"], active: [0, 1], done: [2], note: "Removing from both structures keeps eviction O(1)." },
      ],
      render(frame) {
        return conceptFlow(frame.labels, frame);
      },
    },
  };

  const headingRules = [
    [/sliding window/i, "sliding-window"],
    [/two[- ]?pointers?|slow and fast pointer/i, "two-pointers"],
    [/binary search/i, "binary-search"],
    [/binary tree traversal|tree traversal|breadth.?first|depth.?first|\b(?:bfs|dfs)\b/i, "traversal"],
    [/backtracking/i, "backtracking"],
    [/dynamic programming|\bdp\b/i, "dynamic-programming"],
    [/prefix sums?/i, "prefix-sum"],
    [/monotonic stack/i, "monotonic-stack"],
    [/sorting|\bsort\b/i, "sorting"],
    [/interval|sweep line/i, "intervals"],
    [/mutable versus immutable/i, "python-objects"],
    [/arguments passed in python/i, "python-arguments"],
    [/\bLEGB\b/i, "python-legb"],
    [/shallow and deep copying/i, "python-copy"],
    [/dictionaries work/i, "python-dictionary"],
    [/iterable and an iterator/i, "python-iterator"],
    [/what is a decorator/i, "python-decorator"],
    [/method resolution order/i, "python-mro"],
    [/what is a context manager/i, "python-context"],
    [/threads, processes, or.*asyncio/i, "python-concurrency"],
    [/async.*await/i, "python-async"],
    [/memory managed in CPython/i, "python-memory"],
    [/build an LRU cache/i, "python-lru"],
  ];

  function createVisualizer(definition, kind) {
    const card = document.createElement("section");
    card.className = `algorithm-viz algorithm-viz-${kind}`;
    card.setAttribute("aria-label", definition.title);
    card.innerHTML = `
      <div class="viz-header">
        <div>
          <span class="viz-kicker">Interactive trace</span>
          <h4>${definition.title}</h4>
          <p>${definition.concept}</p>
        </div>
        <span class="viz-frame-count" aria-hidden="true"></span>
      </div>
      <div class="viz-stage"></div>
      <p class="viz-caption" aria-live="polite"></p>
      <div class="viz-controls">
        <button type="button" data-action="toggle" aria-label="Pause animation"><span aria-hidden="true">Ⅱ</span> Pause</button>
        <button type="button" data-action="step" aria-label="Show next step"><span aria-hidden="true">→</span> Step</button>
        <button type="button" data-action="restart" aria-label="Restart animation"><span aria-hidden="true">↻</span> Restart</button>
      </div>`;

    const stage = card.querySelector(".viz-stage");
    const caption = card.querySelector(".viz-caption");
    const counter = card.querySelector(".viz-frame-count");
    const toggle = card.querySelector('[data-action="toggle"]');
    let frameIndex = 0;
    let timer = null;
    let userPaused = reducedMotion.matches;

    function render() {
      const frame = definition.frames[frameIndex];
      stage.innerHTML = definition.render(frame);
      caption.textContent = frame.note;
      counter.textContent = `${frameIndex + 1} / ${definition.frames.length}`;
    }

    function setToggleLabel(isPlaying) {
      toggle.innerHTML = isPlaying
        ? '<span aria-hidden="true">Ⅱ</span> Pause'
        : '<span aria-hidden="true">▶</span> Play';
      toggle.setAttribute("aria-label", isPlaying ? "Pause animation" : "Play animation");
    }

    function stop() {
      if (timer) window.clearInterval(timer);
      timer = null;
      setToggleLabel(false);
    }

    function next() {
      frameIndex = (frameIndex + 1) % definition.frames.length;
      render();
    }

    function start() {
      if (timer || reducedMotion.matches) return;
      timer = window.setInterval(next, FRAME_DELAY);
      setToggleLabel(true);
    }

    toggle.addEventListener("click", () => {
      if (timer) {
        userPaused = true;
        stop();
      } else {
        userPaused = false;
        if (reducedMotion.matches) {
          next();
        } else {
          start();
        }
      }
    });

    card.querySelector('[data-action="step"]').addEventListener("click", () => {
      userPaused = true;
      stop();
      next();
    });

    card.querySelector('[data-action="restart"]').addEventListener("click", () => {
      frameIndex = 0;
      render();
      if (!userPaused) start();
    });

    const observer = "IntersectionObserver" in window
      ? new IntersectionObserver((entries) => {
          entries.forEach((entry) => {
            if (entry.isIntersecting && !userPaused) start();
            if (!entry.isIntersecting) stop();
          });
        }, { threshold: 0.35 })
      : null;

    setToggleLabel(false);
    if (observer) observer.observe(card);
    else if (!userPaused) start();
    render();

    return {
      element: card,
      destroy() {
        stop();
        if (observer) observer.disconnect();
      },
    };
  }

  function destroy() {
    activeVisualizers.forEach((visualizer) => visualizer.destroy());
    activeVisualizers = [];
  }

  function enhance(container) {
    destroy();
    if (!container) return;

    const usedKinds = new Set();
    const headings = container.querySelectorAll("h2, h3");
    headings.forEach((heading) => {
      const text = heading.textContent.trim();
      const match = headingRules.find(([pattern, kind]) => pattern.test(text) && !usedKinds.has(kind));
      if (!match) return;

      const kind = match[1];
      const definition = definitions[kind];
      if (!definition) return;

      const visualizer = createVisualizer(definition, kind);
      heading.insertAdjacentElement("afterend", visualizer.element);
      activeVisualizers.push(visualizer);
      usedKinds.add(kind);
    });
  }

  window.AlgorithmVisualizations = { enhance, destroy };
})();
