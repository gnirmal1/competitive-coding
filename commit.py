from git import Repo
import os
import json

def update_json(file):
    if file.startswith("USACO") or file.startswith("UVa"):
        return
    print(file)
    path_split = file.split('/')
    file_split = path_split[-1].split('.')

    info_path = os.path.join(path_split[0], "info.json")
    if os.path.exists(info_path):
        with open(info_path, "r") as f:
            info = json.load(f)
    else:
        info = {}
    if "url" not in info:
        info["url"] = []
    
    url = ""
    if file.startswith("Kattis"):
        url = "https://open.kattis.com/problems/" + file_split[0]
    elif file.startswith("Codeforces"):
        url = "https://codeforces.com/contest/" + path_split[-2]
    elif file.startswith("CSES"):
        url = "https://cses.fi/problemset/task/" + file_split[0]
    
    if url not in info["url"]:
        info["url"].append(url)

    with open(info_path, "w") as f:
        json.dump(info, f, indent=4, sort_keys=True)
    

def stage_files(repo):
    for file in repo.untracked_files:
        if file.endswith(".cpp"):
            update_json(file)
        repo.index.add(file)

def stage_info_json(repo):
    for dir in os.listdir(repo.working_dir):
        if os.path.isdir(dir) and not dir.startswith("."):
            info_path = os.path.join(dir, "info.json")
            if os.path.exists(info_path):
                repo.index.add([info_path])

def stage_commit_push(repo):
    stage_files(repo)
    stage_info_json(repo)
    repo.index.commit("Committing changes")
    origin = repo.remote(name="origin")
    origin.push()

if __name__ == "__main__":
    repo = Repo(".")
    stage_commit_push(repo)

