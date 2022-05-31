echo "Rodando os testes..."
echo
machine=''
unameOut="$(uname -s)"
case "${unameOut}" in
    CYGWIN*)    machine=-win;;
    MINGW*)     machine=-win;;
esac

#echo ${machine}

for f in $(ls testes/*.in)
do
    echo "---------------------------------------------"
    output="$(./a < $f)"
    expected_output="$(cat $f-out$machine)"
    teste_ok=0
    if [ $? -eq 0 ] ; then
      teste_ok=1
      echo "Teste de execução do programa: O programa executou com retorno CORRETO (zero)."
    else
      echo "Falha ao executar o programa: Houve alguma falha no programa que o retorno esperado (zero) não ocorreu."
      exit 1
    fi
    if [ $teste_ok -eq 1 ]; then 
        echo "Arquivo de teste $f. Entrada Fornecida:"
        echo "$(cat $f)"
        echo "Saída esperada: "
        echo "$expected_output"
        echo "Seu programa gerou a seguinte saída:" 
        echo "$output"

        if [ "$output" = "$expected_output" ] ; then
          echo "Passou: A saída está CORRETA"
        else
          echo "INCORRETO: Não passou. A saída não está conforme esperado"
          exit 1
        fi
    fi  
done
echo "-----------------------------------------------------------"
echo
echo "Passou em TODOS os testes."

exit 0
