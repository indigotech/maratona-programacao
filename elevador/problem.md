# Elevador Espacial
__Problem ID__: _elevador_

O prédio da Taqtile está construindo um elevador espacial, que permitirá o lançamento de sondas e satélites a um custo muito mais baixo, viabilizando não só projetos de pesquisa científica como o turismo espacial. No entanto, o Emerson é muito supersticioso, e por isso têm um cuidado muito especial com a numeração dos andares do elevador: eles não usam nenhum número que contenha o dígito `4` ou a sequência de dígitos `13`. Assim, ele não usa o andar `4`, nem o andar `13`, nem o andar `134`, nem o andar `113`, mas usa o andar `103`. Assim, os primeiros andares são numerados `1`, `2`, `3`, `5`, `6`, `7`, `8`, `9`, `10`, `11`, `12`, `15`, `16`, `...`. Como o elevador espacial tem muitos andares e ele precisa enumerar todos os andares do elevador, o Emerson pediu que você escrevesse um programa que, dado o andar, indica o número que deve ser atribuído a ele.

## Entrada
Cada caso de teste consiste de uma única linha, contendo um inteiro _N_ que indica o andar cujo número deve ser determinado.

## Saída
Para cada caso de teste, imprima uma linha contendo um único número inteiro indicando o número atribuído ao _N_-ésimo andar.

## Restrições
1 &le; _N_ &le; 10<sup>18</sup>

## Exemplos
| Entrada | Saída |
| --- | --- |
| `1` | `1` |
| `4` | `5` |
| `11` | `12` |
| `12` | `15` |
| `440` | `666` |
