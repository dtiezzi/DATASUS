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
