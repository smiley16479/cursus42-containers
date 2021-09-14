#!/bin/bash

function usage() { echo -n "Usage: option
-f pour : '-Werror -Wall -Wextra -std=c++98 -pedantic'
-s pour : '-fsanitize=address -g3'
-d pour : '"; setterm -underline on; echo -n "define";
              setterm -underline off; 1>&2; echo "'"; exit 1; }

while getopts ":f s d:" option; do
    case "${option}" in
        f)
            f="-Werror -Wall -Wextra -std=c++98 -pedantic"
            ;;
        s)
            s="-fsanitize=address -g3"
            ;;
        d)
            d=-D${OPTARG}
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))
# if [ -z "${d}" ]; then
#     usage
# fi
# echo "tous mes arguements : $@"
# echo "f = ${f}"
# echo "s = ${s}"
# echo "d = ${d}"

g++ ${f} ${s} ${d} main.cpp RBTree.cpp #$@ <- pour spécifier les sources
if [ $? = 0 ]
then
    echo "$1 compilé sous a.out 🔥 nous lançons l'éxécutable : "
    ./a.out
else
    echo la compilation a échouée 🐵
fi
# Résumé de la syntaxe du SYNOPSIS
    # gras : tapez le mot exactement comme indiqué ;
    # souligne : remplacez le mot souligné par la valeur qui convient dans votre cas ;
    # [-hvc] : toutes les options -h, -v et -c sont facultatives ;
    # a|b : vous pouvez écrire l'option « a » OU « b », mais pas les deux à la fois ;
    # option… : les points de suspension indiquent que l'option peut être répétée autant
    # de fois que vous voulez.
