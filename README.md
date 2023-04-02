#Desafio Origem Firmware

Funcionalidades implementadas:

Moto:

    - Ligar a moto
    - Associar uma bateria (to attach)
    - Liberar uma bateria (to detach)
    - Acionar acelerador
    - Acionar freio / liberar freio
    - Desligar a moto
    - Acesso a todos os atributos (plate, speed, battery)

ETB:

    - Associar uma bateria CP nº x (to attach)
    - Acionar carregamento CP nº x
    - Desligar carregamento CP nº x
    - Liberar bateria CP nº x (to detach)
    - Número de baterias presentes
    - Número de baterias carregando
    - Tempo até final de carregamento bateria CP nº x
    - Acesso a todos atributos (uid, cps)

Bateria:

    - Associar host <moto ou ETB>
    - Desassociar host
    - Acesso a todos atributos (uid, soc, host)

Para compilar, basta fazer o comando "make"

Ambiente de desenvolvimento:

    Linux Ubuntu 20.04
    VSCode
    Versao do g++: 11.3
