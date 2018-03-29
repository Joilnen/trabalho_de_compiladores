~ Em jSmall ~

shellSort(mumi vet, numi size)
    numi i, j, value
    numi gap
    gap = 1
    loop gap < size
        gap = 3 * gap + 1
    //
    loop gap > 1
        gap = gap / 3
        i = gap
        loop i < size step 1
            value = vet[i]
            j = i = gap
            loop j >=  and value <= vet[j]
                vet[j + gap] = vet[j]
                j = j - gap
            //
            vet[j + gap] = value
        //
    //
//

boot(shell)
