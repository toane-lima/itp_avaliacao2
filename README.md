# ITP — Segunda Avaliação: Boletim de uma pequena turma

**Aluno:** Toane Stefhany de Lima Gomes

**Opção escolhida:** Opção 1 — Boletim de uma pequena turma.

## Descrição

Programa em linguagem C que registra de 1 a 10 estudantes, com três notas entre 0 e 10 para cada um. Utiliza uma matriz de notas, uma matriz de caracteres para os nomes e um vetor de médias alocado dinamicamente. Apresenta a média individual, a situação (atingiu a meta quando a média é maior ou igual a 6), a média geral e todos os estudantes empatados na maior média.

## Compilação e execução

No terminal, na pasta do projeto:

```bash
gcc -std=c11 -Wall -Wextra main.c -o programa
./programa
```

## Testes

### Teste 1 — Funcionamento normal

- Quantidade: `2`
- Estudante 1: `Ana`, notas `5`, `6`, `7`
- Estudante 2: `Bruno`, notas `8`, `8`, `8`
- **Esperado:** média de Ana `6.00` (atingiu a meta); média de Bruno `8.00` (atingiu a meta); média geral `7.00`; maior média de Bruno.

### Teste 2 — Entrada inválida e empate

- Informar quantidade `0` e depois `2`.
- Estudante 1: `Ana`, informar nota `11` (inválida) e depois as notas `6`, `6`, `6`.
- Estudante 2: `Bia`, notas `6`, `6`, `6`.
- **Esperado:** o programa rejeita quantidade `0` e nota `11`; média geral `6.00`; Ana e Bia aparecem como empatadas com maior média `6.00`.

## Vídeo de apresentação

[INSIRA AQUI O LINK DO VÍDEO NO YOUTUBE]

## Referências

- Material das aulas 6 a 11 de Introdução às Técnicas de Programação.
- Enunciado da Segunda Avaliação de ITP.
