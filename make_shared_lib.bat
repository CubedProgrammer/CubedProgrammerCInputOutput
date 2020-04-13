gcc -c -O3 -Ilib -o lib\cpcio_impl_fs.o lib\cpcio_impl\fstream_impl.c
gcc -c -O3 -Ilib -o lib\cpcio_impl_is.o lib\cpcio_impl\istream_impl.c
gcc -c -O3 -Ilib -o lib\cpcio_impl_os.o lib\cpcio_impl\ostream_impl.c
gcc -c -O3 -Ilib -o lib\cpcio_impl_ss.o lib\cpcio_impl\sstream_impl.c
gcc -shared -o lib\cpcio.dll lib\cpcio_impl_fs.o lib\cpcio_impl_is.o lib\cpcio_impl_os.o lib\cpcio_impl_ss.o