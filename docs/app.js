/* =========================================================
   CP Interview Prep — Main Application
   ========================================================= */

const TOPIC_ICONS = {
  "2 Pointers": "👆",
  Array: "📊",
  "Binary Search": "🔍",
  "Binary Search Tree": "🌲",
  "Binary Tree": "🌳",
  "Bit Manipulation": "🔢",
  "Dynamic Programming": "💡",
  Graph: "🕸️",
  Greedy: "🏃",
  Hashing: "🗂️",
  Heap: "⛰️",
  Intervals: "📏",
  LinkedList: "🔗",
  Mathematics: "🧮",
  Matrix: "🔲",
  "Operating Systems": "🖥️",
  "Prefix Sum & Partial Sum": "➕",
  "Prefix Sum": "➕",
  Queue: "📥",
  "Recursion & Backtracking": "🔄",
  "Segment Trees": "🌿",
  "Sliding Window": "🪟",
  Sorting: "📶",
  Stack: "📚",
  Strings: "🔤",
  "System Design": "🏗️",
  Tries: "🌐",
};

const STORAGE_KEY = "cp-interview-reviewed";
const THEME_KEY = "cp-interview-theme";

const state = {
  tree: null,
  repoOwner: null,
  repoName: null,
  branch: "master",
  currentPath: null,
  activeElement: null,
  reviewed: {},
  allFiles: [],
  allFolders: [],
  sidebarOpen: true,
};

// ─── DOM refs ───
const $ = (id) => document.getElementById(id);
const treeRoot = $("treeRoot");
const contentTitle = $("contentTitle");
const contentMeta = $("contentMeta");
const breadcrumb = $("breadcrumb");
const openOnGitHub = $("openOnGitHub");
const repoLink = $("repoLink");
const searchModal = $("searchModal");
const searchModalInput = $("searchModalInput");
const searchResults = $("searchResults");
const searchTrigger = $("searchTrigger");
const themeToggle = $("themeToggle");
const collapseAll = $("collapseAll");
const mobileMenuBtn = $("mobileMenuBtn");
const sidebar = $("sidebar");
const layout = $("layout");
const welcomeScreen = $("welcomeScreen");
const fileView = $("fileView");
const markdownContent = $("markdownContent");
const imageContent = $("imageContent");
const codeView = $("codeView");
const codeBlock = $("codeBlock");
const codeLang = $("codeLang");
const codeCopyBtn = $("codeCopyBtn");
const markReviewedBtn = $("markReviewed");
const progressBadge = $("progressBadge");
const progressText = $("progressText");
const topicGrid = $("topicGrid");
const statsBar = $("statsBar");
const shortcutsToast = $("shortcutsToast");

// ─── Marked config ───
if (window.marked) {
  window.marked.setOptions({ breaks: true, gfm: true });
}

// ─── Theme ───
function loadTheme() {
  const saved = localStorage.getItem(THEME_KEY);
  if (saved) {
    document.documentElement.setAttribute("data-theme", saved);
  } else if (window.matchMedia("(prefers-color-scheme: dark)").matches) {
    document.documentElement.setAttribute("data-theme", "dark");
  }
  updateHljsTheme();
}

function toggleTheme() {
  const current = document.documentElement.getAttribute("data-theme");
  const next = current === "dark" ? "light" : "dark";
  document.documentElement.setAttribute("data-theme", next);
  localStorage.setItem(THEME_KEY, next);
  updateHljsTheme();
}

function updateHljsTheme() {
  const theme = document.documentElement.getAttribute("data-theme");
  const link = document.getElementById("hljs-theme");
  if (link) {
    link.href =
      theme === "dark"
        ? "https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/styles/github-dark.min.css"
        : "https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/styles/github.min.css";
  }
}

// ─── LocalStorage progress ───
function loadReviewed() {
  try {
    const data = localStorage.getItem(STORAGE_KEY);
    state.reviewed = data ? JSON.parse(data) : {};
  } catch {
    state.reviewed = {};
  }
}

function saveReviewed() {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(state.reviewed));
}

function isReviewed(path) {
  return !!state.reviewed[path];
}

function toggleReviewed(path) {
  if (state.reviewed[path]) {
    delete state.reviewed[path];
  } else {
    state.reviewed[path] = Date.now();
  }
  saveReviewed();
  updateProgressUI();
}

