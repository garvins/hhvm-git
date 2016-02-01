CORES=$(getconf _NPROCESSORS_ONLN)

mkdir libgit2/build
cd libgit2/build
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DBUILD_CLAR=OFF ..
cmake --build .

cd ../../
hphpize
cmake .
make -j $CORES