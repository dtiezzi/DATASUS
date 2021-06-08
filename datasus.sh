#!/bin/bash

OUTDIR="./dbfiles/"
STATES="AC AL AP AM BA CE DF ES GO MA MT MS MG PA PB PR PE PI RJ RN RS RO RR SC SP SE TO"
URL="ftp://ftp.datasus.gov.br/dissemin/publicos/SIASUS/200801_/Dados/"
DATABASE="PA"
MO="01 02 03 04 05 06 07 08 09 10 11 12"
YEAR=$1

for val in $STATES; do
    for y in $YEAR; do
        for m in $MO; do
            wget ${URL}${DATABASE}${val}${y}${m}.dbc
            file=${DATABASE}${val}${y}${m}.dbc
            mv $file $OUTDIR
        done
    done
done
