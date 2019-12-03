#
#    Copyright (C) 2019  Emil Lind <emil@sys.nu>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
mkdir git || true
git -C git clone https://github.com/bminor/bash.git
echo "run `bash --version` and `git tags` and checkout the closes to right tag or branch with `git checkout <tag>`"
echo "by default we will checkout bash-5.0"
pushd git/bash
git checkout "bash-5.0"
./configure
make pathnames.h
