#! /usr/bin/zsh
rm -rf build;
mkdir build;
cd build;
cmake -DBUILD_SHARED_LIBS=ON -DGLFW_BUILD_DOCS=OFF -GNinja ..  
