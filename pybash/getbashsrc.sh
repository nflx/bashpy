mkdir git
git -C git clone https://github.com/bminor/bash.git
echo "run `bash --version` and `git tags` and checkout the closes to right tag or branch with `git checkout <tag>`"
echo "by default we will checkout bash-5.0"
pushd git/bash
git checkout "bash-5.0"
./configure
make pathnames.h
