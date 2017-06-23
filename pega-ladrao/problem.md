# Pega Ladrão
__Problem ID__: _ladrao_

![](../images/pega-ladrao.jpg)

`Pega ladrão! Pega ladrão!`

Roubaram a bolinha do Taki que caminhava na Alexandre Dumas e o ladrão, conhecido como Ceviche, fugiu em direção ao rio Pinheiros. Seu plano parece óbvio: ele pretende pegar um barco e escapar! O fugitivo, que a essa altura já está a bordo de sua embarcação de fuga, pretende seguir perpendicularmente à margem em direção ao limite de águas internacionais, que fica a 12 milhas náuticas de distância, onde estará são e salvo das autoridades locais. Seu barco consegue percorrer essa distância a uma velocidade constante de `VC` (Velocidade Ceviche) nós. Ana pretende interceptá-lo, e sua embarcação tem uma velocidade constante de `VA` (Velocidade Ana) nós.

Supondo que ambas as embarcações partam da costa exatamente no mesmo instante, com uma distância de `D` milhas náuticas entre elas, será possível Ana (a autoridade náutica em serviço) alcançar o ladrão antes do limite de águas internacionais? Assuma que a margem do rio Pinheiros é perfeitamente retilínea e o rio bastante calmo, de forma a permitir uma trajetória tão retilínea quanto a margem.

## Entrada
Cada caso de teste é descrito em um linha contendo três inteiros, `D`, `VC` e `VA`, indicando respectivamente a distância inicial entre Ceviche e Ana, a velocidade da embarcação do Ceviche e a velocidade da embarcação da Ana.

## Saída
Para cada caso de teste imprima uma linha contendo `S` se for possível que Ana alcance o fugitivo antes que ele ultrapasse o limite de águas internacionais ou `N` caso contrário.

## Restrições
- `1 ≤ D ≤ 100`
- `1 ≤ VC ≤ 100`
- `1 ≤ VA ≤ 100`

## Exemplos

| Entrada | Saída |
| --- | --- |
| `5 1 12` | `S` |
| `12 10 7` | `N` |
| `12 9 10` | `N` |
| `10 5 5` | `N` |
| `9 12 15` | `S` |
