find  ~/clones/Corewar/champions/tests/src -name "*.s"|while read filename; do
    ./asm "$filename" > /dev/null
    text="echo $filename | sed 's/\.s/\.cor/'"
    text=`eval $text`
    text=`basename $text`
    hexdump -C $text > l1
    unit_test/origin_asm "$filename" > /dev/null
    hexdump -C $text > l2
    diff -s l1 l2 > /dev/null
    if [ "$?" -ne 0 ];
    then
	echo -n "$text: "
	echo "KO"
    else
	echo -n "$text: "
	echo "OK"
    fi
    rm $text
done
rm l1 l2
