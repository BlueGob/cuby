for i in source-code/*.c; do gcc $i -o algorithms/`basename $i .c`; done
