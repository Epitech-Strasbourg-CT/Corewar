if [ ! -r $1.s ];
then
    echo "EQUILIBRE";
    exit
fi


./unit_test/origin_asm $1.s
if [ $? -ne 0 ];
then
    echo "FATAL ERROR: KERNEL PANIC";
    exit
fi

hexdump -C $1.cor > origin.log

./asm $1.s > /dev/null
if [ $? -ne 0 ];
then
    echo "FATAL ERROR: KERNEL PANIC";
    exit
fi

hexdump -C $1.cor > my.log

diff -sy my.log origin.log --color

rm my.log origin.log
