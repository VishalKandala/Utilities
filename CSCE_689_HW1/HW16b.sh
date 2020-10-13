rm output*>/dev/null 2>&1
rm data*>/dev/null 2>&1
bsub<compute_pi_mpi.job
f=0
while (($f!=1))
do
 a=$(find output*)>/dev/null 2>&1
 b=$?
 if test $b -eq "0"; then
  f=1
  echo 'Output Generated'
 else
  echo 'Waiting for Output from job'
  sleep 5s
 fi
done
