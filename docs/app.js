const state = {
  tree: null,
  repoOwner: null,
  repoName: null,
  branch: "main",
  currentPath: "README.md",
  activeItem: null,
  useLocalContent: false,
};

// Configure marked for better markdown rendering
if (window.marked) {
  window.marked.setOptions({
    breaks: true,
    gfm: true,
  });
}

const treeRoot = document.getElementById("treeRoot");
const codeBlock = document.getElementById("codeBlock");
const codeContainer = document.getElementById("codeContainer");
const markdownContent = document.getElementById("markdownContent");
const imageContent = document.getElementById("imageContent");
const contentTitle = document.getElementById("contentTitle");
const contentFooter = document.getElementById("contentFooter");
const copyLink = document.getElementById("copyLink");
const openOnGitHub = document.getElementById("openOnGitHub");
const repoLink = document.getElementById("repoLink");
const searchInput = document.getElementById("searchInput");
const collapseAll = document.getElementById("collapseAll");
const sidebarToggle = document.getElementById("sidebarToggle");
const sidebar = document.getElementById("sidebar");

function detectRepoFromLocation() {
  const hostParts = window.location.hostname.split(".");
  if (hostParts.length >= 3 && hostParts[1] === "github" && hostParts[2] === "io") {
    const owner = hostParts[0];
    const repo = window.location.pathname.split("/").filter(Boolean)[0];
    if (owner && repo) {
      return { owner, repo };
    }
  }
  return null;
}

function pathFromLocation() {
  const params = new URLSearchParams(window.location.search);
  const queryPath = params.get("path");
  if (queryPath) {
    return decodeURIComponent(queryPath);
  }
  if (window.location.hash.length > 1) {
    return decodeURIComponent(window.location.hash.slice(1));
  }
  return null;
}

function updateLocationWithPath(path) {
  const params = new URLSearchParams(window.location.search);
  params.set("path", encodeURIComponent(path));
  const newUrl = `${window.location.pathname}?${params.toString()}`;
  window.history.replaceState({}, "", newUrl);
}

function encodePath(path) {
  return path
    .split("/")
    .map((segment) => encodeURIComponent(segment))
    .join("/");
}

function fileUrlForPath(path) {
  const encoded = encodePath(path);
  if (state.useLocalContent) {
    // For local content, use encoded path since GitHub Pages needs URL encoding
    return `content/${encoded}`;
  }
  // For GitHub raw content, use encoded path
  return `https://raw.githubusercontent.com/${state.repoOwner}/${state.repoName}/${state.branch}/${encoded}`;
}

function githubUrlForPath(path) {
  const encoded = encodePath(path);
  return `https://github.com/${state.repoOwner}/${state.repoName}/blob/${state.branch}/${encoded}`;
}

function fileExtension(path) {
  const parts = path.split(".");
  if (parts.length < 2) return "";
  return parts.pop().toLowerCase();
}

function languageForPath(path) {
  const ext = fileExtension(path);
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
  };
  return map[ext] || "";
}

function isImageFile(path) {
  const ext = fileExtension(path);
  return ["png", "jpg", "jpeg", "gif", "svg", "webp"].includes(ext);
}

