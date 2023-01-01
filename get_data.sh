seeds=( 3 14 15 92 65 ) #sementes a testar
methods=( "quicksort" "mergesort" "heapsort" ) #métodos
versions=( 1 2 3 4 5 ) #versões do quicksort
ks=( 3 5 7 ) #ks para o método 2 do quicksort
ms=( 10 100 ) #ms para o método 3 do quicksort

for i in "${seeds[@]}"
do
  echo "seed" $i
  for p in "${methods[@]}"
  do
    if [ "${p}" == "quicksort" ]; then
      echo "quicksort"
      for j in "${versions[@]}"
      do
      echo "version" $j
      if [ $j -eq 2 ]; then
        for k in "${ks[@]}"
        do
          echo "k" $k
          ./bin/main quicksort -v $j -k $k -s $i -i ./trials/input.txt -o ./trials/out"$i".txt
        done
      elif [ $j -eq 3 ]; then
        for m in "${ms[@]}"
        do
          echo "m" $m
          ./bin/main quicksort -v $j -m $m -s $i -i ./trials/input.txt -o ./trials/out"$i".txt
        done
      else
        ./bin/main quicksort -v $j -s $i -i ./trials/input.txt -o ./trials/out"$i".txt
      fi
    done
    else
      echo "${p}"
      ./bin/main "${p}" -s $i -i ./trials/input.txt -o ./trials/out"$i".txt
    fi
  done
done