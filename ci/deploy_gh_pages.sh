#!/bin/bash

# After success travis code
git config --global user.email 'octocat@github.com'
git config --global user.name 'Github Action'
make badges
cd web
git init
echo "GH_TOKEN: ${GH_TOKEN}"
echo "GITHUB_ACTOR: ${GITHUB_ACTOR}"
echo "GITHUB_REPOSITORY: ${GITHUB_REPOSITORY}"
git remote add origin "https://${GITHUB_ACTOR}:${ GH_TOKEN }@github.com/${GITHUB_REPOSITORY}.git" > /dev/null 2>&1
git checkout -b gh-pages
git add .
git commit --message "GitHub Action ${GITHUB_RUN_NUMBER}"
git push --force --quiet origin gh-pages || echo "didn't push, not on deployment branch"
