#!/bin/bash
echo "Iter" > ./logs/log.0
for i in {0..15} 
   do
      echo $i >> ./logs/log.0
   done
./schedule-clause 1 > ./logs/log.10
./schedule-clause 2 > ./logs/log.20
./schedule-clause 4 > ./logs/log.40
./scheduled-clause 1 > ./logs/log.11
./scheduled-clause 2 > ./logs/log.21
./scheduled-clause 4 > ./logs/log.41
./scheduleg-clause 1 > ./logs/log.12
./scheduleg-clause 2 > ./logs/log.22
./scheduleg-clause 4 > ./logs/log.42

paste ./logs/log.0 ./logs/log.10 ./logs/log.20 ./logs/log.40 ./logs/log.11 ./logs/log.21 ./logs/log.41 ./logs/log.12 ./logs/log.22 ./logs/log.42  > ./logs/log_final

cat ./logs/log_final
