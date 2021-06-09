# DATASUS

### Download DATASUS databases

This is a shell script to download datasets from DATASUS FTP server.

To download data, you have to pass the year as an argument:


```bash
./datasus.sh 15 # downloads all datasets from 2015
```

Note the script is designed to download the SIA-PA data. You can change the `$DATABASE` and the `URL` variables. Note you have to create a directory named `dbfiles` or change the `$OUTDIR` variable.

```bash
mkdir dbfiles
```

## Using OpenMP

You can use OpenMP with `datasus.c` for multi-thread download. The default year is `2010`. If you want to modify, change de global variable `year`. To compile, you can use the gcc compiler and setup the number of threads:

```bash
gcc -o datasus.out -fopenmp datasus.c
export OMP_NUM_THREADS=16 # for 16 threads
nohup ./datasus.c &> nohup_Cdatasus.out & # running in the backgroung
```