function escapeHtml(text) {
  return text.replace(/[&<>]/g, (char) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;" }[char]));
}

function renderCode(text, languageClass) {
  let highlighted;
  try {
    if (window.hljs && languageClass) {
      highlighted = window.hljs.highlight(text, { language: languageClass }).value;
    } else if (window.hljs) {
      highlighted = window.hljs.highlightAuto(text).value;
    } else {
      highlighted = escapeHtml(text);
    }
  } catch (error) {
    highlighted = escapeHtml(text);
  }

  const lines = highlighted.split("\n");
  const wrapped = lines
    .map((line, index) => {
      const lineNumber = index + 1;
      const content = line.length ? line : "&nbsp;";
      return `<span class="code-line"><span class="line-number">${lineNumber}</span><span class="line-content">${content}</span></span>`;
    })
    .join("\n");

  codeBlock.innerHTML = `<span class="code-lines">${wrapped}</span>`;
}

function setActiveItem(element) {
  if (state.activeItem) {
    state.activeItem.classList.remove("active");
  }
  state.activeItem = element;
  if (state.activeItem) {
    state.activeItem.classList.add("active");
  }
}

function updateContentHeader(path) {
  contentTitle.textContent = path;
  openOnGitHub.href = githubUrlForPath(path);
}

function updateFooter(meta) {
  const segments = [
    meta?.type ? `Type: ${meta.type}` : null,
    meta?.size ? `Size: ${meta.size} bytes` : null,
    meta?.updated ? `Updated: ${meta.updated}` : null,
  ].filter(Boolean);

  contentFooter.textContent = segments.join(" | ");
}

async function loadFile(path, meta = {}) {
  state.currentPath = path;
  updateContentHeader(path);
  updateFooter(meta);
  updateLocationWithPath(path);

  const languageClass = languageForPath(path);
  codeBlock.className = languageClass ? `language-${languageClass}` : "";

  try {
    const response = await fetch(fileUrlForPath(path));
    if (!response.ok) {
      throw new Error(`Failed to fetch ${path}`);
    }
    if (isImageFile(path)) {
      const blob = await response.blob();
      const imageUrl = URL.createObjectURL(blob);
      imageContent.innerHTML = `<img src="${imageUrl}" alt="${path}" />`;
      imageContent.classList.remove("hidden");
      markdownContent.classList.add("hidden");
      codeContainer.classList.add("hidden");
      return;
    }

    const text = await response.text();
    if (languageClass === "markdown" && window.marked) {
      const html = window.marked.parse(text);
      const sanitized = window.DOMPurify ? window.DOMPurify.sanitize(html) : html;
      markdownContent.innerHTML = sanitized;
      markdownContent.classList.remove("hidden");
      imageContent.classList.add("hidden");
      codeContainer.classList.add("hidden");
    } else if (languageClass === "python") {
      // For Python files, display as plain text without rendering
      markdownContent.classList.add("hidden");
      imageContent.classList.add("hidden");
      codeContainer.classList.remove("hidden");
      codeBlock.textContent = text;
    } else if (languageClass === "json") {
      let formatted = text;
      try {
        formatted = JSON.stringify(JSON.parse(text), null, 2);
      } catch (error) {
        formatted = text;
      }
      markdownContent.classList.add("hidden");
      imageContent.classList.add("hidden");
      codeContainer.classList.remove("hidden");
      renderCode(formatted, languageClass);
    } else {
      markdownContent.classList.add("hidden");
      imageContent.classList.add("hidden");
      codeContainer.classList.remove("hidden");
      renderCode(text, languageClass);
    }
  } catch (error) {
    markdownContent.classList.add("hidden");
    imageContent.classList.add("hidden");
    codeContainer.classList.remove("hidden");
    codeBlock.textContent = `Unable to load ${path}. ${error.message}`;
  }
}

function createTreeNode(node, depth = 0) {
  if (node.type === "dir") {
    const wrapper = document.createElement("div");
    wrapper.className = "tree-group";

    const header = document.createElement("div");
    header.className = "tree-item";

    const caret = document.createElement("span");
    caret.className = "caret";

    const label = document.createElement("span");
    label.className = "tree-label";
    label.textContent = node.name;

    const meta = document.createElement("span");
    meta.className = "tree-meta";
    meta.textContent = `${node.children.length} items`;

    header.appendChild(caret);
    header.appendChild(label);
    header.appendChild(meta);

    const children = document.createElement("div");
    children.className = "tree-children";

    node.children.forEach((child) => {
      children.appendChild(createTreeNode(child, depth + 1));
    });

    header.addEventListener("click", () => {
      const isExpanded = children.classList.toggle("expanded");
      caret.classList.toggle("expanded", isExpanded);
    });

    wrapper.appendChild(header);
    wrapper.appendChild(children);

    return wrapper;
  }

  const wrapper = document.createElement("div");
  wrapper.className = "tree-leaf";

  const item = document.createElement("div");
  item.className = "tree-item";

  const spacer = document.createElement("span");
  spacer.style.width = "10px";

  const label = document.createElement("span");
  label.className = "tree-label";
  label.textContent = node.name;

  const meta = document.createElement("span");
  meta.className = "tree-meta";
  meta.textContent = node.ext ? node.ext.toUpperCase() : "file";

  item.appendChild(spacer);
  item.appendChild(label);
  item.appendChild(meta);

  item.addEventListener("click", () => {
    setActiveItem(item);
    loadFile(node.path, { type: "file", size: node.size });
  });

  wrapper.appendChild(item);
  return wrapper;
}

function renderTree(tree) {
  treeRoot.innerHTML = "";
  tree.children.forEach((child) => treeRoot.appendChild(createTreeNode(child)));
}

function collapseEverything() {
  document.querySelectorAll(".tree-children").forEach((el) => {
    el.classList.remove("expanded");
  });
  document.querySelectorAll(".caret").forEach((el) => {
    el.classList.remove("expanded");
  });
}

function filterTree(query) {
  const text = query.trim().toLowerCase();
  const groups = Array.from(treeRoot.children);

  if (!text) {
    treeRoot.querySelectorAll(".tree-group, .tree-leaf").forEach((el) => {
      el.classList.remove("hidden");
    });
    collapseEverything();
    return;
  }

  const filterGroup = (group) => {
    const header = group.querySelector(":scope > .tree-item");
    const label = header?.querySelector(".tree-label");
    const children = group.querySelector(":scope > .tree-children");
    const isMatch = label && label.textContent.toLowerCase().includes(text);

    let childMatch = false;
    if (children) {
      const childNodes = Array.from(children.children);
      childNodes.forEach((child) => {
        if (child.classList.contains("tree-group")) {
          childMatch = filterGroup(child) || childMatch;
        } else {
          const leafLabel = child.querySelector(".tree-label");
          const leafMatch = leafLabel && leafLabel.textContent.toLowerCase().includes(text);
          child.classList.toggle("hidden", !leafMatch);
          childMatch = childMatch || leafMatch;
        }
      });
    }

    const visible = isMatch || childMatch;
    group.classList.toggle("hidden", !visible);
    if (children) {
      children.classList.toggle("expanded", childMatch);
      const caret = header?.querySelector(".caret");
      if (caret) {
        caret.classList.toggle("expanded", childMatch);
      }
    }
    return visible;
  };

  groups.forEach((group) => {
    if (group.classList.contains("tree-group")) {
      filterGroup(group);
    }
  });
}

async function loadConfig() {
  try {
    const response = await fetch("config.json");
    if (!response.ok) return {};
    return await response.json();
  } catch (error) {
    return {};
  }
}

async function init() {
  const config = await loadConfig();
  const detected = detectRepoFromLocation();
  const initialPath = pathFromLocation();

  state.repoOwner = config.repoOwner || detected?.owner || "your-github-username";
  state.repoName = config.repoName || detected?.repo || "your-repo-name";
  state.branch = config.branch || "main";
  state.useLocalContent = Boolean(config.useLocalContent);

  repoLink.href = `https://github.com/${state.repoOwner}/${state.repoName}`;

  const treeResponse = await fetch("tree.json");
  if (!treeResponse.ok) {
    codeBlock.textContent = "tree.json not found. Run the tree generator.";
    return;
  }

  state.tree = await treeResponse.json();
  renderTree(state.tree);

  searchInput.addEventListener("input", (event) => {
    filterTree(event.target.value);
  });

  collapseAll.addEventListener("click", () => {
    collapseEverything();
  });

  sidebarToggle.addEventListener("click", () => {
    sidebar.classList.toggle("hidden");
  });

  copyLink.addEventListener("click", async () => {
    try {
      await navigator.clipboard.writeText(fileUrlForPath(state.currentPath));
      copyLink.textContent = "Copied";
      setTimeout(() => {
        copyLink.textContent = "Copy raw link";
      }, 1500);
    } catch (error) {
      copyLink.textContent = "Copy failed";
      setTimeout(() => {
        copyLink.textContent = "Copy raw link";
      }, 1500);
    }
  });

  if (initialPath) {
    state.currentPath = initialPath;
  }
  loadFile(state.currentPath, { type: "file" });
}

init();
