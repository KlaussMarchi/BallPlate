# PROJETAR CONTROLADOR INTERMEDIÁRIO

$$C(s) = G(s)\cdot C_{aux}(s)\cdot C(s)$$

- O objetivo é projetar o controlador auxiliar que irá fazer com que o sistema seja controlável, ou seja, fazer com que as linhas do root locus permitam com que os polos possam percorrer para o semiplano esquerdo, e portanto estabilizarem o sistema

- O controlador deve posicionar polos e zeros de forma eficaz em um sistema de controle é essencial para melhorar a estabilidade e o desempenho. Aqui estão algumas recomendações gerais para a posição inicial de polos e zeros quando se está projetando controladores:

### Para Controladores PD e PID
- Zeros: Ao introduzir zeros com um controlador PD ou PID, um palpite inicial comum é posicioná-los próximo aos polos instáveis ou de alta frequência do sistema que você deseja cancelar ou atenuar. O zero do controlador PD ou a parte derivativa do PID pode ser posicionado para tentar cancelar o efeito de um polo específico ou para melhorar a resposta transitória, colocando-o à esquerda dos polos dominantes no plano s.
- Polos: Em um controlador PI ou na parte integrativa de um PID, o polo é geralmente colocado na origem (s = 0) para garantir a eliminação do erro em regime permanente. No entanto, isso pode ser ajustado ligeiramente para a esquerda do eixo imaginário para evitar uma resposta muito lenta ou instabilidade devido à ação integral.

### Para Controladores de Avanço de Fase
**Avanço de Fase:** um controlador de avanço de fase é projetado para deslocar o Lugar Geométrico das Raízes (LGR) para a esquerda no plano s, o que melhora a estabilidade do sistema. O controlador de avanço de fase adiciona um zero e um polo ao sistema, sendo que o zero tem um impacto maior na resposta em frequência do que o polo, devido à sua posição mais próxima do eixo imaginário.

- Zeros: Posicione o zero mais próximo do eixo  imaginário do que o polo, mas não tão próximo que induza uma resposta transitória excessivamente rápida ou oscilações.
- Polos: Posicione o polo para que ele tenha menos influência na resposta do sistema do que o zero, tipicamente mais à esquerda no plano s.

### Para Controladores de Atraso de Fase
- Polos: Posicione o polo mais próximo do eixo imaginário do que o zero para reduzir o impacto na largura de banda do sistema.
- Zeros: Posicione o zero de forma que ele tenha menos influência na resposta em frequência, geralmente mais à esquerda no plano s.

### Recomendações Gerais
- Análise de Sensibilidade: Considere a sensibilidade dos polos e zeros. Posições muito próximas ao eixo imaginário podem tornar o sistema excessivamente sensível a variações nos parâmetros do modelo.
- Margens de Estabilidade: Polos e zeros devem ser posicionados de forma a melhorar as margens de ganho e de fase do sistema, proporcionando uma maior robustez.
- Considerações de Desempenho: A localização de polos e zeros deve ser escolhida não apenas para estabilidade, mas também para atender aos requisitos de desempenho, como tempo de acomodação, overshoot e erro em regime estacionário.
- Essas são diretrizes iniciais, e ajustes finos geralmente são necessários após simulações e análises adicionais para otimizar o desempenho e a estabilidade do sistema de controle.



