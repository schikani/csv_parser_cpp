mkdir ./build
cd ./build
cmake ..
make
cd ..
cp ./build/main/app .
# ./csv_to_c