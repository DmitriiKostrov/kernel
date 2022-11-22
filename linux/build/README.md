https://ravesli.com/build-linux-kernel-from-scratch/
https://losst.pro/sobiraem-yadro-linux
https://habr.com/ru/company/veeam/blog/520296/


Ubuntu certs: https://askubuntu.com/questions/1329538/compiling-the-kernel-5-11-11
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS

make menuconfig
make -j 10 && make -j 10 modules
make modules_install
ls /lib/modules
make install
ls /boot