function updateProgressUI() {
  const total = state.allFiles.length;
  const done = state.allFiles.filter((f) => state.reviewed[f.path]).length;
  const pct = total > 0 ? Math.round((done / total) * 100) : 0;
  progressText.textContent = `${pct}%`;

  // Update mark reviewed button state
  if (state.currentPath) {
    const isRev = isReviewed(state.currentPath);
    markReviewedBtn.classList.toggle("reviewed", isRev);
    markReviewedBtn.querySelector("span").textContent = isRev ? "Reviewed" : "Mark Reviewed";
  }

  // Update tree checkmarks
  document.querySelectorAll(".tree-file-reviewed").forEach((el) => {
    const path = el.dataset.path;
    const checked = isReviewed(path);
    el.classList.toggle("checked", checked);
  });

  // Update folder progress dots
  document.querySelectorAll(".tree-folder-progress").forEach((el) => {
    const folderPath = el.dataset.folder;
    const folderFiles = state.allFiles.filter((f) => f.path.startsWith(folderPath + "/"));
    const hasAny = folderFiles.some((f) => state.reviewed[f.path]);
    el.classList.toggle("has-progress", hasAny);
  });

  // Update topic cards
  document.querySelectorAll(".topic-card-progress-fill").forEach((el) => {
    const folder = el.dataset.folder;
    const folderFiles = state.allFiles.filter((f) => f.path.startsWith(folder + "/"));
    const folderDone = folderFiles.filter((f) => state.reviewed[f.path]).length;
    const folderPct = folderFiles.length > 0 ? (folderDone / folderFiles.length) * 100 : 0;
    el.style.width = `${folderPct}%`;
  });
}

// ─── Utilities ───
function encodePath(path) {
  return path
    .split("/")
    .map((s) => encodeURIComponent(s))
    .join("/");
}

function fileUrl(path) {
  if (state.useLocalContent) {
    return `content/${encodePath(path)}`;
  }
  return `https://raw.githubusercontent.com/${state.repoOwner}/${state.repoName}/${state.branch}/${encodePath(path)}`;
}

function githubUrl(path) {
  return `https://github.com/${state.repoOwner}/${state.repoName}/blob/${state.branch}/${encodePath(path)}`;
}

function fileExt(path) {
  const parts = path.split(".");
  return parts.length > 1 ? parts.pop().toLowerCase() : "";
}

function langForExt(ext) {
  const map = {
    py: "python",
    cpp: "cpp",
    c: "c",
    java: "java",
    js: "javascript",
    ts: "typescript",
    md: "markdown",
    txt: "plaintext",
    sh: "bash",
    json: "json",
    yml: "yaml",
    yaml: "yaml",
    go: "go",
    rs: "rust",
  };
  return map[ext] || "";
}

function isImage(path) {
  return ["png", "jpg", "jpeg", "gif", "svg", "webp"].includes(fileExt(path));
}

function isMarkdown(path) {
  return fileExt(path) === "md";
}

