#/bin/bash 

cd ../../../ 
echo ==============insectionSort===========================
make MAIN=testdata/data_structure/Sort/insectionSort.c
echo ==============mergeSort===============================
make MAIN=testdata/data_structure/Sort/mergeSort.c
echo ==============quickSort===============================
make MAIN=testdata/data_structure/Sort/quickSort.c
echo ==============selectionSort===========================
make MAIN=testdata/data_structure/Sort/selectionSort.c
echo ==============shellSort===============================
make MAIN=testdata/data_structure/Sort/shellSort.c
