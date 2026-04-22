#!/bin/bash
# Auto-commit and push changes to GitHub after file edits

REPO_DIR="/home/nbakic/Projects/arduino-project"
cd "$REPO_DIR" || exit 1

# Nothing to do if working tree is clean
if git diff --quiet && git diff --staged --quiet && [ -z "$(git ls-files --others --exclude-standard)" ]; then
    exit 0
fi

git add -A

# Build commit message from changed files
CHANGED=$(git diff --cached --name-only | head -5 | paste -sd ", ")
TIMESTAMP=$(date '+%Y-%m-%d %H:%M')
git commit -m "Update ${CHANGED:-project files} (${TIMESTAMP})"

git push origin main 2>&1