function escapeHtml(text) {
  return text.replace(/[&<>"']/g, (c) =>
    ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" })[c]
  );
}

function normalizeRepoPath(basePath, href) {
  if (!href) return null;
  if (
    href.startsWith("http://") ||
    href.startsWith("https://") ||
    href.startsWith("mailto:") ||
    href.startsWith("#")
  ) {
    return null;
  }

  let raw = href;
  try {
    raw = decodeURIComponent(href);
  } catch {
    raw = href;
  }

  // Strip optional leading slash or current-dir prefix used in markdown links.
  raw = raw.replace(/^\.?\//, "");

  const baseParts = basePath ? basePath.split("/").slice(0, -1) : [];
  const parts = raw.split("/").filter(Boolean);
  const resolved = raw.startsWith("/") ? [] : [...baseParts];

  for (const part of parts) {
    if (part === ".") continue;
    if (part === "..") {
      resolved.pop();
      continue;
    }
    resolved.push(part);
  }

  return resolved.join("/");
}

function wireMarkdownLinks(container, currentPath) {
  container.querySelectorAll("a[href]").forEach((link) => {
    const href = link.getAttribute("href");
    const targetPath = normalizeRepoPath(currentPath, href);
    if (!targetPath) {
      if (/^https?:\/\//.test(href || "")) {
        link.target = "_blank";
        link.rel = "noreferrer";
      }
      return;
    }

    const exists = state.allFiles.some((file) => file.path === targetPath);
    if (!exists) return;

    link.setAttribute("href", `?path=${encodeURIComponent(targetPath)}`);
    link.addEventListener("click", (event) => {
      event.preventDefault();
      loadFile(targetPath);
    });
  });
}

function pathFromUrl() {
  const params = new URLSearchParams(window.location.search);
  return params.get("path") ? decodeURIComponent(params.get("path")) : null;
}

function updateUrl(path) {
  const params = new URLSearchParams(window.location.search);
  params.set("path", encodeURIComponent(path));
  window.history.pushState({}, "", `${window.location.pathname}?${params}`);
}

// ─── Flatten tree ───
function flattenTree(node, result = { files: [], folders: [] }) {
  if (node.type === "dir") {
    if (node.path) result.folders.push(node);
    (node.children || []).forEach((c) => flattenTree(c, result));
  } else {
    result.files.push(node);
  }
  return result;
}

// ─── File icon ───
function fileIcon(ext) {
  const icons = {
    py: "🐍",
    cpp: "⚡",
    c: "⚡",
    java: "☕",
    js: "📜",
    md: "📝",
    json: "📋",
    sh: "🖥️",
    txt: "📄",
  };
  return icons[ext] || "📄";
}

// ─── Count files recursively ───
function countFiles(node) {
  if (node.type === "file") return 1;
  return (node.children || []).reduce((sum, c) => sum + countFiles(c), 0);
}

// ─── Render sidebar tree ───
function renderTree(tree) {
  treeRoot.innerHTML = "";
  const topDirs = (tree.children || []).filter((n) => n.type === "dir");
  const topFiles = (tree.children || []).filter((n) => n.type === "file");

  topDirs.forEach((node) => treeRoot.appendChild(createFolderNode(node)));
  topFiles.forEach((node) => treeRoot.appendChild(createFileNode(node)));
}

function createFolderNode(node) {
  const group = document.createElement("div");
  group.className = "tree-group";
  group.dataset.name = node.name.toLowerCase();

  const folder = document.createElement("div");
  folder.className = "tree-folder";

  const icon = document.createElement("span");
  icon.className = "tree-folder-icon";
  icon.textContent = TOPIC_ICONS[node.name] || "📁";

  const name = document.createElement("span");
  name.className = "tree-folder-name";
  name.textContent = node.name;

  const count = document.createElement("span");
  count.className = "tree-folder-count";
  count.textContent = countFiles(node);

  const progress = document.createElement("span");
  progress.className = "tree-folder-progress";
  progress.dataset.folder = node.path;

  const caret = document.createElement("span");
  caret.className = "tree-folder-caret";
  caret.innerHTML = `<svg width="12" height="12" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M9 18l6-6-6-6"/></svg>`;

  folder.append(icon, name, count, progress, caret);

  const children = document.createElement("div");
  children.className = "tree-children";

  const childDirs = (node.children || []).filter((c) => c.type === "dir");
  const childFiles = (node.children || []).filter((c) => c.type === "file");
  childDirs.forEach((c) => children.appendChild(createFolderNode(c)));
  childFiles.forEach((c) => children.appendChild(createFileNode(c)));

  folder.addEventListener("click", () => {
    const expanded = children.classList.toggle("expanded");
    caret.classList.toggle("expanded", expanded);
  });

  group.append(folder, children);
  return group;
}

function createFileNode(node) {
  const file = document.createElement("div");
  file.className = "tree-file";
  file.dataset.path = node.path;
  file.dataset.name = node.name.toLowerCase();

  const icon = document.createElement("span");
  icon.className = "tree-file-icon";
  icon.textContent = fileIcon(node.ext);

  const name = document.createElement("span");
  name.className = "tree-file-name";
  name.textContent = node.name;

  const ext = document.createElement("span");
  ext.className = "tree-file-ext";
  ext.textContent = node.ext || "";

  const reviewed = document.createElement("span");
  reviewed.className = "tree-file-reviewed" + (isReviewed(node.path) ? " checked" : "");
  reviewed.dataset.path = node.path;
  reviewed.innerHTML = `<svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="3"><polyline points="20 6 9 17 4 12"/></svg>`;

  file.append(icon, name, ext, reviewed);

  file.addEventListener("click", (e) => {
    // If clicking on the reviewed circle, toggle review instead
    if (e.target.closest(".tree-file-reviewed")) {
      e.stopPropagation();
      toggleReviewed(node.path);
      return;
    }
    loadFile(node.path);
    // Close mobile sidebar
    sidebar.classList.remove("mobile-open");
    const overlay = document.querySelector(".sidebar-overlay");
    if (overlay) overlay.classList.remove("active");
  });

  return file;
}

// ─── Set active file in sidebar ───
function setActive(path) {
  if (state.activeElement) state.activeElement.classList.remove("active");
  const el = treeRoot.querySelector(`.tree-file[data-path="${CSS.escape(path)}"]`);
  if (el) {
    el.classList.add("active");
    state.activeElement = el;
    // Expand parent folders
    let parent = el.parentElement;
    while (parent && parent !== treeRoot) {
      if (parent.classList.contains("tree-children")) {
        parent.classList.add("expanded");
        const prevCaret = parent.previousElementSibling?.querySelector(".tree-folder-caret");
        if (prevCaret) prevCaret.classList.add("expanded");
      }
      parent = parent.parentElement;
    }
    el.scrollIntoView({ block: "nearest", behavior: "smooth" });
  }
}

// ─── Breadcrumb ───
function renderBreadcrumb(path) {
  breadcrumb.innerHTML = "";
  const parts = path.split("/");
  parts.forEach((part, i) => {
    if (i > 0) {
      const sep = document.createElement("span");
      sep.className = "breadcrumb-sep";
      sep.textContent = "/";
      breadcrumb.appendChild(sep);
    }
    const item = document.createElement("span");
    item.className = "breadcrumb-item";
    item.textContent = part;
    if (i < parts.length - 1) {
      const folderPath = parts.slice(0, i + 1).join("/");
      item.addEventListener("click", () => {
        // Expand folder in sidebar
        const group = treeRoot.querySelector(
          `.tree-group[data-name="${CSS.escape(part.toLowerCase())}"]`
        );
        if (group) {
          const children = group.querySelector(".tree-children");
          const caret = group.querySelector(".tree-folder-caret");
          if (children) children.classList.add("expanded");
          if (caret) caret.classList.add("expanded");
        }
      });
    }
    breadcrumb.appendChild(item);
  });
}

// ─── Parse Python file into 3 sections: header, code body, footer notes ───
function parsePythonFile(text) {
  const lines = text.split("\n");
  let i = 0;

  // --- Section 1: Header (leading # URL + docstring) ---
  const headerLines = [];
  let inDocstring = false;
  let headerDone = false;

  while (i < lines.length && !headerDone) {
    const trimmed = lines[i].trim();

    if (inDocstring) {
      headerLines.push(lines[i]);
      if (trimmed.endsWith("'''") || trimmed.endsWith('"""')) {
        inDocstring = false;
        headerDone = true;
      }
      i++;
      continue;
    }

    // Leading # lines (URL, etc.) — only at very top before any code
    if (/^\s*#/.test(lines[i]) && headerLines.length === 0 ||
        /^\s*#/.test(lines[i]) && headerLines.every(l => /^\s*#/.test(l) || l.trim() === "")) {
      headerLines.push(lines[i]);
      i++;
      continue;
    }

    // Blank lines between # and docstring
    if (trimmed === "" && headerLines.length > 0) {
      headerLines.push(lines[i]);
      i++;
      continue;
    }

    // Docstring opener
    if (trimmed.startsWith("'''") || trimmed.startsWith('"""')) {
      const opener = trimmed.slice(0, 3);
      if (trimmed.length > 6 && trimmed.endsWith(opener)) {
        headerLines.push(lines[i]);
        headerDone = true;
        i++;
        continue;
      }
      headerLines.push(lines[i]);
      inDocstring = true;
      i++;
      continue;
    }

    // Not a comment/docstring — header section is over
    break;
  }

  // Skip blank lines after header
  while (i < lines.length && lines[i].trim() === "") i++;

  // --- Collect remaining lines ---
  const restLines = [];
  while (i < lines.length) {
    restLines.push({ text: lines[i], origIdx: i });
    i++;
  }

  // Trim trailing blank lines
  while (restLines.length > 0 && restLines[restLines.length - 1].text.trim() === "") {
    restLines.pop();
  }

  // --- Section 3: Split trailing # comment block as footer notes ---
  const footerLines = [];
  let j = restLines.length - 1;
  while (j >= 0) {
    const t = restLines[j].text.trim();
    if (/^#/.test(t) || t === "") {
      footerLines.unshift(restLines[j]);
      j--;
    } else {
      break;
    }
  }
  // Only treat as footer if we found at least 2 comment lines (not just a trailing blank)
  const hasFooter = footerLines.filter(l => /^\s*#/.test(l.text)).length >= 2;
  const codeRest = hasFooter ? restLines.slice(0, j + 1) : restLines;
  const footer = hasFooter ? footerLines : [];

  // Trim trailing blanks from code section
  while (codeRest.length > 0 && codeRest[codeRest.length - 1].text.trim() === "") {
    codeRest.pop();
  }

  return {
    headerLines,
    codeLines: codeRest.map(l => l.text),
    codeStartLine: codeRest.length > 0 ? codeRest[0].origIdx + 1 : 1,
    footerLines: footer.map(l => l.text),
  };
}

// ─── Clean header lines into description HTML ───
function buildDescriptionHtml(headerLines) {
  const cleaned = headerLines.map((line) => {
    let s = line;
    s = s.replace(/^\s*#\s?/, "");
    s = s.replace(/^\s*'''$/, "").replace(/^\s*"""$/, "");
    s = s.replace(/^\s*'''/, "").replace(/^\s*"""/, "");
    s = s.replace(/'''\s*$/, "").replace(/"""\s*$/, "");
    return s;
  });

  let url = "";
  const textLines = [];
  for (const line of cleaned) {
    const urlMatch = line.match(/https?:\/\/[^\s]+/);
    if (urlMatch && !url) {
      url = urlMatch[0];
    } else {
      textLines.push(line);
    }
  }

  while (textLines.length > 0 && textLines[0].trim() === "") textLines.shift();
  while (textLines.length > 0 && textLines[textLines.length - 1].trim() === "") textLines.pop();

  let html = "";
  if (url) {
    html += `<a class="desc-link" href="${escapeHtml(url)}" target="_blank" rel="noreferrer">${escapeHtml(url)}</a>`;
  }
  if (textLines.length > 0) {
    html += `<div class="desc-text">${escapeHtml(textLines.join("\n"))}</div>`;
  }
  return html;
}

// ─── Clean footer comment lines ───
function buildFooterHtml(footerLines) {
  const cleaned = footerLines
    .map((line) => line.replace(/^\s*#\s?/, ""))
    .join("\n")
    .trim();
  if (!cleaned) return "";
  return `<div class="code-footer"><div class="code-footer-label">Notes</div><div class="code-footer-text">${escapeHtml(cleaned)}</div></div>`;
}

// ─── Syntax-highlight lines and return HTML ───
function highlightLines(rawLines, lang, startNum) {
  const text = rawLines.join("\n");
  let highlighted;
  try {
    if (window.hljs && lang && lang !== "plaintext") {
      highlighted = window.hljs.highlight(text, { language: lang }).value;
    } else if (window.hljs) {
      highlighted = window.hljs.highlightAuto(text).value;
    } else {
      highlighted = escapeHtml(text);
    }
  } catch {
    highlighted = escapeHtml(text);
  }

  const hlLines = highlighted.split("\n");

  return rawLines.map((raw, i) => {
    const num = startNum + i;
    const content = hlLines[i] !== undefined ? hlLines[i] : escapeHtml(raw);
    const isComment = /^\s*#/.test(raw) && !raw.trim().startsWith("#!");
    return `<div class="cl${isComment ? " cl-cmt" : ""}"><div class="ln">${num}</div><div class="lc">${content || " "}</div></div>`;
  }).join("");
}

// ─── Main render entry ───
function renderCode(text, lang) {
  if (lang === "python") {
    const { headerLines, codeLines, codeStartLine, footerLines } = parsePythonFile(text);

    let html = "";

    // Problem description
    if (headerLines.length > 0) {
      const descHtml = buildDescriptionHtml(headerLines);
      if (descHtml) {
        html += `<div class="code-desc">
          <div class="code-desc-toggle" onclick="this.parentElement.classList.toggle('collapsed')">
            <span>Problem Description</span>
            <svg width="12" height="12" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M6 9l6 6 6-6"/></svg>
          </div>
          <div class="code-desc-body">${descHtml}</div>
        </div>`;
      }
    }

    // Solution code
    if (codeLines.length > 0) {
      html += `<div class="code-block">${highlightLines(codeLines, lang, codeStartLine)}</div>`;
    }

    // Footer notes (complexity, etc.)
    if (footerLines.length > 0) {
      html += buildFooterHtml(footerLines);
    }

    codeBlock.innerHTML = html;
    return;
  }

  // Non-python: standard render
  let highlighted;
  try {
    if (window.hljs && lang && lang !== "plaintext") {
      highlighted = window.hljs.highlight(text, { language: lang }).value;
    } else if (window.hljs) {
      highlighted = window.hljs.highlightAuto(text).value;
    } else {
      highlighted = escapeHtml(text);
    }
  } catch {
    highlighted = escapeHtml(text);
  }

  const rawLines = text.split("\n");
  const hlLines = highlighted.split("\n");

  const html = rawLines.map((raw, i) => {
    const num = i + 1;
    const content = hlLines[i] !== undefined ? hlLines[i] : escapeHtml(raw);
    const isComment = /^\s*(#|\/\/|\/\*|\*\s)/.test(raw);
    return `<div class="cl${isComment ? " cl-cmt" : ""}"><div class="ln">${num}</div><div class="lc">${content || " "}</div></div>`;
  }).join("");

  codeBlock.innerHTML = `<div class="code-block">${html}</div>`;
}

// ─── Load file ───
async function loadFile(path) {
  state.currentPath = path;
  updateUrl(path);
  setActive(path);
  renderBreadcrumb(path);

  // Show file view, hide welcome
  welcomeScreen.classList.add("hidden");
  fileView.classList.remove("hidden");

  // Update header
  const name = path.split("/").pop();
  contentTitle.textContent = name;
  openOnGitHub.href = githubUrl(path);

  // Update reviewed button
  const isRev = isReviewed(path);
  markReviewedBtn.classList.toggle("reviewed", isRev);
  markReviewedBtn.querySelector("span").textContent = isRev ? "Reviewed" : "Mark Reviewed";

  const ext = fileExt(path);
  const lang = langForExt(ext);

  // Hide all content types
  markdownContent.classList.add("hidden");
  imageContent.classList.add("hidden");
  codeView.classList.add("hidden");

  try {
    if (isImage(path)) {
      const url = fileUrl(path);
      imageContent.innerHTML = `<img src="${url}" alt="${escapeHtml(name)}" />`;
      imageContent.classList.remove("hidden");
      contentMeta.textContent = ext.toUpperCase() + " image";
      return;
    }

    const resp = await fetch(fileUrl(path));
    if (!resp.ok) throw new Error(`HTTP ${resp.status}`);
    const text = await resp.text();

    if (isMarkdown(path)) {
      const html = window.marked.parse(text);
      const clean = window.DOMPurify ? window.DOMPurify.sanitize(html) : html;
      markdownContent.innerHTML = clean;
      wireMarkdownLinks(markdownContent, path);
      markdownContent.classList.remove("hidden");
      // Re-highlight code blocks inside markdown
      markdownContent.querySelectorAll("pre code").forEach((block) => {
        if (window.hljs) window.hljs.highlightElement(block);
      });
      const wordCount = text.split(/\s+/).length;
      const readTime = Math.max(1, Math.ceil(wordCount / 200));
      contentMeta.textContent = `${readTime} min read`;
    } else {
      codeLang.textContent = lang || ext || "file";
      codeView.classList.remove("hidden");
      renderCode(text, lang);
      const lineCount = text.split("\n").length;
      contentMeta.textContent = `${lineCount} lines`;
    }
  } catch (err) {
    codeView.classList.remove("hidden");
    codeLang.textContent = "error";
    codeBlock.textContent = `Failed to load: ${path}\n${err.message}`;
    contentMeta.textContent = "";
  }
}

// ─── Welcome screen ───
function renderWelcome() {
  // Topic cards
  topicGrid.innerHTML = "";
  const topDirs = (state.tree.children || []).filter((n) => n.type === "dir" && n.name !== "docs");

  topDirs.forEach((node) => {
    const card = document.createElement("div");
    card.className = "topic-card";

    const total = countFiles(node);
    const reviewed = state.allFiles.filter(
      (f) => f.path.startsWith(node.path + "/") && state.reviewed[f.path]
    ).length;

    card.innerHTML = `
      <div class="topic-card-icon">${TOPIC_ICONS[node.name] || "📁"}</div>
      <div class="topic-card-name">${escapeHtml(node.name)}</div>
      <div class="topic-card-info">${total} problems${reviewed > 0 ? ` · ${reviewed} reviewed` : ""}</div>
      <div class="topic-card-progress"><div class="topic-card-progress-fill" data-folder="${escapeHtml(node.path)}" style="width: ${total > 0 ? (reviewed / total) * 100 : 0}%"></div></div>
    `;

    card.addEventListener("click", () => {
      // Expand this folder in sidebar
      const groups = treeRoot.querySelectorAll(".tree-group");
      groups.forEach((g) => {
        if (g.dataset.name === node.name.toLowerCase()) {
          const children = g.querySelector(".tree-children");
          const caret = g.querySelector(".tree-folder-caret");
          if (children) children.classList.add("expanded");
          if (caret) caret.classList.add("expanded");
          g.scrollIntoView({ block: "nearest", behavior: "smooth" });
        }
      });
    });

    topicGrid.appendChild(card);
  });

  // Stats
  const totalProblems = state.allFiles.length;
  const totalReviewed = state.allFiles.filter((f) => state.reviewed[f.path]).length;
  const totalTopics = topDirs.length;

  statsBar.innerHTML = `
    <div class="stat-item"><div class="stat-value">${totalTopics}</div><div class="stat-label">Topics</div></div>
    <div class="stat-item"><div class="stat-value">${totalProblems}</div><div class="stat-label">Problems</div></div>
    <div class="stat-item"><div class="stat-value">${totalReviewed}</div><div class="stat-label">Reviewed</div></div>
    <div class="stat-item"><div class="stat-value">${totalProblems > 0 ? Math.round((totalReviewed / totalProblems) * 100) : 0}%</div><div class="stat-label">Complete</div></div>
  `;
}

// ─── Search ───
function openSearch() {
  searchModal.classList.add("active");
  searchModalInput.value = "";
  searchModalInput.focus();
  renderSearchResults("");
}

function closeSearch() {
  searchModal.classList.remove("active");
  searchModalInput.value = "";
}

function renderSearchResults(query) {
  searchResults.innerHTML = "";
  const q = query.trim().toLowerCase();

  if (!q) {
    // Show recent / popular topics
    const topDirs = (state.tree.children || []).filter((n) => n.type === "dir" && n.name !== "docs");
    const html = topDirs
      .slice(0, 8)
      .map(
        (n) => `
      <div class="search-result-item" data-type="folder" data-name="${escapeHtml(n.name)}">
        <div class="search-result-icon">${TOPIC_ICONS[n.name] || "📁"}</div>
        <div class="search-result-info">
          <div class="search-result-name">${escapeHtml(n.name)}</div>
          <div class="search-result-path">${countFiles(n)} problems</div>
        </div>
        <div class="search-result-badge">Topic</div>
      </div>
    `
      )
      .join("");
    searchResults.innerHTML = html || '<div class="search-empty">No topics found</div>';
    attachSearchResultListeners();
    return;
  }

  // Search files and folders
  const results = [];

  state.allFolders.forEach((f) => {
    if (f.name.toLowerCase().includes(q)) {
      results.push({ type: "folder", node: f, score: f.name.toLowerCase().startsWith(q) ? 2 : 1 });
    }
  });

  state.allFiles.forEach((f) => {
    if (f.name.toLowerCase().includes(q) || f.path.toLowerCase().includes(q)) {
      results.push({ type: "file", node: f, score: f.name.toLowerCase().startsWith(q) ? 2 : 1 });
    }
  });

  results.sort((a, b) => b.score - a.score);

  if (results.length === 0) {
    searchResults.innerHTML = '<div class="search-empty">No results found</div>';
    return;
  }

  const html = results
    .slice(0, 20)
    .map((r) => {
      if (r.type === "folder") {
        return `
        <div class="search-result-item" data-type="folder" data-name="${escapeHtml(r.node.name)}">
          <div class="search-result-icon">${TOPIC_ICONS[r.node.name] || "📁"}</div>
          <div class="search-result-info">
            <div class="search-result-name">${escapeHtml(r.node.name)}</div>
            <div class="search-result-path">${countFiles(r.node)} problems</div>
          </div>
          <div class="search-result-badge">Topic</div>
        </div>`;
      }
      return `
      <div class="search-result-item" data-type="file" data-path="${escapeHtml(r.node.path)}">
        <div class="search-result-icon">${fileIcon(r.node.ext)}</div>
        <div class="search-result-info">
          <div class="search-result-name">${escapeHtml(r.node.name)}</div>
          <div class="search-result-path">${escapeHtml(r.node.path)}</div>
        </div>
        <div class="search-result-badge">${(r.node.ext || "file").toUpperCase()}</div>
      </div>`;
    })
    .join("");

  searchResults.innerHTML = html;
  attachSearchResultListeners();
}

function attachSearchResultListeners() {
  searchResults.querySelectorAll(".search-result-item").forEach((el) => {
    el.addEventListener("click", () => {
      const type = el.dataset.type;
      if (type === "file") {
        loadFile(el.dataset.path);
      } else if (type === "folder") {
        const name = el.dataset.name;
        // Expand folder in sidebar
        const groups = treeRoot.querySelectorAll(".tree-group");
        groups.forEach((g) => {
          if (g.dataset.name === name.toLowerCase()) {
            const children = g.querySelector(".tree-children");
            const caret = g.querySelector(".tree-folder-caret");
            if (children) children.classList.add("expanded");
            if (caret) caret.classList.add("expanded");
            g.scrollIntoView({ block: "nearest", behavior: "smooth" });
          }
        });
      }
      closeSearch();
    });
  });
}

// ─── Keyboard shortcuts ───
let shortcutsTimeout;
function showShortcuts() {
  shortcutsToast.classList.remove("hidden");
  clearTimeout(shortcutsTimeout);
  shortcutsTimeout = setTimeout(() => shortcutsToast.classList.add("hidden"), 3000);
}

document.addEventListener("keydown", (e) => {
  // Ctrl+K or Cmd+K — search
  if ((e.ctrlKey || e.metaKey) && e.key === "k") {
    e.preventDefault();
    if (searchModal.classList.contains("active")) {
      closeSearch();
    } else {
      openSearch();
    }
    return;
  }

  // ESC — close search
  if (e.key === "Escape") {
    if (searchModal.classList.contains("active")) {
      closeSearch();
    }
    if (!shortcutsToast.classList.contains("hidden")) {
      shortcutsToast.classList.add("hidden");
    }
    return;
  }

  // Ctrl+B — toggle sidebar
  if ((e.ctrlKey || e.metaKey) && e.key === "b") {
    e.preventDefault();
    toggleSidebar();
    return;
  }

  // Ctrl+D — toggle dark mode
  if ((e.ctrlKey || e.metaKey) && e.key === "d") {
    e.preventDefault();
    toggleTheme();
    return;
  }

  // ? — show shortcuts (only when not typing)
  if (e.key === "?" && !e.target.closest("input, textarea")) {
    showShortcuts();
  }
});

function toggleSidebar() {
  state.sidebarOpen = !state.sidebarOpen;
  sidebar.classList.toggle("collapsed", !state.sidebarOpen);
  layout.classList.toggle("sidebar-collapsed", !state.sidebarOpen);
}

// ─── Collapse all folders ───
function collapseAllFolders() {
  treeRoot.querySelectorAll(".tree-children").forEach((el) => el.classList.remove("expanded"));
  treeRoot
    .querySelectorAll(".tree-folder-caret")
    .forEach((el) => el.classList.remove("expanded"));
}

// ─── Copy code ───
function copyCode() {
  const text = codeBlock.textContent;
  navigator.clipboard.writeText(text).then(() => {
    codeCopyBtn.querySelector("svg").style.display = "none";
    const origText = codeCopyBtn.textContent;
    codeCopyBtn.textContent = "Copied!";
    setTimeout(() => {
      codeCopyBtn.innerHTML = `<svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><rect x="9" y="9" width="13" height="13" rx="2" ry="2"/><path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"/></svg> Copy`;
    }, 1500);
  });
}

// ─── Mobile sidebar ───
function createOverlay() {
  const overlay = document.createElement("div");
  overlay.className = "sidebar-overlay";
  document.body.appendChild(overlay);
  overlay.addEventListener("click", () => {
    sidebar.classList.remove("mobile-open");
    overlay.classList.remove("active");
  });
  return overlay;
}

// ─── Browser history ───
window.addEventListener("popstate", () => {
  const path = pathFromUrl();
  if (path) loadFile(path);
});

// ─── Config ───
async function loadConfig() {
  try {
    const resp = await fetch("config.json");
    if (!resp.ok) return {};
    return await resp.json();
  } catch {
    return {};
  }
}

function detectRepo() {
  const parts = window.location.hostname.split(".");
  if (parts.length >= 3 && parts[1] === "github" && parts[2] === "io") {
    const owner = parts[0];
    const repo = window.location.pathname.split("/").filter(Boolean)[0];
    if (owner && repo) return { owner, repo };
  }
  return null;
}

// ─── Init ───
async function init() {
  loadTheme();
  loadReviewed();

  const config = await loadConfig();
  const detected = detectRepo();

  state.repoOwner = config.repoOwner || detected?.owner || "Prakash-sa";
  state.repoName = config.repoName || detected?.repo || "Competitive-Programming";
  state.branch = config.branch || "master";

  const host = window.location.hostname;
  const isLocal = host === "localhost" || host === "127.0.0.1" || host === "" || host === "0.0.0.0";
  if (config.useLocalContent === true) {
    state.useLocalContent = true;
  } else if (config.useLocalContent === "auto") {
    state.useLocalContent = isLocal;
  } else {
    state.useLocalContent = false;
  }

  repoLink.href = `https://github.com/${state.repoOwner}/${state.repoName}`;

  // Load tree
  try {
    const resp = await fetch("tree.json");
    if (!resp.ok) throw new Error("tree.json not found");
    state.tree = await resp.json();
  } catch {
    codeBlock.textContent = "Failed to load tree.json. Run the tree generator.";
    return;
  }

  // Flatten for search
  const flat = flattenTree(state.tree);
  state.allFiles = flat.files;
  state.allFolders = flat.folders;

  // Render
  renderTree(state.tree);
  updateProgressUI();

  // Event listeners
  themeToggle.addEventListener("click", toggleTheme);
  searchTrigger.addEventListener("click", openSearch);
  searchModalInput.addEventListener("input", (e) => renderSearchResults(e.target.value));
  searchModal.addEventListener("click", (e) => {
    if (e.target === searchModal) closeSearch();
  });
  collapseAll.addEventListener("click", collapseAllFolders);
  codeCopyBtn.addEventListener("click", copyCode);
  markReviewedBtn.addEventListener("click", () => {
    if (state.currentPath) {
      toggleReviewed(state.currentPath);
    }
  });

  // Mobile
  const overlay = createOverlay();
  mobileMenuBtn.addEventListener("click", () => {
    const isOpen = sidebar.classList.toggle("mobile-open");
    overlay.classList.toggle("active", isOpen);
  });

  // Check URL for initial path
  const initialPath = pathFromUrl();
  if (initialPath) {
    loadFile(initialPath);
  } else {
    renderWelcome();
  }
}

init();
