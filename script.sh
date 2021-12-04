for i in *.c; do gcc $i -o algorithms/`basename $i .c`; done
