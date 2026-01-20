import json
import os
import shutil

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUTPUT = os.path.join(ROOT, "docs", "tree.json")
CONTENT_ROOT = os.path.join(ROOT, "docs", "content")
EXCLUDE_DIRS = {".git", "docs", "__pycache__"}


def build_tree(current_path):
    name = os.path.basename(current_path) if current_path != ROOT else "root"
    node = {"name": name, "type": "dir", "path": ""}
    children = []

    try:
        entries = sorted(os.listdir(current_path))
    except OSError:
        entries = []

    for entry in entries:
        if entry.startswith("."):
            continue
        full_path = os.path.join(current_path, entry)
        rel_path = os.path.relpath(full_path, ROOT).replace(os.sep, "/")

        if os.path.isdir(full_path):
            if entry in EXCLUDE_DIRS:
                continue
            child = build_tree(full_path)
            child["path"] = rel_path
            children.append(child)
        else:
            size = os.path.getsize(full_path)
            ext = os.path.splitext(entry)[1].lstrip(".")
            children.append(
                {
                    "name": entry,
                    "type": "file",
                    "path": rel_path,
                    "size": size,
                    "ext": ext,
                }
            )

    node["children"] = children
    return node


def main():
    if os.path.exists(CONTENT_ROOT):
        shutil.rmtree(CONTENT_ROOT)
    os.makedirs(CONTENT_ROOT, exist_ok=True)

    tree = build_tree(ROOT)
    with open(OUTPUT, "w", encoding="utf-8") as handle:
        json.dump(tree, handle, indent=2)

    for current_root, dirs, files in os.walk(ROOT):
        dirs[:] = [d for d in dirs if d not in EXCLUDE_DIRS and not d.startswith(".")]
        rel_root = os.path.relpath(current_root, ROOT)
        target_root = os.path.join(CONTENT_ROOT, rel_root)
        os.makedirs(target_root, exist_ok=True)

        for filename in files:
            if filename.startswith("."):
                continue
            src_path = os.path.join(current_root, filename)
            rel_path = os.path.relpath(src_path, ROOT)
            if rel_path.startswith("docs/"):
                continue
            dest_path = os.path.join(CONTENT_ROOT, rel_path)
            os.makedirs(os.path.dirname(dest_path), exist_ok=True)
            shutil.copy2(src_path, dest_path)

    print(f"Wrote {OUTPUT}")
    print(f"Mirrored content into {CONTENT_ROOT}")


if __name__ == "__main__":
    main()
