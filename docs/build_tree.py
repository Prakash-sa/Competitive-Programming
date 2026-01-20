import json
import os

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUTPUT = os.path.join(ROOT, "docs", "tree.json")
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
    tree = build_tree(ROOT)
    with open(OUTPUT, "w", encoding="utf-8") as handle:
        json.dump(tree, handle, indent=2)
    print(f"Wrote {OUTPUT}")


if __name__ == "__main__":
    main()
