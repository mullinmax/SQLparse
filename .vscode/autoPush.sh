#!/bin/bash
: $(git add .) 
: $(git commit -q -m'auto push for test')
: $(git push -q)