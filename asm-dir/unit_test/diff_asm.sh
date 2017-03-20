if [ ! -r $1.s ];
then
    echo "EQUILIBRE";
    exit
fi

cp ../asm .

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

diff -s my.log origin.log
