"""
 *    author:  Nirmal Govindaraj
 *    created: 29.01.2024 11:21:57
 *    Script that commits, pushes and auto updates the README's table of contents
 *    Requires GitPython to be installed
 *    Each folder has an info.json file that contains list of all url's
"""
from git import Repo
import os
import json

def update_json(file): # updates the info.json file with the url
    if file.startswith("USACO") or file.startswith("UVa"):
        return
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
    

def stage_files(repo): # stages the changed .cpp files
    for file in repo.untracked_files:
        print(file)
        if file.endswith(".cpp"):
            update_json(file)
        repo.index.add(file)

def stage_info_json(repo): # stages the info.json files
    for dir in os.listdir(repo.working_dir):
        if os.path.isdir(dir) and not dir.startswith("."):
            info_path = os.path.join(dir, "info.json")
            if os.path.exists(info_path):
                repo.index.add([info_path])

def stage_commit_push(repo, message="Committing changes"):
    stage_files(repo)
    stage_info_json(repo)
    repo.index.commit(message)
    origin = repo.remote(name="origin")
    origin.push()

if __name__ == "__main__":
    repo = Repo(".")
    message = "Problems added"
    stage_commit_push(repo, message)

