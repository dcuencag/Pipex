#!/bin/bash

# Preparación
make re
echo -e "hello\nthere\ngeneral\nkenobi" > infile

# Test 1: Comportamiento básico
echo "[TEST 1] cat | wc"
./pipex infile "cat" "wc" outfile
< infile cat | wc > expected.txt
diff outfile expected.txt && echo "✅ OK" || echo "❌ Error"

# Test 2: Comando inexistente
echo "[TEST 2] Comando inexistente"
./pipex infile "noexist" "wc" outfile

# Test 3: Archivo de entrada no existente
echo "[TEST 3] Archivo de entrada no existente"
./pipex nofile "cat" "wc" outfile

# Test 4: Archivo de entrada sin permisos
echo "[TEST 4] Sin permisos de lectura"
chmod 000 infile
./pipex infile "cat" "wc" outfile
chmod 644 infile  # restaurar permisos

# Test 5: Archivo de salida sin permisos
echo "[TEST 5] Sin permisos de escritura"
touch outfile
chmod 000 outfile
./pipex infile "cat" "wc" outfile
chmod 644 outfile  # restaurar permisos

# Test 6: Argumentos incorrectos
echo "[TEST 6] Argumentos incorrectos"
./pipex infile "cat" "wc"

# Test 7: Transformación + conteo de palabras
echo "[TEST 7] tr + wc -w"
./pipex infile "tr a-z A-Z" "wc -w" outfile
< infile tr a-z A-Z | wc -w > expected.txt
diff outfile expected.txt && echo "✅ OK" || echo "❌ Error"

# Bonus 1: Varios pipes (si implementado)
echo "[BONUS 1] Múltiples pipes"
./pipex infile "grep e" "tr a-z A-Z" "sort" "uniq" outfile
< infile grep e | tr a-z A-Z | sort | uniq > expected.txt
diff outfile expected.txt && echo "✅ OK" || echo "❌ Error"

# Bonus 2: here_doc (requiere entrada manual)
echo "[BONUS 2] here_doc"
echo "Escribe 2 líneas y luego END para terminar"
./pipex here_doc END "cat" "wc -l" outfile

# Limpieza
rm -f expected.txt outfile infile
