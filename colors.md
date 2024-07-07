As sequências de escape ANSI são códigos especiais que podem modificar a formatação do texto e outras características do terminal.

### Formatação de Estilo:

`\033[0m` ou `\033[0;0m`: Reseta todos os atributos de formatação (estilo, cor, fundo).
`\033[1m`: Ativa o modo de texto em negrito.
`\033[2m`: Ativa o modo de texto em fraco (dim, menos brilhante).
`\033[3m`: Ativa o modo de texto em itálico (nem sempre suportado).
`\033[4m`: Ativa o modo de texto sublinhado.
`\033[5m`: Ativa o modo de texto piscante (nem sempre suportado).
`\033[7m`: Inverte as cores do texto e do fundo.
`\033[8m`: Esconde o texto (nem sempre suportado).
`\033[9m`: Ativa o modo de texto riscado (nem sempre suportado).

### Cores do Texto:

`\033[30m` a `\033[37m`: Define a cor do texto, onde 30 a 37 são códigos para cores diferentes (preto a branco).
`\033[90m` a `\033[97m`: Define cores de texto brilhante (preto a branco).
`\033[38;5;NUMm`: Define uma cor de texto de 256 cores, onde NUM é o número da cor.
`\033[38;2;R;G;Bm`: Define uma cor de texto RGB, especificando os valores de vermelho (R), verde (G) e azul (B).

### Cores de Fundo:

`\033[40m` a `\033[47m`: Define a cor de fundo, onde 40 a 47 são códigos para cores diferentes (preto a branco).
`\033[100m` a `\033[107m`: Define cores de fundo brilhante (preto a branco).
`\033[48;5;NUMm`: Define uma cor de fundo de 256 cores, onde NUM é o número da cor.
`\033[48;2;R;G;Bm`: Define uma cor de fundo RGB, especificando os valores de vermelho (R), verde (G) e azul (B).

### Controle do Cursor:

`\033[A`: Move o cursor para cima.
`\033[B`: Move o cursor para baixo.
`\033[C`: Move o cursor para a direita.
`\033[D`: Move o cursor para a esquerda.
`\033[E`: Move o cursor para a próxima linha.
`\033[F`: Move o cursor para a linha anterior.
`\033[G`: Move o cursor para uma coluna específica.
`\033[H` ou `\033[;H`: Move o cursor para a posição inicial (1,1).
`\033[2J`: Limpa a tela.
`\033[K`: Limpa a linha atual a partir da posição do cursor.

### Outros:

`\033[s`: Salva a posição do cursor.
`\033[u`: Restaura a posição do cursor salva.