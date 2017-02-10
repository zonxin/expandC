#/bin/bash 

cd ../../../ 
echo ==============selectionSort===========================
make MAIN=testdata/data_structure/Sort/selectionSort.c
echo ==============insectionSort===========================
make MAIN=testdata/data_structure/Sort/insectionSort.c
echo ==============shellSort===============================
make MAIN=testdata/data_structure/Sort/shellSort.c
echo ==============mergeSort===============================
make MAIN=testdata/data_structure/Sort/mergeSort.c
echo ==============quickSort===============================
make MAIN=testdata/data_structure/Sort/quickSort.c
echo ==============quick3waySort===============================
make MAIN=testdata/data_structure/Sort/quick3waySort.c
echo ==============heapSort===============================
make MAIN=testdata/data_structure/Sort/heapSort.c
